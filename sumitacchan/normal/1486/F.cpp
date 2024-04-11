#include <bits/stdc++.h>
using namespace std;
//using namespace atcoder;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define IFOR(i, begin, end) for(int i=(end)-1;i>=(begin);i--)
#define IREP(i, n) IFOR(i,0,n)
#define Sort(v) sort(v.begin(), v.end())
#define Reverse(v) reverse(v.begin(), v.end())
#define all(v) v.begin(),v.end()
#define SZ(v) ((int)v.size())
#define Lower_bound(v, x) distance(v.begin(), lower_bound(v.begin(), v.end(), x))
#define Upper_bound(v, x) distance(v.begin(), upper_bound(v.begin(), v.end(), x))
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define bit(n) (1LL<<(n))
#define debug(x) cout << #x << "=" << x << endl;
#define vdebug(v) { cout << #v << "=" << endl; REP(i_debug, v.size()){ cout << v[i_debug] << ","; } cout << endl; }
#define mdebug(m) { cout << #m << "=" << endl; REP(i_debug, m.size()){ REP(j_debug, m[i_debug].size()){ cout << m[i_debug][j_debug] << ","; } cout << endl;} }
#define pb push_back
#define fi first
#define se second
//#define int long long
//#define INF 1000000000000000000
template<typename T> istream &operator>>(istream &is, vector<T> &v){ for (auto &x : v) is >> x; return is; }
template<typename T> ostream &operator<<(ostream &os, vector<T> &v){ for(int i = 0; i < v.size(); i++) { cout << v[i]; if(i != v.size() - 1) cout << endl; }; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, pair<T1, T2> p){ cout << '(' << p.first << ',' << p.second << ')'; return os; }
template<typename T> void Out(T x) { cout << x << endl; }
template<typename T1, typename T2> void chOut(bool f, T1 y, T2 n) { if(f) Out(y); else Out(n); }

using vec = vector<int>;
using mat = vector<vec>;
using Pii = pair<int, int>;
using v_bool = vector<bool>;
using v_Pii = vector<Pii>;

//int dx[4] = {1,0,-1,0};
//int dy[4] = {0,1,0,-1};
//char d[4] = {'D','R','U','L'};

const int mod = 1000000007;
//const int mod = 998244353;

struct edge{int to, cost, id;};

class Graph
{
public:
    int N;
    vector<vector<edge>> G;
    vec cnt_v, cnt_e;

    Graph(int N): N(N){
        G = vector<vector<edge>>(N, vector<edge>(0));
        cnt_v = vec(N, 0);
        cnt_e = vec(N - 1, 0);
    }

    void add_Directed_edge(int from, int to, int cost = 1, int id = 0){
        G[from].push_back(edge({to, cost, id}));
    }

    void add_Undirected_edge(int v1, int v2, int cost = 1, int id = 0){
        add_Directed_edge(v1, v2, cost, id);
        add_Directed_edge(v2, v1, cost, id);
    }

    const int logN = 20;
    mat anc;
    vec depth;
    void init_doubling(){
        anc = mat(logN, vec(N, -1));
        depth = vec(N);
        dfs0(0);
        FOR(t, 1, logN) REP(i, N) if(anc[t - 1][i] != -1) anc[t][i] = anc[t - 1][anc[t - 1][i]];
    }
    void dfs0(int v, int p = -1){
        anc[0][v] = p;
        if(p == -1) depth[v] = 0;
        else depth[v] = depth[p] + 1;

        for(auto e: G[v]) if(e.to != p){
            dfs0(e.to, v);
        }
    }
    int calc_anc(int v, int ng){
        int now = v;
        REP(t, logN) if(now != -1 && (ng >> t) & 1) now = anc[t][now];
        return now;
    }
    int calc_lca(int v, int w){
        if(depth[v] > depth[w]) swap(v, w);
        if(calc_anc(w, depth[w] - depth[v]) == v) return v;
        int g0 = 0, g1 = depth[v];
        while(g1 - g0 > 1){
            int g = (g0 + g1) / 2;
            if(calc_anc(v, depth[v] - g) == calc_anc(w, depth[w] - g)) g0 = g;
            else g1 = g;
        }
        return calc_anc(v, depth[v] - g0);
    }

