#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

#define MAX_ESTADOS 110

// defino cuerpo del algoritmo
int main()
{
    char nombre_estado[65], nombre_municipio[65], confirmacion_municipio;
    float presupuesto_destinado = 0, presupuesto_ejecutado = 0, estado_sobrante = 0, muni_divi = 0, estado_destinado = 0, estado_ejecutado = 0, monto_ano_sobrante = 0, monto_anual = -1;
    int estados = 0, municipios = 0, poblacion_muni = 0, v = 0, z = 0, indice_estado_mayor_monto = -1;

    // Vectores que contienen los datos de presupuesto de cada estado
    float vector_destinados[MAX_ESTADOS];
    float vector_ejecutados[MAX_ESTADOS];
    char nombre_final[MAX_ESTADOS][65];

    printf("Ingrese la cantidad de Estados a calcular: ");
    scanf("%i", &estados);

    for (v = 0; v < estados; v++)
    {

        presupuesto_destinado = 0;
        presupuesto_ejecutado = 0;
        estado_destinado = 0;
        estado_ejecutado = 0;
        estado_sobrante = 0;

        printf("\nEstado N%i\n", v + 1);
        printf("\nIngrese el nombre de estado:");
        scanf("%64s", &nombre_estado);

        strcpy(nombre_final[v], nombre_estado);
        fflush(stdin);
        printf("\nIngrese la cantidad de municipios a calcular: ");
        scanf("%i", &municipios);

        for (z = 0; z < municipios; z++)
        {
            fflush(stdin);
            printf("\nMunicipio N%i\n", z + 1);
            printf("\nIngrese el nombre del municipio: ");
            scanf("%64s", &nombre_municipio);

            fflush(stdin);
            printf("\nColoque habitantes del municipio: ");
            scanf("%i", &poblacion_muni);

            fflush(stdin);
            printf("\nIngrese presupuesto destinado a cada municipio: ");
            scanf("%f", &presupuesto_destinado);

            estado_destinado = estado_destinado + presupuesto_destinado;

            fflush(stdin);
            printf("\nIngrese monto ejecutado por cada municipio: ");
            scanf("%f", &presupuesto_ejecutado);

            estado_ejecutado = estado_ejecutado + presupuesto_ejecutado;

            muni_divi = presupuesto_destinado / poblacion_muni;

            printf("\n");
            fflush(stdin);
            printf("la cantidad que corresponde a cada habitante del municipio %0.2f\n", muni_divi);
        }
        vector_ejecutados[v] = estado_ejecutado;
        vector_destinados[v] = estado_destinado;
        estado_sobrante = estado_destinado - estado_ejecutado;
        printf("El prepusupuesto destinado para el estado es de: %0.2fbs.F\n", estado_destinado);
        printf("El prepusupuesto ejecutado para el estado es de: %0.2fbs.F\n", estado_ejecutado);
        printf("El prepusupuesto sobrante para el estado es de: %0.2fbs.F\n", estado_sobrante);

        if (estado_sobrante == 0)
        {
            monto_ano_sobrante = estado_destinado + (estado_destinado * 0.125);
        }
        else
        {
            if (estado_sobrante >= 350)
            {
                monto_ano_sobrante = estado_destinado - (estado_destinado * 0.05);
            }
            else
            {
                if (estado_sobrante > 100.5 && estado_sobrante < 350)
                {
                    monto_ano_sobrante = estado_destinado + (estado_destinado * 0.07);
                }
                else
                {
                    if (estado_sobrante <= 100)
                    {
                        monto_ano_sobrante = estado_destinado + (estado_destinado * 0.125);
                    }
                }
            }
        }
        printf("El presupuesto asignado para el año siguiente del estado es de: %0.2f\n", monto_ano_sobrante);
    }
    for (v = 0; v < estados - 5; v++)
    {
        if (vector_ejecutados[v] > monto_anual)
        {
            monto_anual = vector_ejecutados[v];
            indice_estado_mayor_monto = v;
        }
    }
    if (indice_estado_mayor_monto != -1)
    {

        printf("El estado que mas dinero ejecuto en el anio es %s, en la posición %i, con un monto de %0.2fbs.F\n", nombre_final[indice_estado_mayor_monto], indice_estado_mayor_monto, monto_anual);
    }
    else
    {
        printf("No se pudo determinar el estado con el mayor presupuesto ejecutado.\n");
    }

    return 0;
}