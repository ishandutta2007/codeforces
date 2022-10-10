#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 10;
int a[MAXN], mil[MAXN];
map<pair<int, int>, int> upg;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll ans = 0;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        ans += a[i];
    }
    int q;
    cin >> q;
    while(q--) {
        int s, t, u;
        cin >> s >> t >> u;
        if(upg[{s, t}] > 0) {
            int x = upg[{s, t}];
            ans += min(mil[x], a[x]);
            mil[x]--;
            ans -= min(mil[x], a[x]);
        }
        upg[{s, t}] = u;
        if(u == 0) {
            cout << ans << '\n';
            continue;
        }
        ans += min(mil[u], a[u]);
        mil[u]++;
        ans -= min(mil[u], a[u]);
        cout << ans << '\n';
    }
}