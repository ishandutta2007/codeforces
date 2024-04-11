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

const int N = 20, K = 202, M = N * (1 << (N - 1));

struct P {
    int i, j, cost;
}p[M];

int m;

int n, k;
int a[1 << N];
mt19937 rng(2333);

const int INF = (int)1e9;

struct edge{int to, cap, cost, rev;};

struct MincostFlow {
    typedef pair<int, int> P;
    vector<vector<edge>> G;
    vi h, dist, prevv, preve;

    MincostFlow(int n = 0): G(n), h(n), dist(n), prevv(n), preve(n) {}

    void add_edge(int from, int to, int cap, int cost){
        G[from].push_back((edge){to, cap, cost, (int)G[to].size()});
        G[to].push_back((edge){from, 0, -cost, (int)G[from].size() - 1});
    }

    int min_cost_flow(int s, int t, int f){
        int res = 0;
        // substitute with Bellman-ford/DAG DP for negative edges
        fill(all(h), 0);
        while(f > 0) {
            priority_queue<P, vector<P>, greater<P> > que;
            fill(all(dist), INF);
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
            if(dist[t] == INF) {
                return res;
            }
            for(int v = 0; v < sz(h); v++) h[v] += dist[v];

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
} ;

MincostFlow mcmf((int)20000);

map<int, int> gid;
int tcnt = 2;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    rep(i, 0, 1 << n) {
        cin >> a[i];
    }
    rep(i, 0, 1 << n) {
        if(__builtin_popcount(i) % 2 == 1) continue;
        rep(j, 0, n) p[m++] = {i, i ^ (1 << j), a[i] + a[i ^ (1 << j)]};
    }
    int em = min(1 + (k - 1) * (2 * n - 1), m);
    nth_element(p, p + em, p + m, [](const P &p1, const P &p2) {
        return p1.cost > p2.cost;
    });

    int s = 0, t = 1;
    rep(i, 0, em) {
        if(!gid.count(p[i].i)) {
            mcmf.add_edge(s, tcnt, 1, 0);
            gid[p[i].i] = tcnt++;
        }
        if(!gid.count(p[i].j)) {
            mcmf.add_edge(tcnt, t, 1, 0);
            gid[p[i].j] = tcnt++;
        }
        mcmf.add_edge(gid[p[i].i], gid[p[i].j], 1, -p[i].cost);
    }

    cout << -mcmf.min_cost_flow(s, t, k) << '\n';



}