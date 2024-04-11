#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 5;
const ll INF = 1e18;
int deg[MAXN], id[MAXN];
ll dis[1000][1000];
vector<array<int, 3>> edges;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }
    sort(edges.begin(), edges.end());

    for(int i = 0; i < min(m, k); i++) {
        deg[edges[i][1]]++;
        deg[edges[i][2]]++;
    }
    int pt = 0;
    for(int i = 1; i <= n; i++) {
        if(deg[i])
            id[i] = pt++;
    }
    for(int i = 0; i < pt; i++) {
        for(int j = 0; j < pt; j++) {
            dis[i][j] = INF;
        }
        dis[i][i] = 0;
    }
    for(int i = 0; i < min(m, k); i++) {
        int a = id[edges[i][1]], b = id[edges[i][2]];
        dis[a][b] = dis[b][a] = edges[i][0];
    }
    for(int k = 0; k < pt; k++) {
        for(int i = 0; i < pt; i++) {
            for(int j = 0; j < pt; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    vector<ll> em;
    for(int i = 0; i < pt; i++) {
        for(int j = i + 1; j < pt; j++) {
            if(dis[i][j] < INF)
                em.push_back(dis[i][j]);
        }
    }
    sort(em.begin(), em.end());
    cout << em[k - 1] << '\n';
}