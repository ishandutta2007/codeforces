#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (auto &x : s) cin >> x;
    ll ans = 0;
    vector<int> row(n, 0);
    vector<int> col(m, 0);
    int sum = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (s[i][j] == '*') {
                row[i]++;
                col[j]++;
                sum++;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) if (s[i][j] == '*')
            ans += (col[j] - 1) * (row[i] - 1);
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
#ifdef SERT
    freopen("a.in", "r", stdin);
    t = 2;
#endif
    while (t--) {
        solve();
    }
}