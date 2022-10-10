#include <bits/stdc++.h>
using namespace std;

int mat[105][105];

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cin >> mat[i][j];
    }
    while(true) {
        if(n % 2) {
            cout << n << endl;
            return 0;
        }
        for(int j = 0; j < m; j++) {
            for(int i = 0; i < n; i++) {
                if(mat[i][j] != mat[n - 1 - i][j]) {
                    cout << n << endl;
                    return 0;
                }
            }
        }
        n /= 2;
    }
}