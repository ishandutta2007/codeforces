#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<string> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            for(int j = 0; j < m; j++) {
                if((i % 3) == 0)
                    v[i][j] = 'X';
            }
        }

        for(int i = 1; i + 1 < n; i += 3) {
            bool conn = false;
            for(int j = 0; j < m; j++) {
                if(v[i][j] == 'X' || v[i + 1][j] == 'X') {
                    v[i][j] = 'X';
                    v[i + 1][j] = 'X';
                    conn = true;
                    break;
                }
            }
            if(!conn)
                v[i][0] = v[i + 1][0] = 'X';
        }

        if(n % 3 == 0) {
            for(int j = 0; j < m; j++) {
                if(v[n - 2][j] == 'X' || v[n - 1][j] == 'X')
                    v[n - 2][j] = v[n - 1][j] = 'X';
            }
        }

        for(int i = 0; i < n; i++)
            cout << v[i] << '\n';
    }
}