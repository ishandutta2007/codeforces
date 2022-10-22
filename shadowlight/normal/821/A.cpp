#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 1) continue;
            bool fl = 0;
            for (int k = 0; k < n; k++) {
                if (k == i) continue;
                for (int l = 0; l < n; l++) {
                    if (l == j) continue;
                    if (a[k][j] + a[i][l] == a[i][j]) {
                        fl = 1;
                        break;
                    }
                }
            }
            if (!fl) {
                cout << "No";
                return 0;
            }
        }
    }
    cout << "Yes";
}