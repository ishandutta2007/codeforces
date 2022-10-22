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
#define int long long
#define INF 1000000000000000000
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

struct UnionFind
{
    vector<int> par, sz;
    int n_cc;

    UnionFind(int N){
        par = vector<int>(N);
        REP(i, N) par[i] = i;
        sz = vector<int>(N, 1);
        n_cc = N;
    }

    int find(int x){
        if(par[x] == x) return x;
        else return par[x] = find(par[x]);
    }

    void unite(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return;

        if(sz[x] < sz[y]) swap(x, y);

        par[y] = x;
        sz[x] += sz[y];
        n_cc--;
    }

    bool is_union(int x, int y){
        x = find(x);
        y = find(y);
        return x == y;
    }

    int union_size(int x){
        return sz[find(x)];
    }

};

struct edge{int to, cost, id;};

class Graph
{
public:
    int N;
    vector<vector<edge>> G;
    vec dp;

    Graph(int N): N(N){
        G = vector<vector<edge>>(N, vector<edge>(0));
        dp.resize(N);
    }

    void add_Directed_edge(int from, int to, int cost = 1, int id = 0){
        G[from].push_back(edge({to, cost, id}));
    }

    void add_Undirected_edge(int v1, int v2, int cost = 1, int id = 0){
        add_Directed_edge(v1, v2, cost, id);
        add_Directed_edge(v2, v1, cost, id);
    }

    void dfs(int v, int p = -1){
        if(p == -1) dp[v] = 0;
        for(auto e: G[v]) if(e.to != p){
            dp[e.to] = max(dp[v], e.cost);
            dfs(e.to, v);
        }
    }

};

using PiP = pair<int, Pii>;
using v_PiP = vector<PiP>;

signed main(){

    int n, q, s, d; cin >> n >> q >> s >> d;
    s--;
    vec a(n); cin >> a;
    map<int, int> id;
    REP(i, n) id[a[i]] = i;

    UnionFind UF(n);
    Graph G(n);
    set<int> S;
    REP(i, n) S.insert(a[i]);
    S.insert(-INF); S.insert(INF);
    while(UF.n_cc > 1){
        mat ls(n);
        v_PiP unite;
        REP(i, n) ls[UF.find(i)].pb(a[i]);
        REP(i, n) if(SZ(ls[i])){
            for(int x: ls[i]) S.erase(x);
            
            PiP mm(INF, Pii(INF, INF));
            for(int x: ls[i]){
                {
                    auto it = S.lower_bound(x - d);
                    int y = *it;
                    if(y < x) chmin(mm, PiP(y - (x - d), Pii(y, x)));
                    it--; y = *it;
                    if(y < x) chmin(mm, PiP((x - d) - y, Pii(y, x)));
                }
                {
                    auto it = S.lower_bound(x + d);
                    int y = *it;
                    if(x < y) chmin(mm, PiP(y - (x + d), Pii(x, y)));
                    it--; y = *it;
                    if(x < y) chmin(mm, PiP((x + d) - y, Pii(x, y)));
                }
            }
            unite.pb(mm);

            for(int x: ls[i]) S.insert(x);
        }

        for(auto q: unite){
            int i = id[q.se.fi], j = id[q.se.se];
            if(!UF.is_union(i, j)){
                //cout << i << "," << j << "," << q.fi << endl;
                UF.unite(i, j);
                G.add_Undirected_edge(i, j, q.fi);
            }
        }
    }
    G.dfs(s);

    REP(_, q){
        int i, k; cin >> i >> k;
        i--;
        chOut(G.dp[i] <= k, "Yes", "No");
    }

    return 0;
}