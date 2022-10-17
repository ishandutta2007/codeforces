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

pair<ll, ll> calc(auto& adj, vi& w, int loc, int par) {
    ll ans = w[loc];
    vll cres;

    for (auto e : adj[loc]) {
        if (e.first == par) continue;
        auto ch = calc(adj, w, e.first, loc);
        ans = max(ans, ch.second);
        cres.push_back(ch.first - e.second);
    }

    sort(all(cres), greater<ll>());

    ll bup = w[loc];
    if (cres.size() > 0 && cres[0] > 0) bup += cres[0];

    ll bpath = w[loc];
    if (cres.size() > 0 && cres[0] > 0) bpath += cres[0];
    if (cres.size() > 1 && cres[1] > 0) bpath += cres[1];

    return { bup, max(bpath, ans) };
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;

    vi w(N);
    for (int i = 0; i < N; i++)
        cin >> w[i];

    vector<vector<pair<int, int>>> adj(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u-1].emplace_back(v-1, c);
        adj[v-1].emplace_back(u-1, c);
    }

    cout << calc(adj, w, 0, 0).second << "\n";
    return 0;
}