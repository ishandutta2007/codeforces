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

struct SegmentTree
{
    using T = int;

    int N;
    vector<T> dat;

    T id = -INF;
    T F(T &a, T &b) { return max(a, b); }
    
    SegmentTree(int n){
        N = 1;
        while(n > N) N = N << 1;
        dat = vector<T>(2 * N - 1, id);
    }

    SegmentTree(int n, vector<T> &v){
        N = 1;
        while(n > N) N = N << 1;
        dat = vector<T>(2 * N - 1, id);
        for(int i = 0; i < n; i++) dat[i + N - 1] = v[i];
        for(int i = N - 2; i >= 0; i--) dat[i] = F(dat[i * 2 + 1], dat[i * 2 + 2]); 
    }

    SegmentTree(){}


    void update(int k, T a){
        k += N - 1;
        dat[k] = a;
        while(k > 0){
            k = (k - 1) / 2;
            dat[k] = F(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }

    void reset() { fill(dat.begin(), dat.end(), id); }

    T get(int a, int b, int k, int l, int r){
        if(r <= a || b <= l) return id;
        if(a <= l && r <= b) return dat[k];
        else{
            T vl = get(a, b, k * 2 + 1, l, (l + r) / 2);
            T vr = get(a, b, k * 2 + 2, (l + r) / 2, r);
            return F(vl, vr);
        }
    }
    T get(int a, int b) { return get(a, b, 0, 0, N); }

    T val(int k){ return dat[k + N - 1]; }
};

struct edge{int to, cost, id;};

class Graph
{
public:
    int N;
    vector<vector<edge>> G;
    vec a, par;
    mat vs;
    vec dp;
    int D;

    Graph(int N): N(N){
        G = vector<vector<edge>>(N, vector<edge>(0));
        vs.resize(N);
        par.resize(N);
        dp = vec(N, -INF);
        D = 0;
    }

    void add_Directed_edge(int from, int to, int cost = 1, int id = 0){
        G[from].push_back(edge({to, cost, id}));
    }

    void add_Undirected_edge(int v1, int v2, int cost = 1, int id = 0){
        add_Directed_edge(v1, v2, cost, id);
        add_Directed_edge(v2, v1, cost, id);
    }

    void dfs0(int v = 0, int p = -1, int d = 0){
        par[v] = p;
        vs[d].pb(v);
        chmax(D, d);
        for(auto e: G[v]) if(e.to != p){
            dfs0(e.to, v, d + 1);
        }
    }

    int solve(){
        dp[0] = 0;
        FOR(d, 1, D + 1){
            int n = SZ(vs[d]);
            v_Pii p(n);
            REP(i, n) p[i] = Pii(a[vs[d][i]], vs[d][i]);
            Sort(p);

            REP(i, n){
                int MM = max(p[i].fi - p[0].fi, p[n - 1].fi - p[i].fi);
                chmax(dp[p[i].se], MM + dp[par[p[i].se]]);
            }

            vec tmp(n);
            REP(i, n) tmp[i] = p[i].fi + dp[par[p[i].se]];
            SegmentTree ST(n, tmp);
            REP(i, n){
                int MM = max(ST.get(0, i) + p[i].fi, ST.get(i, n) - p[i].fi);
                chmax(dp[p[i].se], MM);
                ST.update(i, -p[i].fi + dp[par[p[i].se]]);
            }
            if(d == D){
                int ans = 0;
                REP(i, n) chmax(ans, dp[vs[d][i]]);
                return ans;
            }
            
        } 
    }
};

signed main(){

    int t; cin >> t;
    REP(q, t){
        int n; cin >> n;
        Graph G(n);
        REP(i, n - 1){
            int p; cin >> p;
            G.add_Directed_edge(p - 1, i + 1);
        }
        vec a(n);
        FOR(i, 1, n) cin >> a[i];
        G.a = a;
        G.dfs0();
        Out(G.solve());
    }

    return 0;
}