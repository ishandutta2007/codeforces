#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;

    vi a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    vvi adj(N);
    for (int e = 0; e < N - 1; e++) {
        int u, v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    vll sum(N), meet(N);
    function<void(int, int)> dfs = [&](int loc, int par) {
        sum[loc] = a[loc];
        for (int nbr : adj[loc]) if (nbr != par) {
            dfs(nbr, loc);
            sum[loc] += sum[nbr];
            meet[loc] += meet[nbr] + sum[nbr];
        }
    };
    dfs(0, 0);

    function<void(int, int)> dfs2 = [&](int loc, int par) {
        if (loc != par) {
            meet[loc] = meet[par] - sum[loc] + sum[0] - sum[loc];
        }
        for (int nbr : adj[loc]) if (nbr != par) {
            dfs2(nbr, loc);
        }
    };
    dfs2(0, 0);

    ll ans = 0;
    for (ll v : meet)
        ans = max(ans, v);
    cout << ans << endl;

    return 0;
}