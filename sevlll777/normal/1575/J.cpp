#include <bits/stdc++.h>

// #define int long long
#define pb push_back
#define endl '\n'
#define all(x) x.begin(), x.end()

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> A(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }
    while (k--) {
        int c;
        cin >> c;
        c--;
        for (int i = 0; i < n; i++) {
            if (A[i][c] == 1) {
                while (A[i][c] == 1) {
                    A[i][c] = 2;
                    c++;
                }
                if (A[i][c] == 3) {
                    A[i][c] = 2;
                    c--;
                }
            } else if (A[i][c] == 3) {
                while (A[i][c] == 3) {
                    A[i][c] = 2;
                    c--;
                }
                if (A[i][c] == 1) {
                    A[i][c] = 2;
                    c++;
                }
            }
        }
        cout << c + 1 << '\n';
    }

}