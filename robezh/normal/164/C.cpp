#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int N = 1005, MAX_V = 2055, INF = (int)1e9;

typedef pair<int, int> P;
struct edge{int to, cap, cost, rev;};

int in[MAX_V];

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
        int rd = 0;
        while(f > 0){
            queue<int> que;
            fill(dist, dist + V, INF);
            dist[s] = 0;
            in[s] = true;
            que.push(s);
            while(!que.empty()){
                int v = que.front(); que.pop();
                in[v] = 0;
                for(int i = 0; i < G[v].size(); i++){
                    edge &e = G[v][i];
                    if(e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]){
                        dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                        prevv[e.to] = v;
                        preve[e.to] = i;
                        if(!in[e.to]) {
                            que.push(e.to);
                            in[e.to] = 1;
                        }
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

struct work {
    int s, t, c, i;
    void read(int _i) {
        cin >> s >> t >> c;
        i = _i;
    }
};

int n, k;
work wk[N];
int ss[N];
int res[N];

int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        wk[i].read(i);
    }
    sort(wk, wk + n, [](const work &w1, const work &w2) {
        return w1.s < w2.s;
    });
    for(int i = 0; i < n; i++) ss[i] = wk[i].s;

    int s = n, t = n + 1;
    mf.V = t + 1;

    mf.add_edge(s, 0, k, 0);
    for(int i = 0; i < n - 1; i++) mf.add_edge(i, i + 1, INF, 0);
    mf.add_edge(n - 1, t, INF, 0);
    for(int i = 0; i < n; i++) {
        int nxt = (int)(lower_bound(ss, ss + n, wk[i].s + wk[i].t) - ss);
        if(nxt == n) nxt = t;
        mf.add_edge(i, nxt, 1, -wk[i].c);
    }
    mf.min_cost_flow(s, t, k);
    for(int i = 0; i < n; i++) {
//        int nxt = (int)(lower_bound(ss, ss + n, wk[i].s + wk[i].t) - ss);
//        if(nxt == n) nxt++;
        for(auto e : mf.G[i]) {
            if(e.cost == -wk[i].c && e.cap == 0) {
                res[wk[i].i] = 1;
            }
        }
    }
    for(int i = 0; i < n; i++) cout << res[i] << " ";

}