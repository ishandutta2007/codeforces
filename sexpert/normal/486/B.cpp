#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> A(n, vector<int>(m)), B(n, vector<int>(m, 1)), C(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!A[i][j]) {
                for(int r = 0; r < m; r++)
                    B[i][r] = 0;
                for(int r = 0; r < n; r++)
                    B[r][j] = 0;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int res = 0;
            for(int r = 0; r < m; r++)
                res |= B[i][r];
            for(int r = 0; r < n; r++)
                res |= B[r][j];
            C[i][j] = res;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(A[i][j] != C[i][j]) {
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
    for(int i = 0; i <n ; i++) {
        for(int j = 0; j < m; j++) {
            cout << B[i][j] << " ";
        }
        cout << '\n';
    }
}