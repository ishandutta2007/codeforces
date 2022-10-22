#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for (int k = 0; k < (n + m - 1) / 2; ++k) {
        int cn = k;
        int cm = 0;
        int tot = 0;
        int sum = 0;
        while (cn >= 0) {
            if (cn < n && cm < m) {
                tot += 2;
                sum += a[cn][cm];
                sum += a[n - cn - 1][m - cm - 1];
            }
            --cn;
            ++cm;
            //cout << cn << " " << cm << " " << tot << " " << sum << endl;
        }
        ans += min(sum, tot - sum);
    }
    cout << ans << endl;
}

int main()
{
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