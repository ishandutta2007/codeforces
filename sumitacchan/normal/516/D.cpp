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
    vec dp;
    mat next;

    Graph(int N): N(N){
        G = vector<vector<edge>>(N, vector<edge>(0));
        dp.resize(N);
        next = mat(20, vec(N, -1));
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

    vec D;
    void dfs(int v, int p = -1){
        for(auto e: G[v]) if(e.to != p){
            next[0][e.to] = v;
            dfs(e.to, v);
        }
    }

    void init(){
        FOR(t, 1, 20){
            REP(v, N) if(next[t - 1][v] != -1){
                next[t][v] = next[t - 1][next[t - 1][v]];
            }
        }
    }

    int calcans(int l, int i0){
        fill(all(dp), 0);
        REP(v, N){
            dp[v]++;

            int now = v;
            IREP(t, 20){
                if(next[t][now] != -1 && D[next[t][now]] >= D[v] - l) now = next[t][now];
            }
            int p = next[0][now];
            if(p != -1) dp[p]--;

            //debug(v); debug(p);
        }
        dfs2(i0);

        int ans = 0;
        REP(v, N) chmax(ans, dp[v]);
        return ans;
    }

    void dfs2(int v, int p = -1){
        for(auto e: G[v]) if(e.to != p){
            dfs2(e.to, v);
            dp[v] += dp[e.to];
        }
    }
    

};

signed main(){

    int n; cin >> n;
    Graph G(n);
    REP(i, n - 1){
        int a, b, d; cin >> a >> b >> d;
        G.add_Undirected_edge(a - 1, b - 1, d);
    }

    int s, t;
    G.diameter(s, t);
    vec dist_s(n), dist_t(n);
    G.dfs_for_calcdist(s, -1, 0, dist_s);
    G.dfs_for_calcdist(t, -1, 0, dist_t);

    vec dist(n);
    REP(i, n) dist[i] = max(dist_s[i], dist_t[i]);
    int i0 = -1, MM = INF;
    REP(i, n) if(dist[i] < MM){
        MM = dist[i];
        i0 = i;
    }

    G.D = dist;
    G.dfs(i0);
    G.init();

    int q; cin >> q;
    REP(_, q){
        int l; cin >> l;
        int ans = G.calcans(l, i0);
        cout << ans << endl;
    }


    return 0;
}