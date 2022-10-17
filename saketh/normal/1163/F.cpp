#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

// builds SPT and returns distances, parents
tuple<vll, vi> spt(int N, vvi& adj, auto& edges, int root) {
    vll dists(N, LLONG_MAX / 4); vi pred(N, -1);

    priority_queue<pair<ll, int>> pq;
    pq.push({ 0, root });
    dists[root] = 0;

    while (!pq.empty()) {
        auto [dist, loc] = pq.top(); pq.pop();
        if ((dist *= -1) != dists[loc]) continue;

        for (int e : adj[loc]) {
            auto [u, v, w] = edges[e];
            if (int nbr = u + v - loc; dist + w < dists[nbr]) {
                dists[nbr] = dist + w;
                pred[nbr] = e;
                pq.push({ -dists[nbr], nbr });
            }
        }
    }

    return { dists, pred };
}

vi rely(int N, vvi& adj, auto& edges, auto& pelts, vll& dists, int root) {
    vi need(N, INT_MAX);

    priority_queue<pair<int, int>> pq;
    pq.push({ 0, root });
    need[root] = 0;

    while (!pq.empty()) {
        auto [used, loc] = pq.top(); pq.pop();
        if ((used *= -1) != need[loc]) continue;

        for (int e : adj[loc]) {
            auto [u, v, w] = edges[e];
            if (int nbr = u + v - loc; dists[loc] + w == dists[nbr]) {
                int would = max(need[loc], pelts[e] + 1);
                if (would < need[nbr]) {
                    need[nbr] = would;
                    pq.push({ -need[nbr], nbr });
                }
            }
        }
    }

    return need;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, Q;
    cin >> N >> M >> Q;

    vvi adj(N);
    vector<tuple<int, int, int>> edges(M);
    for (int e = 0, u, v, w; e < M; e++) {
        cin >> u >> v >> w;
        adj[--u].push_back(e);
        adj[--v].push_back(e);
        edges[e] = { u, v, w };
    }

    auto [distsA, predA] = spt(N, adj, edges, 0);
    auto [distsB, predB] = spt(N, adj, edges, N - 1);

    vi spath;
    for (int loc = N - 1, e; loc != 0; ) {
        spath.push_back(e = predA[loc]);
        loc = get<0>(edges[e]) + get<1>(edges[e]) - loc;
    }
    vi peltsA(M, -1), peltsB(M, -1);
    for (int i = 0; i < sz(spath); i++) {
        peltsB[spath[i]] = i;
        peltsA[spath[i]] = sz(spath) - i - 1;
    }

    vi relyA = rely(N, adj, edges, peltsA, distsA, 0);
    vi relyB = rely(N, adj, edges, peltsB, distsB, N - 1);

    vector<vector<pair<ll, int>>> cand(sz(spath) + 1);
    for (int e = 0; e < M; e++) if (peltsA[e] == -1) {
        auto [u, v, w] = edges[e];
        if (relyA[u] != INT_MAX && relyB[u] != INT_MAX)
            cand[relyA[u]].emplace_back(-(distsA[u] + w + distsB[v]), relyB[v]);
        if (relyA[v] != INT_MAX && relyB[v] != INT_MAX)
            cand[relyA[v]].emplace_back(-(distsA[v] + w + distsB[u]), relyB[u]);
    }

    vll avoid(sz(spath), LLONG_MAX / 4);
    priority_queue<pair<ll, int>> options;
    for (int i = 0; i < sz(spath); i++) {
        for (auto elt : cand[i]) options.push(elt);
        while (!options.empty() && i + options.top().second >= sz(spath))
            options.pop();
        if (!options.empty()) avoid[i] = -options.top().first;
    }

    for (int q = 0, t, x; q < Q; q++) {
        cin >> t >> x;
        auto [mu, mv, mw] = edges[--t];
        if (peltsA[t] == -1) {
            cout << min({ distsA[N - 1], distsA[mu] + x + distsB[mv], distsA[mv] + x + distsB[mu] }) << "\n";
        } else {
            cout << min(avoid[peltsA[t]], distsA[N - 1] + x - mw) << "\n";
        }
    }

    return 0;
}