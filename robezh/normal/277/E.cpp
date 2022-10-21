#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <iomanip>

using namespace std;

const int N = 405, MAX_V = 805, INF = (int)1e9;

typedef pair<double, int> P;
struct edge{
    int to, cap;
    double cost;
    int rev;};

struct MincostFlow {
    int V; //Please set V!!!!
    vector<edge> G[MAX_V];
    double h[MAX_V];
    double dist[MAX_V];
    int prevv[MAX_V], preve[MAX_V];

    void add_edge(int from, int to, int cap, double cost){
        G[from].push_back((edge){to, cap, cost, (int)G[to].size()});
        G[to].push_back((edge){from, 0, -cost, (int)G[from].size() - 1});
    }

    double min_cost_flow(int s, int t, int f){
        double res = 0;
        fill(h, h + V, 0);
        while(f > 0){
            priority_queue<P, vector<P>, greater<> > que;
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

int n;
int x[N], y[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    int mx = -1;
    int s = 2 * n, t = s + 1;
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        if(mx == -1 || y[mx] < y[i]) mx = i;
    }
    for(int i = 0; i < n; i++) {
        mf.add_edge(s, i, 2, 0);
        for(int j = 0; j < n; j++) {
            if(y[i] > y[j]) mf.add_edge(i, j + n, 1, hypot(x[i] - x[j], y[i] - y[j]));
        }
        if(i != mx) mf.add_edge(i + n, t, 1, 0);
    }
    mf.V = t + 1;
    double cost = mf.min_cost_flow(s, t, n - 1);
    if(cost == -1) cout << -1 << endl;
    else cout << fixed << setprecision(10) << cost << endl;
}