#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = 1000000009;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    
    for (int i = 1; i < n - 1; ++i) {
        if (a[i][0] > 3) {
            cout << "NO\n";
            return;
        }
        a[i][0] = 3;
        if (a[i][m - 1] > 3) {
            cout << "NO\n";
            return;
        }
        a[i][m - 1] = 3;
    }
    for (int j = 1; j < m - 1; ++j) {
        if (a[0][j] > 3) {
            cout << "NO\n";
            return;
        }
        a[0][j] = 3;
        if (a[n - 1][j] > 3) {
            cout << "NO\n";
            return;
        }
        a[n - 1][j] = 3;
    }
    
    for (int i = 0; i < n; i += n - 1) {
        for (int j = 0; j < m; j += m - 1) {
            if (a[i][j] > 2) {
                cout << "NO\n";
                return;
            }
            a[i][j] = 2;
        }
    }
    
    for (int i = 1; i < n - 1; ++i) {
        for (int j = 1; j < m - 1; ++j) {
            if (a[i][j] > 4) {
                cout << "NO\n";
                return;
            }
            a[i][j] = 4;
        }
    }
    
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin >> t;
    for (int qq = 0; qq < t; ++qq) {
       solve();
    }
   
    return 0;
}