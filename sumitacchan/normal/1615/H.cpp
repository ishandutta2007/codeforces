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

struct edge { int to, cap, cost, rev, id; };

class Graph
{
public:
    int N;
    vector<vector<edge>> G;
    vec h, dist, prevv, preve;

    Graph(int N): N(N){
        G.resize(N);
        h.resize(N);
        dist.resize(N);
        prevv.resize(N);
        preve.resize(N);
    }

    void add_Directed_edge(int from, int to, int cap, int cost, int id = -1){
        G[from].push_back((edge){to, cap, cost, (int)G[to].size(), -1});
        G[to].push_back((edge){from, 0, -cost, (int)G[from].size() - 1, id});
    }

    //-1
    int min_cost_flow(int s, int t, int f){
        int res = 0;
        fill(all(h), 0);
        while(f > 0){
            priority_queue<Pii, vector<Pii>, greater<Pii>> que;
            fill(all(dist), INF);
            dist[s] = 0;
            que.push(Pii(0, s));
            while(!que.empty()){
                Pii p = que.top(); que.pop();
                int v = p.second;
                if(dist[v] < p.first) continue;
                REP(i, G[v].size()){
                    edge &e = G[v][i];
                    if(e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]){
                        dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                        prevv[e.to] = v;
                        preve[e.to] = i;
                        que.push(Pii(dist[e.to], e.to));
                    }
                }
            }
            if(dist[t] == INF) return -1;
            REP(v, N) h[v] += dist[v];

            int d = f;
            for(int v = t; v != s; v = prevv[v]){
                d = min(d, G[prevv[v]][preve[v]].cap);
            }
            f -= d;
            res += d * h[t];
            for(int v = t; v != s; v = prevv[v]){
                edge &e = G[prevv[v]][preve[v]];
                e.cap -= d;
                G[v][e.rev].cap += d;
            }
        }
        return res;
    }

    //
    vector<int> calc_flow(int num_id){
        vector<int> flow(num_id, 0);
        REP(v, N) for(auto e: G[v]) if(e.id >= 0 && e.id < num_id) flow[e.id] = e.cap;
        return flow;
    }

    vec calc_potential(int o){
        vec d(N);
        priority_queue<Pii, vector<Pii>, greater<Pii>> que;
        fill(all(d), INF);
        d[o] = 0;
        REP(t, N){
            REP(v, N) for(auto e: G[v]) if(e.cap > 0) chmin(d[e.to], d[v] + e.cost); 
        }
        return d;
    }
};

signed main(){

    int n, m; cin >> n >> m;
    vec a(n); cin >> a;
    Graph G(n + 3);
    int o = n, s = n + 1, t = s + 1;
    int ans = 0;
    REP(i, n){
        G.add_Directed_edge(o, i, 2, a[i]);
        //G.add_Directed_edge(s, o, 1, 0);
        G.add_Directed_edge(i, t, 1, 0);
        
        ans -= a[i];
    }
    G.add_Directed_edge(s, o, n, 0);
    
    REP(i, m){
        int u, v; cin >> u >> v;
        u--; v--;
        G.add_Directed_edge(v, u, INF, 0);
    }

    int cost = G.min_cost_flow(s, t, n);
    ans = -(ans + cost);
    //debug(ans);

    auto p = G.calc_potential(o);
    //vdebug(p);
    REP(i, n) cout << p[i] - p[o] << ' ';
    cout << endl;

    return 0;
}