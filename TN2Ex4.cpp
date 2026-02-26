#include <iostream>
#include <iomanip>
#include <cmath>
#include <array>

using namespace std;

// Function for displaying and calculating the exponential table.
void affichage_tableau(array<int, 20> tableau, int nb_elements)
{
    // Display of the table.
    for (int i=0; i < nb_elements; i++)
    {
        // Organization of the table into 4 rows of 5 elements.
        if (i % 5 == 0)
        {
            cout << endl;
        }
        cout << "   " << std::scientific << std::setprecision(5) << exp(tableau[i]);
    }
    cout << endl << endl;

    return;
}

// Function for ascending sort of the table.
array<int, 20> tri_tableau(array<int, 20> tableau, int nb_elements)
{
    int temp;
    for (int i=0; i < nb_elements - 1; i++)
    {
        for(int j=nb_elements - 1 ;j > i; j--)
        {
            if(tableau[j-1] > tableau[j])
            {
                temp = tableau[j-1];
                tableau[j-1] = tableau[j];
                tableau[j] = temp;
            }
        }
    }
    return tableau;
}

int main()
{
    // Declaration of constants and variables.
    const int nb_elements = 20;
    array<int, nb_elements> tableau = {};

    // Generation of the table with more or less random numbers smaller than 100.
    for (int i=0; i < nb_elements; i++)
    {
        tableau[i] = (rand() % 100);
    }

    // Display of the unsorted exponential table.
    cout << "Voici le tableau des exponentiels de 20 valeurs aléatoires non triés :" << endl;
    affichage_tableau(tableau, nb_elements);

    // Ascending sort of the table.
    tableau = tri_tableau(tableau, nb_elements);

    // Display of the exponential table sorted in ascending order.
    cout << "Voici le tableau des exponentiels de 20 valeurs aléatoires triés en ordre ascendant :" << endl;
    affichage_tableau(tableau, nb_elements);

    return 0;
}