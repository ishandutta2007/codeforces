/*
 * Codeforces 1300A
 * Link: https://codeforces.com/contest/1300/problem/A
 * Sugerido por: Ari
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n_tests;
    cin >> n_tests; // Leemos el nmero de casos.
    for(int test = 0; test < n_tests; test++) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int steps = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] == 0) {
                a[i]++; // Sumamos 1 a todos los ceros que hay inicialmente.
                steps++;
            }
        }

        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += a[i];
        }
        if(sum == 0) {
            steps++; // Sumamos 1 a cualquier elemento si la suma an es 0.
        }

        cout << steps << '\n';
    }
}

/*
Explicacin:
    Para forzar que el producto sea distinto de cero, basta con que no haya ningn cero. Esto
    lo logramos sumndole 1 a todos los elementos que inicialmente son cero. Finalmente, si la
    suma despus de estas operaciones es cero, hay que aplicarle una operacin a cualquier
    nmero para cambiar eso.
*/