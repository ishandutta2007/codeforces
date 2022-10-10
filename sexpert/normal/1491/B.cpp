#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, u, v;
    cin >> n >> u >> v;
    int ans = min(u + v, 2 * v);
    vector<int> vv(n);
    for(auto &x : vv)
        cin >> x;
    for(int i = 0; i + 1 < n; i++) {
        if(abs(vv[i] - vv[i + 1]) >= 2)
            ans = 0;
        if(abs(vv[i] - vv[i + 1]) == 1) {
            ans = min(ans, u);
            ans = min(ans, v);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}