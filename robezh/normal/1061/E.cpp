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
const int N = 505;

const int INF = (int)1e9;

typedef pair<int, int> P;
struct edge{int to, cap, cost, rev;};
// Finding Min Cost Max Flow in min(O(F * E * log(V), O(F * V * V));
struct MincostFlow {
    vector<vector<edge>> G;
    vi h, dist, prevv, preve;

    MincostFlow(int n = 0): G(n), h(n), dist(n), prevv(n), preve(n) {}

    void add_edge(int from, int to, int cap, int cost){
//        cout << "from " << from << " to " << to << " with cap = " << cap << ", cost = " << cost << endl;
        G[from].push_back((edge){to, cap, cost, (int)G[to].size()});
        G[to].push_back((edge){from, 0, -cost, (int)G[from].size() - 1});
    }

    int min_cost_flow(int s, int t, int f){
        int res = 0;
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
                return 1;
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

} mf;

int n, x, y;
int a[N];
vector<vi> G, H;
int idL[N], idR[N];
int sl[N], sr[N];
int cnt = 0;
int s, t;
int dem;

void dfs(int v, int p, int pid, int rev, vector<vi> &g, int *id, int *sub) {
    id[v] = cnt++;

    int e = pid, f = id[v];
    if(rev) swap(e, f);
    if(pid == s || pid == t) {
        mf.add_edge(e, f, sub[v], 0);
    } else if(sub[v] != -1) {
        mf.add_edge(s, f, sub[v], 0);
        mf.add_edge(e, t, sub[v], 0);
        dem += sub[v];
    } else {
        mf.add_edge(e, f, INF, 0);
    }

    for (int nxt : g[v]) {
        if(nxt != p) {
            dfs(nxt, v, id[v], rev, g, id, sub);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> x >> y; x--, y--;
    rep(i, 0, n) cin >> a[i];
    G.resize(n);
    H.resize(n);
    rep(i, 0, n - 1) {
        int u, v; cin >> u >> v; u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    rep(i, 0, n - 1) {
        int u, v; cin >> u >> v; u--, v--;
        H[u].push_back(v);
        H[v].push_back(u);
    }
    int q;
    fill(sl, sl + n, -1);
    cin >> q;
    rep(i, 0, q) {
        int k, v; cin >> k >> v; k--;
        sl[k] = v;
    }
    fill(sr, sr + n, -1);
    cin >> q;
    rep(i, 0, q) {
        int k, v; cin >> k >> v; k--;
        sr[k] = v;
    }

    if(sl[x] != sr[y]) {
        cout << -1 << endl;
        return 0;
    }
    dem += sl[x];

    mf = MincostFlow(2 * n + 4);
    s = cnt++, t = cnt++;
//    int ns = cnt++, nt = cnt++;
    dfs(x, -1, s, 0, G, idL, sl);
    dfs(y, -1, t, 1, H, idR, sr);
    rep(i, 0, n) {
        mf.add_edge(idL[i], idR[i], 1, -a[i]);
    }

//    cout << dem << endl;
    cout << -mf.min_cost_flow(s, t, dem) << '\n';

}