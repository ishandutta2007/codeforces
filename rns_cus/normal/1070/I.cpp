#include<bits/stdc++.h>
using namespace std;

class dinic_flow {
  public:
    struct edge {
        int to, rev, cap;
        edge(int to = 0, int rev = 0, int cap = 0) : to(to), rev(rev), cap(cap) {}
    };
    vector < vector <edge> > g;
    vector < vector <edge> :: iterator > nowi;
    vector < int > dist;
    int nodes, src, dst;
    queue <int> q;
    void init(int _nodes) {
        nodes = _nodes;
        g.resize(_nodes);
        nowi.resize(_nodes);
        for(int i = 0; i < _nodes; i ++) g[i].clear();
        dist.resize(_nodes);
    }
    void add_Edge(int _from, int _to, int _cap) {
        g[_from].push_back(edge(_to, g[_to].size(), _cap));
        g[_to].push_back(edge(_from, g[_from].size() - 1, 0));
    }
    bool dinic_bfs() {
        fill(dist.begin(), dist.end(), -1);
        dist[src] = 0;
        q.push(src);
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(int i = 0; i < g[u].size(); i ++) {
                edge e = g[u][i];
                if(e.cap) {
                    int v = e.to;
                    if(dist[v] < 0) dist[v] = dist[u] + 1, q.push(v);
                }
            }
        }
        return dist[dst] >= 0;
    }
    int dinic_dfs(int u, int f) {
        if(u == dst) return f;
        int ret = 0;
        for(vector<edge>::iterator &it = nowi[u]; it != g[u].end(); it ++) if(it->cap) {
                int v = it->to;
                if(dist[v] == dist[u] + 1) {
                    int tmp = dinic_dfs(v, min(f, it->cap));
                    it->cap -= tmp, f -= tmp, ret += tmp, g[v][it->rev].cap += tmp;
                    if(!f) return ret;
                }
            }
        return ret;
    }
    int maxFlow(int _src, int _dst) {
        src = _src, dst = _dst;
        int flow = 0;
        while(dinic_bfs()) {
            for(int i = 0; i < nodes; i ++) nowi[i] = g[i].begin();
            flow += dinic_dfs(_src, 1e9);
        }
        return flow;
    }
} D;

#define N 666

int d[N], c[N];
vector <int> v[N];

int main() {
    int t, n, m, k;
    scanf("%d", &t);
    while(t --) {
        scanf("%d%d%d", &n, &m, &k);
        memset(d, 0, sizeof d);
        D.init(n + m + 10);
        int S = 0, T = n + m + 1;
        for(int i = 1, x, y; i <= m; i ++) {
            scanf("%d%d", &x, &y);
            d[x] ++;
            d[y] ++;
            D.add_Edge(x, n + i, 1);
            D.add_Edge(y, n + i, 1);
            D.add_Edge(n + i, T, 1);
        }
        int tot = 0;
        for(int i = 1; i <= n; i ++) {
            int flw = 2 * max(0, d[i] - k);
            tot += flw;
            D.add_Edge(S, i, flw);
        }
        int mxflw = D.maxFlow(S, T);
        if(mxflw != tot) {
            for(int i = 1; i <= m; i ++) printf("%d ", 0);
            puts("");
            continue;
        }
        for(int i = 1; i <= n; i ++) v[i].clear();
        for(int i = 1; i <= n; i ++) {
            for(int j = 0; j < D.g[i].size(); j ++) {
                int e = D.g[i][j].to, c = D.g[i][j].cap;
                if(e != S && c == 0) v[i].push_back(e - n);
            }
        }
        int cnt = 0;
        memset(c, 0, sizeof c);
        for(int i = 1; i <= n; i ++) {
            for(int j = 0; j < v[i].size(); j += 2) {
                ++ cnt;
                c[v[i][j]] = cnt;
                c[v[i][j+1]] = cnt;
            }
        }
        for(int i = 1; i <= m; i ++) {
            if(!c[i]) printf("%d ", ++ cnt);
            else printf("%d ", c[i]);
        }
        puts("");
    }
}