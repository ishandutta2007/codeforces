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

struct edge{int to, cost;};

class Graph
{
public:
    int N;
    vector<vector<edge>> G;
    vec dp;

    Graph(int N): N(N){
        G = vector<vector<edge>>(N, vector<edge>(0));
        dp.resize(N);
    }

    void add_edge(int from, int to, int cost = 0){
        G[from].push_back(edge({to, cost}));
    }

    void add_edge2(int v1, int v2, int cost = 0){
        add_edge(v1, v2, cost);
        add_edge(v2, v1, cost);
    }

    void dfs(vec &o, int v, int &l, int p = -1){
        if(p != -1 && SZ(G[v]) == 1){
            dp[v] = 1;
            l++;
        }else{
            if(o[v] == 1){
                dp[v] = INF;
                for(auto e: G[v]) if(e.to != p){
                    dfs(o, e.to, l, v);
                    Min(dp[v], dp[e.to]);
                }
            }else{
                dp[v] = 0;
                for(auto e: G[v]) if(e.to != p){
                    dfs(o, e.to, l, v);
                    dp[v] += dp[e.to];
                }
            }
        }
    }

};

signed main(){

    int n; cin >> n;
    vec o(n); readv(o);
    int f;
    Graph G(n);
    REP(i, n - 1){
        cin >> f;
        G.add_edge2(i + 1, f - 1);
    }
    int l = 0;
    G.dfs(o, 0, l);
    int ans = l + 1 - G.dp[0];
    cout << ans << endl;

    return 0;
}