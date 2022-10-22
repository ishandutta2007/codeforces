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

    vec dijkstra(int s, int t){
        vec d(N);
        priority_queue<Pii, vector<Pii>, greater<Pii>> que;
        fill(d.begin(), d.end(), INF);
        d[s] = 0;
        que.push(Pii(0, s));

        while(!que.empty()){
            Pii p = que.top(); que.pop();
            int v = p.second;
            if(v == t) return d;
            if(d[v] < p.first) continue;
            REP(i, G[v].size()){
                edge e = G[v][i];
                if(d[e.to] > d[v] + e.cost){
                    d[e.to] = d[v] + e.cost;
                    que.push(Pii(d[e.to], e.to));
                }
            }
        }
        return d;
    }

};

signed main(){

    int n; cin >> n;
    vec a(n), c(n);
    REP(i, n) cin >> a[i] >> c[i];

    v_Pii p(n);
    REP(i, n) p[i] = Pii(a[i], c[i]);
    Sort(p);

    Graph G(n);
    REP(i, n - 1){
        G.add_Directed_edge(i + 1, i, 0);
        G.add_Directed_edge(i, i + 1, p[i + 1].fi - p[i].fi);

        int j = Upper_bound(p, Pii(p[i].fi + p[i].se, INF));
        G.add_Directed_edge(i, j - 1, 0);
        if(j < n) G.add_Directed_edge(i, j, p[j].fi - p[i].fi - p[i].se);
    }
    int d = G.dijkstra(0, -1)[n - 1];
    
    int ans = 0;
    REP(i, n) ans += c[i];
    ans += d;
    Out(ans);

    return 0;
}