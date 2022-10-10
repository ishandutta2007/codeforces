#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for(auto &x : v)
        cin >> x;
    vector<vector<char>> gri(n, vector<char>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            gri[i][j] = "RW"[(i + j) & 1];
        }
    }
    for(int it = 0; it < 2; it++) {
        bool good = true;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(v[i][j] != '.' && v[i][j] != gri[i][j])
                    good = false;
            }
        }
        if(good) {
            cout << "YES\n";
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    cout << gri[i][j];
                }
                cout << '\n';
            }
            return;
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                gri[i][j] = "WR"[(i + j) & 1];
            }
        }
    }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}