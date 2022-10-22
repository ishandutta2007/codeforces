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
using PiP = pair<int, Pii>;
using v_bool = vector<bool>;
using v_Pii = vector<Pii>;
using v_PiP = vector<PiP>;

//int dx[4] = {1,0,-1,0};
//int dy[4] = {0,1,0,-1};
//char d[4] = {'D','R','U','L'};

const int mod = 1000000007;
//const int mod = 998244353;

void imp(){
    Out("NO");
    exit(0);
}

struct edge{int to, cost, id;};

class Graph
{
public:
    int N;
    vector<vector<edge>> G;
    v_bool exist;
    v_bool f;
    vec dp;

    Graph(int N): N(N){
        G = vector<vector<edge>>(N, vector<edge>(0));
        exist = v_bool(N - 1, true);
        dp.resize(N);
    }

    void add_Directed_edge(int from, int to, int cost = 1, int id = 0){
        G[from].push_back(edge({to, cost, id}));
    }

    void add_Undirected_edge(int v1, int v2, int cost = 1, int id = 0){
        add_Directed_edge(v1, v2, cost, id);
        add_Directed_edge(v2, v1, cost, id);
    }

    void dfs0(int v, int T){
        if(T == 1) return;
        mat cand;
        dfs1(v, T, -1, cand);
        if(SZ(cand) == 0) imp();

        vec q = cand[0];
        exist[q[0]] = false;
        dfs0(q[1], q[2]);
        dfs0(q[3], q[4]);
    }

    void dfs1(int v, int T, int p, mat &cand){
        dp[v] = 1;
        for(auto e: G[v]) if(e.to != p && exist[e.id]){
            dfs1(e.to, T, v, cand);
            if(f[dp[e.to]] && f[T - dp[e.to]]) cand.pb(vec({e.id, e.to, dp[e.to], v, T - dp[e.to]}));
            dp[v] += dp[e.to];
        }
    }

};

signed main(){

    int n; cin >> n;
    Graph G(n);
    REP(i, n - 1){
        int a, b; cin >> a >> b;
        G.add_Undirected_edge(a - 1, b - 1, 1, i);
    }
    v_bool f(n + 1, false);
    vec dp({0, 1});
    f[0] = f[1] = true;
    while(true){
        int sz = SZ(dp);
        dp.pb(dp[sz - 2] + dp[sz - 1]);
        if(dp.back() <= n) f[dp.back()] = true;
        else break;
    }
    G.f = f;

    if(!f[n]){
        imp();
    }
    G.dfs0(0, n);
    Out("YES");

    return 0;
}