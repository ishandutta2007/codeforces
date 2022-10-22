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

//const int mod = 1000000007;
const int mod = 998244353;

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

    //SCC decomposition
    void dfs(int v, vector<bool> &used, vec &vs){
        used[v] = true;
        REP(i, G[v].size()){
            if(!used[G[v][i].to]) dfs(G[v][i].to, used, vs);
        }
        vs.push_back(v);
    }
    void rdfs(int v, int k, vector<bool> &used, vec &cmp){
        used[v] = true;
        cmp[v] = k;
        REP(i, G[v].size()){
            if(!used[G[v][i].to]) rdfs(G[v][i].to, k, used, cmp);
        }
    }
    //u->v => cmp[u]<cmp[v]
    vec scc(int &k){
        vector<bool> used(N, false);
        vec vs(0), cmp(N);
        REP(i, N){
            if(!used[i]) dfs(i, used, vs);
        }
        //reverse graph
        Graph rG(N);
        REP(v, N) REP(i, G[v].size()) rG.add_Directed_edge(G[v][i].to, v, G[v][i].cost);

        fill(used.begin(), used.end(), false);
        k = 0;
        IREP(i, vs.size()){
            if(!used[vs[i]]) rG.rdfs(vs[i], k++, used, cmp);
        }
        return cmp;
    }

};


signed main(){

    int t; cin >> t;
    REP(_, t){
        int n; cin >> n;
        vec a(n); cin >> a;
        vec b(n); cin >> b;
        REP(i, n){
            a[i]--; b[i]--;
        }

        vec cnt(n);
        REP(i, n) cnt[a[i]]++;
        int M = 0, x = -1;
        REP(i, n){
            if(cnt[i] > M){
                x = i;
                M = cnt[i];
            }
        }

        Graph G(n);
        bool ans = true;
        REP(i, n){
            if(a[i] == x || b[i] == x) continue;
            if(a[i] == b[i]) ans = false;
            G.add_Directed_edge(a[i], b[i], 1);
        }
        int sz;
        auto cmp = G.scc(sz);
        if(sz != n) ans = false;
        chOut(ans, "AC", "WA");
    }

    return 0;
}