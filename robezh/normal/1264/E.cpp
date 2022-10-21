#include <bits/stdc++.h>
using namespace std;

const int N = 55, MAX_V = 2505, INF = (int)1e9;

typedef pair<int, int> P;
struct edge{int to, cap, cost, rev;};

int n, m;
int out[N], deg[N];
int mp[N][N];

// Finding Min Cost Max Flow in min(O(F * E * log(V), O(F * V * V));
struct MincostFlow {
    int V; //Please set V!!!!
    vector<edge> G[MAX_V];
    int h[MAX_V];
    int dist[MAX_V];
    int prevv[MAX_V], preve[MAX_V];

    void add_edge(int from, int to, int cap, int cost){
        G[from].push_back((edge){to, cap, cost, (int)G[to].size()});
        G[to].push_back((edge){from, 0, -cost, (int)G[from].size() - 1});
    }

    int min_cost_flow(int s, int t, int f){
        int res = 0;
        fill(h, h + V, 0);
        while(f > 0){
            priority_queue<P, vector<P>, greater<P> > que;
            fill(dist, dist + V, INF);
            dist[s] = 0;
            que.push(P(0, s));
            while(!que.empty()){
                P p = que.top(); que.pop();
                int v = p.second;
                if(dist[v] < p.first) continue;
                for(int i = 0; i < G[v].size(); i++){
                    edge &e = G[v][i];
                    if(e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]){
                        dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                        prevv[e.to] = v;
                        preve[e.to] = i;
                        que.push(P(dist[e.to], e.to));
                    }
                }
            }
            if(dist[t] == INF) return -1;
            for(int v = 0; v < V; v++) h[v] += dist[v];

            int d = f;
            for(int v = t; v != s; v = prevv[v]){
                d = min(d, G[prevv[v]][preve[v]].cap);
            }
            f -= d;
            res += d * h[t];
            for(int v = t; v != s; v = prevv[v]){
                edge &e = G[prevv[v]][preve[v]];
                e.cap -= d;
                G[v][e.rev].cap += d;
            }
        }
        return res;
    }

} mf;

map<P, int> idxs;


int main() {
    memset(mp, -1, sizeof(mp));
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        out[u]++;
        deg[u]++, deg[v]++;
        mp[u][v] = 1;
        mp[v][u] = 0;
    }
    int s = 2 * n, t = s + 1, cur = t + 1;
    for(int i = 0; i < n; i++) {
        mf.add_edge(s, i, (n - 1) - deg[i], 0);
        for(int j = out[i]; j < out[i] + ((n - 1) - deg[i]); j++) {
            mf.add_edge(i, i + n, 1, j);
        }
        for(int j = 0; j < n; j++) {
            if(j == i || mp[i][j] != -1) continue;
            int u = i, v = j;
            if(u > v) swap(u, v);
            int &id = idxs[{u, v}];
            if(id == 0) {
                id = cur++;
                mf.add_edge(id, t, 1, 0);
            }
            if(mp[i][j] == -1) mf.add_edge(i + n, id, 1, 0);
        }
    }
    mf.V = cur;
    mf.min_cost_flow(s, t, n * (n - 1) / 2 - m);
    for(int i = 2 * n + 2; i < mf.V; i++) {
        int u = -1, fu = 0;
        int v = -1, fv = 0;
        for(auto e : mf.G[i]) {
            if(e.to == t) continue;
            if(u == -1) {
                u = e.to; fu = e.cap;
            } else if(v == -1) {
                v = e.to; fv = e.cap;
            } else {
                assert(false);
            }
        }
        u -= n, v -= n;
//        cout << u << " " << v << endl;
        mp[u][v] = fu;
        mp[v][u] = fv;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i != j) cout << mp[i][j];
            else cout << 0;
        }
        cout << '\n';
    }
}