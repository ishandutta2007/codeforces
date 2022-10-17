#include <bits/stdc++.h>
using namespace std;

char g[8][8];

int main() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> g[i][j];
        }
    }

    int na = 9, nb = 9;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (g[i][j] == 'B') {
                bool passed = true;

                for (int ii = i + 1; ii < 8; ii++)
                    if (g[ii][j] != '.')
                        passed = false;

                if (passed) nb = min(nb, 7 - i);
            } else if(g[i][j] == 'W') {
                bool passed = true;

                for (int ii = 0; ii < i; ii++) 
                    if (g[ii][j] != '.')
                        passed = false;

                if (passed) na = min(na, i);
            }
        }
    }

    if (na <= nb) cout << "A\n";
    else cout << "B\n";
}