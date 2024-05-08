#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Función para generar un número aleatorio par entre un rango dado
int numero(int min, int max) {
    int num;
    do {
        num = rand() % (max - min + 1) + min;
 // Genera un número entre min y max, incluyendo ambos extremos
    } while (num % 2 != 0);
 // Repite el proceso hasta que se genere un número par
    return num;
}

int main() {
    int lim_inf, lim_sup, suma = 0;

    // Solicitar al usuario los límites inferior y superior
    printf("Ingrese el limite inferior: ");
    scanf("%d", &lim_inf);
    printf("Ingrese el limite superior: ");
    scanf("%d", &lim_sup);

    // Semilla para la generación de números aleatorios
    unsigned int semilla;
    printf("Ingrese una semilla o 0 para generarla pseudoaleatoriamente: ");
    scanf("%u", &semilla);

    if (semilla == 0) {
        semilla = time(NULL);
 // Genera una semilla basada en el tiempo actual
    }

    srand(semilla);
 // Inicializa la semilla para la generación de números aleatorios

    // Sumar 1000 valores aleatorios pares
    for (int i = 0; i < 1000; i++) {
        int num = numero(lim_inf, lim_sup);
        suma += num;
    }

    // Imprimir la suma
    printf("La suma de los 1000 valores aleatorios pares es: %d\n", suma);

    return 0;
}

