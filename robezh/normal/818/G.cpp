#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
#define Lnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef pair<int, int> P;
struct edge{int to, cap, cost, rev;};
const int N = 6005, INF = (int)1e9;

// Finding Min Cost Max Flow in min(O(F * E * log(V), O(F * V * V));
struct MincostFlow {
    int V; //Please set V!!!!
    vector<edge> G[N];
    int h[N];
    int dist[N];
    int prevv[N], preve[N];
    int vis[N];

    void add_edge(int from, int to, int cap, int cost){
        G[from].push_back((edge){to, cap, cost, (int)G[to].size()});
        G[to].push_back((edge){from, 0, -cost, (int)G[from].size() - 1});
    }

    int min_cost_flow(int s, int t, int f){
        int res = 0;
//        fill(h, h + V, 0);

        while(f > 0) {
//            priority_queue<P, vector<P>, greater<P> > que;
            fill(dist, dist + V, INF);
            dist[s] = 0;
            fill(vis, vis + V, 0);
            for (int it = 0; it < V; it++) {
                int v = -1;
                rep(j, 0, V) {
                    if(!vis[j] && (v == -1 || dist[j] < dist[v])) v = j;
                }
                for(int i = 0; i < G[v].size(); i++){
                    edge &e = G[v][i];
                    if(e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]){
                        dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                        prevv[e.to] = v;
                        preve[e.to] = i;
                    }
                }
                vis[v] = 1;
            }
//            while(!que.empty()){
//                P p = que.top(); que.pop();
//                int v = p.second;
//                if(dist[v] < p.first) continue;
//                for(int i = 0; i < G[v].size(); i++){
//                    edge &e = G[v][i];
//                    if(e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]){
//                        dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
//                        prevv[e.to] = v;
//                        preve[e.to] = i;
//                        que.push(P(dist[e.to], e.to));
//                    }
//                }
//            }
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

int n, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 0, n) cin >> a[i];
    mf.V = 2 * n + 2;
    int s = 2 * n, t = s + 1;
    rep(i, 0, n) {
        mf.add_edge(s, 2 * i, 1, 0);
        mf.add_edge(2 * i, 2 * i + 1, 1, -1);
        mf.add_edge(2 * i + 1, t, 1, 0);
        rep(j, i + 1, n) {
            if(abs(a[i] - a[j]) == 1 || (a[i] - a[j]) % 7 == 0) {
                mf.add_edge(2 * i + 1, 2 * j, 1, 0);
            }
        }
    }
    vi vs = {s};
    rep(i, 0, 2 * n) vs.push_back(i);
    vs.push_back(t);
    for (int idx : vs) {
        for (auto &e : mf.G[idx]) {
            if(e.cap) mf.h[e.to] = min(mf.h[e.to], mf.h[idx] + e.cost);
        }
    }
    cout << -mf.min_cost_flow(s, t, 4) << '\n';


}