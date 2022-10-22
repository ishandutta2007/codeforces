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
        ans = vec(N, -1);
    }

    void add_Directed_edge(int from, int to, int cost = 1, int id = 0){
        G[from].push_back(edge({to, cost, id}));
    }

    void add_Undirected_edge(int v1, int v2, int cost = 1, int id = 0){
        add_Directed_edge(v1, v2, cost, id);
        add_Directed_edge(v2, v1, cost, id);
    }

    //calculate diameter of a Tree
    void dfs_for_calcdist(int v, int p, int c, vec &dist){
        if(p != -1) dist[v] = dist[p] + c;
        for(auto e: G[v]) if(e.to != p) dfs_for_calcdist(e.to, v, e.cost, dist);
    } 

    int diameter(int &v1, int &v2, int s = 0){
        vec dist(N, 0);
        dfs_for_calcdist(s, -1, -1, dist);
        v1 = distance(dist.begin(), max_element(dist.begin(), dist.end()));
        fill(dist.begin(), dist.end(), 0);
        dfs_for_calcdist(v1, -1, -1, dist);
        auto amax = max_element(dist.begin(), dist.end());
        v2 = distance(dist.begin(), amax);
        return *amax;
    }





    void dfs_for_k2(int v, int p = -1){
        if(p == -1) ans[v] = 0;
        else ans[v] = 1 - ans[p];
        for(auto e: G[v]) if(e.to != p) dfs_for_k2(e.to, v);
    }

    void showans(){
        Out("Yes");
        REP(i, N) cout << ans[i] + 1 << ' ';
        cout << endl;
    }

};

signed main(){

    int n, k; cin >> n >> k;
    Graph G(n);
    REP(i, n - 1){
        int a, b; cin >> a >> b;
        G.add_Undirected_edge(a - 1, b - 1, 1);
    }

    if(k == 2){
        G.dfs_for_k2(0);
        G.showans();
        return 0;
    }
    int s, t;
    int R = G.diameter(s, t, 0);
    //debug(R);
    if(R + 1 < k){
        Out("Yes");
        REP(i, n) cout << i % k + 1 << ' ';
        cout << endl;
        return 0;
    }

    vec dist_s(n, 0), dist_t(n, 0);
    G.dfs_for_calcdist(s, -1, -1, dist_s);
    G.dfs_for_calcdist(t, -1, -1, dist_t);

    int now = s;
    int c = 0;
    while(true){
        G.ans[now] = c;
        c = (c + 1) % k;
        if(now == t) break;
        for(auto e: G.G[now]) if(dist_t[e.to] == dist_t[now] - 1){
            now = e.to;
            break;
        }
    }
    REP(i, n) if(G.ans[i] == -1){
        int dt = dist_t[i], ds = dist_s[i];
        if(dt >= k - 1 && ds >= k - 1){
            Out("No");
            return 0;
        }
        if(ds >= dt) G.ans[i] = ds % k;
        else G.ans[i] = ((G.ans[t] - dt) % k + k) % k;
    }
    G.showans();

    return 0;
}