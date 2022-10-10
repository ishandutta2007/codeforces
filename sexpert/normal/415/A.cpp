#include <bits/stdc++.h>
using namespace std;

int X[105];

int main() {
    memset(X, -1, sizeof X);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int b;
        cin >> b;
        for(int k = b; k <= n; k++) {
            if(X[k] == -1)
                X[k] = b;
        }
    }
    for(int i = 1; i <= n; i++)
        cout << X[i] << " ";
    cout << endl;
}