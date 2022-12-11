//made by Sert
#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9 + 34;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> s(m), d(m), c(m);
    vector<int> ans(n, 0);
    vector<bool> u(n);

    for (int i = 0; i < m; i++) {
        cin >> s[i] >> d[i] >> c[i];
        s[i]--;
        d[i]--;
        u[d[i]] = true;
    }
    for (int i = 0; i < n; i++) {
        int mn = n;
        int pos = -1;
        bool isD = false;
        for (int j = 0; j < m; j++) {
            if (d[j] == i) isD = true;
            if (s[j] > i || c[j] == 0) continue;
            int cur = -c[j];
            for (int k = i; k < d[j]; k++) {
                if (!u[k]) cur++;
            }
            if (cur < mn) {
                mn = cur;
                pos = j;
            }
        }
        if (mn < 0) {
            cout << "-1\n";
            return;
        }
        if (isD) {
            ans[i] = m + 1;
        } else {
            if (pos != -1) c[pos]--;
            ans[i] = pos + 1;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

int main() {
#ifdef SERT
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    solve();
    solve();
#endif
    solve();
    return 0;
}