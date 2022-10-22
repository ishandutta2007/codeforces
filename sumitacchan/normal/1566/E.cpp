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
    v_bool f, is_leaf;
    int num_leaf = 0, num_bud = 0;

    Graph(int N): N(N){
        E = vector<vector<edge<T>>>(N, vector<edge<T>>(0));
        f = v_bool(N, true);
        is_leaf = v_bool(N, false);
    }

    void add_Directed_edge(int from, int to, T cost = 1, int id = 0){
        E[from].push_back(edge<T>({ to, cost, id }));
    }

    void add_Undirected_edge(int v1, int v2, T cost = 1, int id = 0){
        add_Directed_edge(v1, v2, cost, id);
        add_Directed_edge(v2, v1, cost, id);
    }

    void dfs(int v = 0, int p = -1){
        is_leaf[v] = true;
        f[v] = false;
        for(auto e: E[v]) if(e.to != p){
            dfs(e.to, v);
            if(f[e.to]){
                is_leaf[v] = false;
                if(!is_leaf[e.to]) f[v] = true;
            }
        }

        if(is_leaf[v] || p == -1) f[v] = true;

        if(!f[v]) num_bud++;
        else if(is_leaf[v]) num_leaf++;
    }

};

signed main(){

    int t; cin >> t;
    REP(_, t){
        int n; cin >> n;
        Graph G(n);
        REP(i, n - 1){
            int a, b; cin >> a >> b;
            G.add_Undirected_edge(a - 1, b - 1);
        }
        G.dfs(0);
        //debug(G.num_leaf); debug(G.num_bud);
        int ans = G.num_leaf - G.num_bud;
        Out(ans);
    }

    return 0;
}