    void dfs1(int v, int p = -1){
        for(auto e: G[v]) if(e.to != p){
            dfs1(e.to, v);
            cnt_e[e.id] = cnt_v[e.to];
            cnt_v[v] += cnt_v[e.to];
        }
    }

};

signed main(){

    int n; cin >> n;
    Graph G(n);
    map<Pii, int> id;
    REP(i, n - 1){
        int u, v; cin >> u >> v;
        u--; v--;
        G.add_Undirected_edge(u, v, 1, i);
        id[minmax(u, v)] = i;
    }
    G.init_doubling();

    int m; cin >> m;
    vec u(m), v(m), lca(m);
    REP(i, m){
        cin >> u[i] >> v[i];
        u[i]--; v[i]--;
        
        G.cnt_v[u[i]]++;
        G.cnt_v[v[i]]++;
        lca[i] = G.calc_lca(u[i], v[i]);
        G.cnt_v[lca[i]] -= 2;
    }
    G.dfs1(0);
    REP(i, m) if(u[i] != v[i]) G.cnt_v[lca[i]]++;
    //vdebug(G.cnt_v); vdebug(G.cnt_e);

    vec cnt0(n, 0);
    vector<map<int, int>> cnt1(n);
    vector<map<Pii, int>> cnt2(n);
    REP(i, m) if(u[i] != v[i]){
        cnt0[lca[i]]++;
        if(u[i] != lca[i] && v[i] != lca[i]){
            int ud = G.calc_anc(u[i], G.depth[u[i]] - G.depth[lca[i]] - 1);
            int vd = G.calc_anc(v[i], G.depth[v[i]] - G.depth[lca[i]] - 1);
            cnt1[lca[i]][vd] += 1;
            cnt1[lca[i]][ud] += 1;
            cnt2[lca[i]][minmax(ud, vd)] += 1;
        }else if(u[i] == lca[i]){
            int vd = G.calc_anc(v[i], G.depth[v[i]] - G.depth[lca[i]] - 1);
            cnt1[lca[i]][vd] += 1;
        }else if(v[i] == lca[i]){
            int ud = G.calc_anc(u[i], G.depth[u[i]] - G.depth[lca[i]] - 1);
            cnt1[lca[i]][ud] += 1;
        }
    }

    long long ans = 0;
    REP(i, m) if(u[i] != v[i]){
        long long T = G.cnt_v[lca[i]];
        if(u[i] != lca[i] && v[i] != lca[i]){
            int ud = G.calc_anc(u[i], G.depth[u[i]] - G.depth[lca[i]] - 1);
            int vd = G.calc_anc(v[i], G.depth[v[i]] - G.depth[lca[i]] - 1);
            
            T -= G.cnt_e[id[minmax(lca[i], ud)]] + G.cnt_e[id[minmax(lca[i], vd)]] - cnt2[lca[i]][minmax(ud, vd)];
        }else if(u[i] == lca[i]){
            int vd = G.calc_anc(v[i], G.depth[v[i]] - G.depth[lca[i]] - 1);
            T -= G.cnt_e[id[minmax(lca[i], vd)]];
        }else if(v[i] == lca[i]){
            int ud = G.calc_anc(u[i], G.depth[u[i]] - G.depth[lca[i]] - 1);
            T -= G.cnt_e[id[minmax(lca[i], ud)]];
        }
        ans += T;
    }

    REP(i, n){
        long long T = (long long)cnt0[i] * (cnt0[i] - 1) / 2;
        for(auto q: cnt1[i]) T -= (long long)q.se * (q.se - 1) / 2;
        for(auto q: cnt2[i]) T += (long long)q.se * (q.se - 1) / 2;
        ans -= T;
    }

    REP(i, m) if(u[i] == v[i]){
        ans += G.cnt_v[u[i]];
        G.cnt_v[u[i]]++;
    }

    Out(ans);

    return 0;
}