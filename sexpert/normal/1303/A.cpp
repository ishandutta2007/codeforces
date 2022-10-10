#include <bits/stdc++.h>
using namespace std;

void solve_one() {
    string s;
    cin >> s;

    int n = s.size();
    
    int izq = -1, der = -1; // Posiciones del primer y ltimo 1.

    for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
            izq = i; // Llegamos al primer 1 desde la izquierda, entonces salimos.
            break;
        }
    }

    for(int i = n - 1; i >= 0; i--) {
        if(s[i] == '1') {
            der = i; // Llegamos al primer 1 desde la derecha, entonces salimos.
            break;
        }
    }

    if(izq == -1) {
        // No hay ningn 1 en la cadena.
        cout << "0\n";
        return;
    }

    int res = 0;
    for(int i = izq; i <= der; i++) {
        // Iteramos entre los 1s que encontramos.
        if(s[i] == '0') {
            res++;
        }
    }

    cout << res << '\n';
    return;
}

int main() {
    int n_tests;
    cin >> n_tests;
    for(int test = 0; test < n_tests; test++) {
        solve_one(); // Truquito de implementacin: Creamos una funcin que resuelve
                     // un solo caso y la llamamos varias veces.
    }
}

/*
Explicacin:
    Como no podemos modificar a los 1s, tenemos que borrar a todos los ceros que estn
    entre dos 1s. Entonces, podemos ignorar todos los ceros que aparecen antes del primer 1
    o despus del ltimo 1, y borrar los dems ceros. Hay un caso especial: si no hay ningn
    1 la respuesta es 0.
*/