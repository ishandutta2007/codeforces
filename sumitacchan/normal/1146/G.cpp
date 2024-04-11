#include <bits/stdc++.h>
using namespace std;
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
#define Ans(f, y, n) if(f) cout << y << endl; else cout << n << endl;
#define debug(x) cout << #x << "=" << x << endl;
#define vdebug(v) cout << #v << "=" << endl; REP(i, v.size()){ cout << v[i] << ","; } cout << endl;
#define mdebug(m) cout << #m << "=" << endl; REP(i, m.size()){ REP(j, m[i].size()){ cout << m[i][j] << ","; } cout << endl;}
#define pb push_back
#define f first
#define s second
#define int long long
#define INF 1000000000000000000

using vec = vector<int>;
using mat = vector<vec>;
using Pii = pair<int, int>;
using PiP = pair<int, Pii>;
using PPi = pair<Pii, int>;
using bools = vector<bool>;
using pairs = vector<Pii>;

template<typename T> void readv(vector<T> &a){ REP(i, a.size()) cin >> a[i]; }
void readv_m1(vector<int> &a){ REP(i, a.size()){cin >> a[i]; a[i]--;} }

//int dx[4] = {1,0,-1,0};
//int dy[4] = {0,1,0,-1};

int mod = 1000000007;
//int mod = 998244353;
#define Add(x, y) x = (x + (y)) % mod
#define Mult(x, y) x = (x * (y)) % mod

struct edge { int to, cap, rev; };

class Graph
{
public:
    int N;
    vector<vector<edge>> G;
    vec level, iter;

    Graph(int N): N(N){
        G = vector<vector<edge>>(N, vector<edge>(0));
        level = vec(N);
        iter = vec(N);
    }

    void add_edge(int from, int to, int cap){
        G[from].push_back((edge){to, cap, G[to].size()});
        G[to].push_back((edge){from, 0, G[from].size() - 1});
    }

    void bfs(int s){
        memset(&level[0], -1, sizeof(level[0]) * level.size());
        queue<int> que;
        level[s] = 0;
        que.push(s);
        while(!que.empty()){
            int v = que.front(); que.pop();
            REP(i, G[v].size()){
                edge &e = G[v][i];
                if(e.cap > 0 && level[e.to] < 0){
                    level[e.to] = level[v] + 1;
                    que.push(e.to);
                }
            }
        }
    }

    int dfs(int v, int t, int f){
        if(v == t) return f;
        for(int &i = iter[v]; i < G[v].size(); i++){
            edge &e = G[v][i];
            if(e.cap > 0 && level[v] < level[e.to]){
                int d = dfs(e.to, t, min(f, e.cap));
                if(d > 0){
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    int max_flow(int s, int t){
        int flow = 0;
        for(;;){
            bfs(s);
            if(level[t] < 0) return flow;
            memset(&iter[0], 0, sizeof(iter[0]) * iter.size());
            int f;
            while((f = dfs(s, t, INF)) > 0) flow += f;
        }
    }

};


signed main(){

    int n, h, m; cin >> n >> h >> m;
    vec l(m), r(m), x(m), c(m);
    REP(i, m){
        cin >> l[i] >> r[i] >> x[i] >> c[i];
        l[i]--; r[i]--;
    }

    int M = 2500 * n;
    Graph G(n * (h + 2) + m + 2);
    int s = n * (h + 2) + m, t = s + 1;
    REP(i, n){
        G.add_edge(s, i * (h + 2), INF);
        G.add_edge(i * (h + 2) + h + 1, t, INF);
        REP(j, h + 1) G.add_edge(i * (h + 2) + j, i * (h + 2) + j + 1, 2500 - j * j);
    }
    REP(i, m){
        G.add_edge(n * (h + 2) + i, t, c[i]);
        FOR(j, l[i], r[i] + 1) G.add_edge(j * (h + 2) + x[i] + 1, n * (h + 2) + i, INF);
    }
    int f = G.max_flow(s, t);
    int ans = M - f;
    cout << ans << endl;

    return 0;
}