#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

int t, n, x[3], y[3];
char s[100][100];

int main() {
    //freopen("a.in", "r", stdin);
    cin >> t;
    while (t--) {
        n = 0;
        for (int i = 0; i < 8; i++) {
            scanf("%s", s[i]);
            for (int j = 0; j < 8; j++)
                if (s[i][j] == 'K') {
                    x[n] = j;
                    y[n++] = i;
                }
        }

        if (abs(2 - abs(x[1] - x[0])) == 2 && abs(2 - abs(y[1] - y[0])) == 2)
            cout << "YES\n";
        else
            cout << "NO\n";


    }
    return 0;
}