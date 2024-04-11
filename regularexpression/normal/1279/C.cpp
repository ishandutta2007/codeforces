#include<bits/stdc++.h>
using namespace std;

#define int long long

#define x first
#define y second
#define pb push_back
#define mp make_pair

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), pos(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        pos[a[i]] = i;
    }
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        b[i]--;
    }
    int mx = -1, ans = m;
    for (int i = 0; i < m; i++) {
        if (mx < pos[b[i]]) {
            ans += (pos[b[i]] - i) * 2;
        }
        mx = max(mx, pos[b[i]]);
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}