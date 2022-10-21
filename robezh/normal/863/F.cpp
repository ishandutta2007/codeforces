#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int N = 55, MAX_V = 105, INF = (int)1e9;

typedef pair<int, int> P;
struct edge{int to, cap, cost, rev;};

int n,m,k;
int V; //Please set V!!!!
vector<edge> G[MAX_V];
int h[MAX_V];
int dist[MAX_V];
int prevv[MAX_V], preve[MAX_V];
int ord[N][N], stk[N][N], cst[N][N][N];

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

int q;
int mx[N], mn[N];

int main(){
    cin >> n >> q;
    for(int i = 0; i < n; i++) mx[i] = n - 1, mn[i] = 0;
    while(q--) {
        int tp, l, r, v;
        cin >> tp >> l >> r >> v;
        v--;
        l--, r--;
        for(int j = l; j <= r; j++) {
            if(tp == 1) mn[j] = max(mn[j], v);
            else mx[j] = min(mx[j], v);
        }
    }
    int s = 2 * n, t = 2 * n + 1;
    V = t + 1;
    for(int i = 0; i < n; i++) {
        add_edge(s, i, 1, 0);
        for(int j = 0; j < n; j++) add_edge(i + n, t, 1, 2 * j + 1);
        for(int j = mn[i]; j <= mx[i]; j++) add_edge(i, j + n, 1, 0);
    }
    cout << min_cost_flow(s, t, n) << endl;

}