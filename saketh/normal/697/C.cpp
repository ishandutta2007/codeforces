#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int depth(ll node) {
    return 63 - __builtin_clzll(node);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int Q;
    cin >> Q;

    map<ll, ll> toll;

    for (int q = 0; q < Q; q++) {
        int type;
        cin >> type;

        if (type == 1) {
            ll v, u, w;
            cin >> v >> u >> w;

            if (depth(v) < depth(u))
                swap(v, u);

            while (depth(v) > depth(u)) {
                toll[v] += w;
                v /= 2;
            }

            while (v != u) {
                toll[v] += w;
                toll[u] += w;
                v /= 2;
                u /= 2;
            }
        } else {
            ll v, u;
            cin >> v >> u;

            if (depth(v) < depth(u))
                swap(v, u);

            ll ans = 0;

            while (depth(v) > depth(u)) {
                ans += toll[v];
                v /= 2;
            }

            while (v != u) {
                ans += toll[v];
                ans += toll[u];
                v /= 2;
                u /= 2;
            }

            cout << ans << "\n";
        }
    }

    return 0;
}