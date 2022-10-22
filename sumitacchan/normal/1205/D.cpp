#include <bits/stdc++.h>
using namespace std;
/*#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T> using gpp_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename L> using gpp_map = tree<T, L, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T> using gpp_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;*/
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
#define Max(a, b) a = max(a, b)
#define Min(a, b) a = min(a, b)
#define bit(n) (1LL<<(n))
#define bit_exist(x, n) ((x >> n) & 1)
#define debug(x) cout << #x << "=" << x << endl;
#define vdebug(v) cout << #v << "=" << endl; REP(i_debug, v.size()){ cout << v[i_debug] << ","; } cout << endl;
#define mdebug(m) cout << #m << "=" << endl; REP(i_debug, m.size()){ REP(j_debug, m[i_debug].size()){ cout << m[i_debug][j_debug] << ","; } cout << endl;}
#define pb push_back
#define f first
#define s second
#define int long long
#define INF 1000000000000000000
template<typename T> istream &operator>>(istream &is, vector<T> &v){ for (auto &x : v) is >> x; return is; }
template<typename T> ostream &operator<<(ostream &os, vector<T> &v){ for(int i = 0; i < v.size(); i++) { cout << v[i]; if(i != v.size() - 1) cout << endl; }; return os; }
template<typename T> void Out(T x) { cout << x << endl; }
template<typename T1, typename T2> void Ans(bool f, T1 y, T2 n) { if(f) Out(y); else Out(n); }

using vec = vector<int>;
using mat = vector<vec>;
using Pii = pair<int, int>;
using PiP = pair<int, Pii>;
using PPi = pair<Pii, int>;
using bools = vector<bool>;
using pairs = vector<Pii>;

//int dx[4] = {1,0,-1,0};
//int dy[4] = {0,1,0,-1};
//char d[4] = {'D','R','U','L'};

const int mod = 1000000007;
//const int mod = 998244353;
//#define Add(x, y) x = (x + (y)) % mod
//#define Mult(x, y) x = (x * (y)) % mod

struct edge{int to, cost, id;};

class Graph
{
public:
    int N;
    vector<vector<edge>> G;
    vec ans;

    Graph(int N): N(N){
        G = vector<vector<edge>>(N, vector<edge>(0));
        ans.resize(N - 1);
    }

    void add_Directed_edge(int from, int to, int cost = 1, int id = 0){
        G[from].push_back(edge({to, cost, id}));
    }

    void add_Undirected_edge(int v1, int v2, int cost = 1, int id = 0){
        add_Directed_edge(v1, v2, cost, id);
        add_Directed_edge(v2, v1, cost, id);
    }

    //1
    vector<int> sz, centroids;
    void FindCentroids(int v, int p = -1){
        if(p == -1){
            sz.resize(N);
            centroids.resize(0);
        }
        sz[v] = 1;
        bool is_centroid = true;
        for(auto e: G[v]) if(e.to != p){
            FindCentroids(e.to, v);
            if(sz[e.to] > N / 2) is_centroid = false;
            sz[v] += sz[e.to];
        }
        if(N - sz[v] > N / 2) is_centroid = false;
        if(is_centroid) centroids.push_back(v);
    }

    bools selected;
    void half(int v){
        selected = bools(N, false);
        vec vs, ns;
        int tot = 0;
        for(auto e: G[v]){
            vs.pb(e.to);
            tot += sz[e.to];
            ns.pb(sz[e.to]);
        }

        int n = SZ(vs);
        mat dp(n + 1, vec(tot / 2 + 1, 0));
        dp[0][0] = 1;
        REP(i, n){
            REP(j, tot / 2 + 1){
                dp[i + 1][j] += dp[i][j];
                if(j + ns[i] <= tot / 2) dp[i + 1][j + ns[i]] += dp[i][j];
            }
        }
        int mm = -1;
        REP(j, tot / 2 + 1) if(dp[n][j]) mm = j;
        IREP(i, n) if(mm - ns[i] >= 0 && dp[i][mm - ns[i]]){
            selected[vs[i]] = true;
            mm -= ns[i];
        }
    }

    void dfs1(int v, int p, int &n, int now){
        for(auto e: G[v]){
            if(p == -1){
                if(selected[e.to]) continue;
            }else{
                if(e.to == p) continue;
            }
            e.cost = n - now;
            ans[e.id] = n - now;
            n++;
            dfs1(e.to, v, n, n - 1);
        }
    }

    void dfs2(int v, int p, int &n, int now, int X){
        for(auto e: G[v]){
            if(p == -1){
                if(!selected[e.to]) continue;
            }else{
                if(e.to == p) continue;
            }
            e.cost = (n - now) * X;
            ans[e.id] = (n - now) * X;
            n++;
            dfs2(e.to, v, n, n - 1, X);
        }
    }

};

signed main(){

    int n; cin >> n;
    Graph G(n);
    vec a(n), b(n);
    REP(i, n - 1){
        cin >> a[i] >> b[i];
        G.add_Undirected_edge(a[i] - 1, b[i] - 1, -1, i);
    }
    G.FindCentroids(0);
    int g = G.centroids[0];
    G.FindCentroids(g);

    G.half(g);

    int nn = 1;
    G.dfs1(g, -1, nn, 0);
    int X = nn;
    nn = 1;
    G.dfs2(g, -1, nn, 0, X);

    REP(i, n - 1){
        cout << a[i] << " " << b[i] << " " << G.ans[i] << endl;
    }

    return 0;
}