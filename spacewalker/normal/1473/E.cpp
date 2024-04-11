#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr ll INF = 1000000000000000000;

int main() {
    int n, m; scanf("%d %d", &n, &m);
    // (v, has doubled, has eaten)
    vector<vector<pair<int, ll>>> graph(4 * n);
    auto addEdge = [&] (int u, int v, ll w) {
        for (int stbits = 0; stbits < 4; ++stbits) {
            for (int edbits = 0; edbits < 4; ++edbits) {
                if (stbits & ~edbits) continue;
                ll finalw = ((stbits ^ edbits) == 1 ? 2 * w : (stbits == edbits ? w : 0));
                if (stbits == 0 && edbits == 3) finalw = w;
//                printf("(%d %d)->(%d %d) %lld\n", u, stbits, v, edbits, finalw);
                graph[stbits * n + u].emplace_back(edbits * n + v, finalw);
            }
        }
    };
    for (int i = 0; i < m; ++i) {
        int u, v; ll w; scanf("%d %d %lld", &u, &v, &w); --u; --v;
        addEdge(u, v, w);
        addEdge(v, u, w);
    }
    // core: dijkstra
    // get distances from 0 to 3n + ...
    vector<ll> dist(4 * n, INF);
    dist[0] = 0;
    priority_queue<pair<ll, int>> pq; // NEGATE WEIGHTS
    pq.emplace(0, 0);
    while (!pq.empty()) {
        auto [wto, cur] = pq.top(); pq.pop();
        wto *= -1;
        if (dist[cur] < wto) continue;
        for (auto [nxt, wt] : graph[cur]) {
            if (wto + wt < dist[nxt]) {
                pq.emplace(-wto - wt, nxt);
                dist[nxt] = wto + wt;
            }
        }
    }
    for (int i = 1; i < n; ++i) printf("%lld ", dist[3 * n + i]);
    printf("\n");
    return 0;
}