#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

vll dij(auto &g, int src) {
    vll res(g.size(), LLONG_MAX);
    res[src] = 0;
    priority_queue<pair<ll, int>> pq;
    pq.push(make_pair(0ll, src));
    while (!pq.empty()) {
        ll dist = pq.top().first;
        int loc = pq.top().second;
        pq.pop();
        for (auto e : g[loc]) {
            ll cand = -dist + e[1];
            if (cand < res[e[0]]) {
                res[e[0]] = cand;
                pq.push(make_pair(-cand, e[0]));
            }
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, M;
    cin >> N >> M;

    vector<vector<array<int, 2>>> g(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u-1].push_back({ v-1, w });
        g[v-1].push_back({ u-1, w });
    }

    vll x = dij(g, 0), y = dij(g, N-1);

    vi ord(N);
    for (int i = 0; i < N; i++)
        ord[i] = i;
    sort(all(ord), [&](int i, int j) {
        return (x[i] - y[i]) < (x[j] - y[j]);
    });
    vi loc(N);
    for (int i = 0; i < N; i++)
        loc[ord[i]] = i;

    ll ans = 0;
    set<pair<ll, int>> cand;
    for (int b : ord) {
        for (auto e : g[b])
            if (loc[e[0]] < loc[b])
                cand.erase({ x[e[0]], e[0] });
        if (cand.size())
            ans = max(ans, y[b] + cand.rbegin()->first);
        for (auto e : g[b])
            if (loc[e[0]] < loc[b])
                cand.insert(make_pair(x[e[0]], e[0]));
        cand.insert({ x[b], b });
    }

    for (int i = 0; i < M; i++) {
        int q;
        cin >> q;
        cout << min(y[0], ans + q) << "\n";
    }

    return 0;
}