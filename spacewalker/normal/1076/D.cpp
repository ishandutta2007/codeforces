#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr ll INF = 1e18;

int main() {
    int n, m, k; scanf("%d %d %d", &n, &m, &k);
    vector<vector<pair<int, int>>> graph(n);
    vector<pair<int, int>> elist(m);
    vector<ll> eWeight(m);
    for (int i = 0; i < m; ++i) {
        int x, y, w; scanf("%d %d %d", &x, &y, &w); --x; --y;
        graph[x].emplace_back(y, i);
        graph[y].emplace_back(x, i);
        elist[i] = {x, y};
        eWeight[i] = w;
    }
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    vector<ll> cdist(n, INF);
    vector<int> eToPar(n, -1);
    cdist[0] = 0;
    pq.emplace(0, 0);
    while (!pq.empty()) {
        auto [dtc, cur] = pq.top(); pq.pop();
        if (dtc > cdist[cur]) continue;
        for (auto [nxt, etn] : graph[cur]) {
            if (cdist[nxt] > eWeight[etn] + dtc) {
                eToPar[nxt] = etn;
                pq.emplace(cdist[nxt] = eWeight[etn] + dtc, nxt);
            }
        }
    }
    vector<int> treeOrder;
    for (int i = 0; i < n; ++i) if (cdist[i] < INF) treeOrder.push_back(i);
    sort(begin(treeOrder), end(treeOrder), [&] (int i, int j) {return cdist[i] < cdist[j];});
    vector<int> toKeep;
    for (int v : treeOrder) if (eToPar[v] != -1) toKeep.push_back(eToPar[v]);;
    while (toKeep.size() > k) toKeep.pop_back();
    printf("%lu\n", toKeep.size());
    for (int v : toKeep) printf("%d ", v + 1);
    printf("\n");

}