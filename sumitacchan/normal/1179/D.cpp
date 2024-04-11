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
#define Add(x, y) x = (x + (y)) % mod
#define Mult(x, y) x = (x * (y)) % mod

//pos.size()==0
class CHT{
    using T = int;
    T id = -INF;

    struct line{
        T a, b;
        line(T a, T b): a(a), b(b){}
        T get(T x){return a * x + b;}
    };
    struct node{
        line l;
        node *lch, *rch;
        node(line l): l(l), lch(nullptr), rch(nullptr){}
        ~node(){
            if(lch) delete lch;
            if(rch) delete rch;
        }
    };

public:
    int n;
    vector<T> pos;
    node *root;
    bool calcMax;

    CHT(vector<T> pos, bool calcMax = true): n(pos.size()), pos(pos), root(nullptr), calcMax(calcMax){}

    ~CHT() {if(root) delete(root);}

    node* modify(node *p, int lb, int ub, line &l){
        if(!p) return new node(l);
        if(p->l.get(pos[lb]) >= l.get(pos[lb]) && p->l.get(pos[ub]) >= l.get(pos[ub])) return p;
        if(p->l.get(pos[lb]) <= l.get(pos[lb]) && p->l.get(pos[ub]) <= l.get(pos[ub])){
            p->l = l;
            return p;
        }

        int c = (lb + ub) / 2;
        if(p->l.get(pos[c]) < l.get(pos[c])) swap(p->l, l);
        if(p->l.get(pos[lb]) <= l.get(pos[lb])) p->lch = modify(p->lch, lb, c, l);
        else p->rch = modify(p->rch, c + 1, ub, l);

        return p;
    }

    T sub(node *p, int lb, int ub, int t){
        if(!p) return id;
        if(ub - lb == 0) return p->l.get(pos[t]);
        int c = (lb + ub) / 2;
        if(t <= c) return max(p->l.get(pos[t]), sub(p->lch, lb, c, t));
        else return max(p->l.get(pos[t]), sub(p->rch, c + 1, ub, t));
    }

    void insert(T a, T b){
        if(!calcMax){a *= -1; b *= -1;};
        line l(a, b);
        root = modify(root, 0, n - 1, l);
    }

    T get(T x){
        int t = Lower_bound(pos, x);
        assert(t < n && pos[t] == x);
        T res = sub(root, 0, n - 1, t);
        if(!calcMax) res *= -1;
        return res;
    }
};


struct edge{int to, cost;};

class Graph
{
public:
    int N;
    vector<vector<edge>> G;
    vec par, sz, dp;

    Graph(int N): N(N){
        G = vector<vector<edge>>(N, vector<edge>(0));
        par.resize(N);
        sz.resize(N);
        dp.resize(N);
    }

    void add_Directed_edge(int from, int to, int cost = 1){
        G[from].push_back(edge({to, cost}));
    }

    void add_Undirected_edge(int v1, int v2, int cost = 1){
        add_Directed_edge(v1, v2, cost);
        add_Directed_edge(v2, v1, cost);
    }

    void dfs_for_sz(int v, int p = -1){
        par[v] = p;
        sz[v] = 1;
        for(auto e: G[v]) if(e.to != p){
            dfs_for_sz(e.to, v);
            sz[v] += sz[e.to];
        }
    }

    void dfs_for_dp(int v){
        dp[v] = sz[v] * sz[v];
        for(auto e: G[v]) if(e.to != par[v]){
            dfs_for_dp(e.to);
            int s = sz[v] - sz[e.to];
            Min(dp[v], s * s + dp[e.to]);
        }
    }

    int calcS(int v){
        int S = (N - 1) * (N - 1) + 1;
        vec vs;
        set<int> ss;
        for(auto e: G[v]) if(e.to != par[v]){
            int s = N - sz[e.to];
            Min(S, s * s + dp[e.to]);
            vs.pb(e.to);
            ss.insert(sz[e.to]);
        }
        vec tmp;
        for(int i: ss) tmp.pb(i);
        if(SZ(vs) >= 2){
            CHT cht(tmp, false);
            REP(i, SZ(vs)){
                int j = vs[i];
                if(i > 0) Min(S, sz[j] * sz[j] + dp[j] + cht.get(sz[j]));
                cht.insert(-2 * (N - sz[j]), (N - sz[j]) * (N - sz[j]) + dp[j]);
            }
        }

        return S;
    }

};

signed main(){

    int n; cin >> n;
    Graph G(n);
    int a, b;
    REP(i, n - 1){
        cin >> a >> b;
        G.add_Undirected_edge(a - 1, b - 1, 1);
    }
    G.dfs_for_sz(0);
    G.dfs_for_dp(0);
    //vdebug(G.dp);

    int S = INF;
    REP(i, n) Min(S, G.calcS(i));

    int ans = n * (n - 1) / 2 + (n * n - S) / 2;
    Out(ans);

    return 0;
}