//made by Sert
#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9 + 34;
const int N = (int)1e6 + 34;

typedef long long ll;

void solve() {
    map<int, int> mp;

    for (int iq = 0; iq < 2; iq++) {
        int n, a, p;
        scanf("%d", &n);
        while (n--) {
            scanf("%d%d", &a, &p);
            int x = (mp.find(a) == mp.end() ? p : mp[a]);
            mp[a] = max(x, p);
        }
    }

    ll ans = 0;
    for (auto it: mp) {
        ans += it.second;
    }
    cout << ans << "\n";
}

int main() {
#ifdef MADE_BY_SERT
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    solve();
    //solve();
#endif
    solve();
    return 0;
}