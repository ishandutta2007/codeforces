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
#define vdebug(v) { cout << #v << "=" << endl; REP(i_debug, (int)v.size()){ cout << v[i_debug] << ","; } cout << endl; }
#define mdebug(m) { cout << #m << "=" << endl; REP(i_debug, (int)m.size()){ REP(j_debug, (int)m[i_debug].size()){ cout << m[i_debug][j_debug] << ","; } cout << endl;} }
#define pb push_back
#define fi first
#define se second
#define int long long
#define INF 1000000000000000000
template<typename T> istream &operator>>(istream &is, vector<T> &v){ for (auto &x : v) is >> x; return is; }
template<typename T> ostream &operator<<(ostream &os, vector<T> &v){ for(int i = 0; i < (int)v.size(); i++) { cout << v[i]; if(i != (int)v.size() - 1) cout << endl; }; return os; }
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

template<typename T> 
struct edge{ int to; T cost; int id; };

template<typename T = long long>
struct Graph
{

    int N;
    vector<vector<edge<T>>> E;
    vec g, dp, par;

    Graph(int N): N(N){
        E = vector<vector<edge<T>>>(N, vector<edge<T>>(0));
        g = vec(N, 0);
        dp = vec(N, INF);
        par = vec(N, -1);
    }

    void add_Directed_edge(int from, int to, T cost = 1, int id = 0){
        E[from].push_back(edge<T>({ to, cost, id }));
    }

    void add_Undirected_edge(int v1, int v2, T cost = 1, int id = 0){
        add_Directed_edge(v1, v2, cost, id);
        add_Directed_edge(v2, v1, cost, id);
    }

    void dfs(int v, int p = -1){
        par[v] = p;
        dp[v] = v;
        for(auto e: E[v]) if(e.to != p){
            dfs(e.to, v);
            g[v] ^= 1 + g[e.to];
            chmin(dp[v], dp[e.to]);
        }
    }

};

signed main(){

    int n; cin >> n;
    Graph G(n);
    REP(i, n - 1){
        int a, b; cin >> a >> b;
        G.add_Undirected_edge(a - 1, b - 1);
    }
    G.dfs(0);
    
    mat m0(n), m1(n);
    FOR(i, 1, n){
        m0[G.dp[i]].pb(i);
        if(G.dp[i] > G.dp[G.par[i]]) m1[G.dp[G.par[i]]].pb(i);
    }

    set<int> st;
    for(auto e: G.E[0]) st.insert(e.to);
    int g0 = G.g[0];

    string ans(n, '1');
    if(g0 == 0) ans[0] = '2';
    FOR(i, 1, n){
        for(int v: m0[i]){
            g0 ^= 1;
            if(st.count(v)){
                st.erase(v);
                g0 ^= G.g[v] + 1;
            }
        }
        for(int v: m1[i]){
            st.insert(v);
            g0 ^= G.g[v] + 1;
        }
        if(g0 == 0) ans[i] = '2';
    }

    Out(ans);

    return 0;
}