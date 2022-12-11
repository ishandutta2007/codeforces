#include <bits/stdc++.h>
using namespace std;
void init() {
#if __GNUG__ == 4 && __GNUC_MINOR__ == 9 ///my GNU version is 4.9.3
    freopen("a.in", "r", stdin);
    ///freopen("a.out", "w", stdout);
#endif
}
typedef long long ll;
typedef long double ld;

const ll N = 1e6 + 34;
const ll INF = 1e9 + 34;

ll lca(ll a, ll b) {
    if (a == b) return a;
    if (a > b) return lca(a / 2, b);
    return lca(a, b / 2);
}

map <ll, ll> sum;

ll wtr(ll v) {
    return (v == 1 ? 0 : sum[v] + wtr(v / 2));
}

void add(ll v, ll w) {
    if (v == 1) return;
    sum[v] += w;
    add(v / 2, w);
}

int main() {
    init();

    ll q, v, u, w, t, l;
    cin >> q;
    while (q--) {
        cin >> t >> v >> u;
        l = lca(v, u);
        if (t == 1) {
            cin >> w;
            add(v, w);
            add(u, w);
            add(l, -w * 2);
        } else {
            cout << wtr(u) + wtr(v) - wtr(l) * 2 << "\n";
        }
    }

    return 0;
}