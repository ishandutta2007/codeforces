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

struct edge{int to, cost, id;};

class Graph
{
public:
    int N;
    vector<vector<edge>> G;

    Graph(int N): N(N){
        G = vector<vector<edge>>(N, vector<edge>(0));
    }

    void add_Directed_edge(int from, int to, int cost = 1, int id = 0){
        G[from].push_back(edge({to, cost, id}));
    }

    void add_Undirected_edge(int v1, int v2, int cost = 1, int id = 0){
        add_Directed_edge(v1, v2, cost, id);
        add_Directed_edge(v2, v1, cost, id);
    }

    //
    vector<int> color;
    bool is_bipartite(){
        color = vec(N, -1);
        REP(i, N) if(color[i] == -1){
            if(!dfs_for_check_bipartite(i, 0)) return false;
        }
        return true;
    }
    bool dfs_for_check_bipartite(int v, int c){
        if(color[v] != -1){
            if(color[v] == c) return true;
            else return false;
        }
        color[v] = c;
        for(auto e: G[v]) if(!dfs_for_check_bipartite(e.to, (c + e.cost) & 1)) return false;
        return true;
    }

    mat waeshall_floyd(){
        mat d(N, vec(N, INF));
        REP(i, N) d[i][i] = 0;
        REP(i, N) for(edge e: G[i]){
            d[i][e.to] = min(d[i][e.to], e.cost);
        }
        REP(k, N) REP(i, N) REP(j, N) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

        return d;
    }

};

void imp(){
    Out("NO");
    exit(0);
}

signed main(){

    int n, m; cin >> n >> m;
    Graph G(n);
    REP(_, m){
        int i, j, b; cin >> i >> j >> b;
        i--; j--;
        if(b == 0){
            G.add_Directed_edge(i, j, 1);
            G.add_Directed_edge(j, i, 1);
        }else{
            G.add_Directed_edge(i, j, 1);
            G.add_Directed_edge(j, i, -1);
        }
    }

    if(!G.is_bipartite()) imp();

    mat d = G.waeshall_floyd();
    REP(i, n) if(d[i][i] < 0) imp();

    int M = -1, s = -1;
    REP(i, n) REP(j, n){
        if(d[i][j] > M){
            M = d[i][j];
            s = i;
        }
    }
    int mm = INF;
    REP(i, n) chmin(mm, d[s][i]);
    vec ans(n);
    REP(i, n) ans[i] = d[s][i] - mm;

    Out("YES");
    Out(M);
    REP(i, n) cout << ans[i] << " ";
    cout << endl;

    return 0;
}