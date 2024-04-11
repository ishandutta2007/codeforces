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
//#define int long long
#define INF 2000000000
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

struct LazySegmentTree
{
    //A: data, B: 
    using T_A = Pii;
    using T_B = int;
    T_A id_A = T_A(INF, -INF);
    T_B id_B = 0;
    int N;
    vector<T_A> dat;
    vector<T_B> ope;

    T_A F_AA(T_A &u, T_A &v){
        return T_A(min(u.fi, v.fi), max(u.se, v.se));
    }

    T_A F_AB(T_A &u, T_B &v, int sz, int k){
        if(v == 1) return mM[k];
        else if(v == -1) return id_A;
        else return u;
    }

    T_B F_BB(T_B &u, T_B &v){
        if(u == 0 || v == 0) return u + v;
        else return v;
    }

    vector<T_A> mM;
    LazySegmentTree(int n, vector<int> &v){
        N = 1;
        while(n > N) N = N << 1;
        dat = vector<T_A>(2 * N - 1, id_A);
        ope = vector<T_B>(2 * N - 1, id_B);
        mM = vector<T_A>(2 * N - 1, id_A);
        REP(i, n){
            mM[i + N - 1] = T_A(v[i], v[i]);
        }
        IREP(i, N - 1) mM[i] = F_AA(mM[i * 2 + 1], mM[i * 2 + 2]); 
    }

    //
    void eval(int k, int l, int r){
        if(ope[k] != id_B){
            dat[k] = F_AB(dat[k], ope[k], r - l, k);
            if(r - l > 1){
                ope[k * 2 + 1] = F_BB(ope[k * 2 + 1], ope[k]);
                ope[k * 2 + 2] = F_BB(ope[k * 2 + 2], ope[k]);
            }
            ope[k] = id_B;
        }
    }

    void update(int a, int b, T_B x, int k, int l, int r){

        eval(k, l, r);
        if(b <= l || r <= a) return;

        if(a <= l && r <= b){
            ope[k] = F_BB(ope[k], x);
            eval(k, l, r);
        }else{
            update(a, b, x, k * 2 + 1, l, (l + r) / 2);
            update(a, b, x, k * 2 + 2, (l + r) / 2, r);
            dat[k] = F_AA(dat[k * 2 + 1], dat[k * 2 + 2]);
        }

    }

    T_A get(int a, int b, int k, int l, int r){
        if(r <= a || b <= l) return id_A;

        eval(k, l, r);
        if(a <= l && r <= b) return dat[k];
        else{
            T_A vl = get(a, b, k * 2 + 1, l, (l + r) / 2);
            T_A vr = get(a, b, k * 2 + 2, (l + r) / 2, r);
            return F_AA(vl, vr);
        }
    }

    //[a,b)
    void update(int a, int b, T_B x){ update(a, b, x, 0, 0, N); }

    //[a, b)
    T_A get(int a, int b){ return get(a, b, 0, 0, N); }

    T_A val(int k){ return get(k, k + 1); }
};

struct UnionFind
{
    vector<int> par, sz;
    int n_cc;

    UnionFind(int N){
        par = vector<int>(N);
        REP(i, N) par[i] = i;
        sz = vector<int>(N, 1);
        n_cc = N;
    }

    int find(int x){
        if(par[x] == x) return x;
        else return par[x] = find(par[x]);
    }

    void unite(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return;

        if(sz[x] < sz[y]) swap(x, y);

        par[y] = x;
        sz[x] += sz[y];
        n_cc--;
    }

    bool is_union(int x, int y){
        x = find(x);
        y = find(y);
        return x == y;
    }

    int union_size(int x){
        return sz[find(x)];
    }

};

//LCA
//0-indexed BIT
class BinaryIndexedTree
{
    using T = int;
private:
    void _add(int i, T x) {
        if (i > N) return;
        data[i] += x;
        _add(i + (i & -i), x);
    }

public:
    vector<T> data;
    int N;

    BinaryIndexedTree(int N): data(vector<T>(N + 1, 0)), N(N) {}
    BinaryIndexedTree(){}

    //sum of [0,i) (0<=i<=N)
    T sum(int i) {
        if (!i) return 0;
        return data[i] + sum(i - (i & -i));
    }

    void add(int i, T x) { _add(i + 1, x); };
    void update(int i, T x){
        T now = sum(i + 1) - sum(i);
        add(i, x - now);
    }

};

struct SegmentTree
{
    using T = Pii;

    int N;
    vector<T> dat;

    T id = T(INF, INF);
    T F(T &a, T &b) { return min(a, b); }
    
    SegmentTree(int n){
        N = 1;
        while(n > N) N = N << 1;
        dat = vector<T>(2 * N - 1, id);
    }

    SegmentTree(int n, vector<T> &v){
        N = 1;
        while(n > N) N = N << 1;
        dat = vector<T>(2 * N - 1, id);
        for(int i = 0; i < n; i++) dat[i + N - 1] = v[i];
        for(int i = N - 2; i >= 0; i--) dat[i] = F(dat[i * 2 + 1], dat[i * 2 + 2]); 
    }

    SegmentTree(){}


    void update(int k, T a){
        k += N - 1;
        dat[k] = a;
        while(k > 0){
            k = (k - 1) / 2;
            dat[k] = F(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }

    void reset() { fill(dat.begin(), dat.end(), id); }

    T get(int a, int b, int k, int l, int r){
        if(r <= a || b <= l) return id;
        if(a <= l && r <= b) return dat[k];
        else{
            T vl = get(a, b, k * 2 + 1, l, (l + r) / 2);
            T vr = get(a, b, k * 2 + 2, (l + r) / 2, r);
            return F(vl, vr);
        }
    }
    T get(int a, int b) { return get(a, b, 0, 0, N); }

    T val(int k){ return dat[k + N - 1]; }
};

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

    // (SparseTableBIT)
    //id0~N-1
    vector<int> es, pos;
    vector<Pii> vs;
    vector<vector<int>> ls_p, ls_m;
    bool is_initialized = false;
    SegmentTree ST;
    BinaryIndexedTree BIT;
    void euler_tour(int v = 0){
        vs.resize(0);
        es.resize(0);
        pos = vector<int>(N, -1);
        ls_p = vector<vector<int>>(N - 1, vector<int>(0));
        ls_m = vector<vector<int>>(N - 1, vector<int>(0));
        dfs_euler_tour(v);
        ST = SegmentTree(vs.size(), vs);
        BIT = BinaryIndexedTree(es.size());
        REP(i, es.size()) BIT.add(i, es[i]);
        is_initialized = true;
    }

    void dfs_euler_tour(int v, int p = -1, int d = 0, int p_cost = 0, int p_id = -1){
        if(pos[v] == -1) pos[v] = vs.size();
        vs.push_back(Pii(d, v));
        if(p_id != -1){
            ls_p[p_id].push_back(es.size());
            es.push_back(p_cost);
        }
        for(auto e: G[v]) if(e.to != p){
            assert(0 <= e.id && e.id < N - 1);
            dfs_euler_tour(e.to, v, d + 1, e.cost, e.id);
            vs.push_back(Pii(d, v));
            ls_m[e.id].push_back(es.size());
            es.push_back(-e.cost);
        }
    }

    int lca(int a, int b){
        assert(is_initialized);
        a = pos[a], b = pos[b];
        if(a > b) swap(a, b);
        return ST.get(a, b + 1).second;
    }
    int calcdist(int a, int b){
        assert(is_initialized);
        int c = lca(a, b);
        a = pos[a], b = pos[b], c = pos[c];
        return BIT.sum(a) + BIT.sum(b) - 2 * BIT.sum(c);
    }
    void update_cost(int id0, int x){
        assert(is_initialized);
        for(int i: ls_p[id0]) BIT.update(i, x);
        for(int i: ls_m[id0]) BIT.update(i, -x);
    }



    void dfs0(int v, vec &vs){
        if(SZ(G[v]) == 0) vs.pb(v);
        for(auto e: G[v]) dfs0(e.to, vs);
    }

};

signed main(){

    int n, q; cin >> n >> q;
    vec u(n - 1), v(n - 1), w(n - 1);
    v_Pii p(n - 1);
    REP(i, n - 1){
        cin >> u[i] >> v[i] >> w[i];
        u[i]--; v[i]--;
        p[i] = Pii(w[i], i);
    }
    Sort(p);

    UnionFind UF(n);
    Graph G(2 * n - 1);
    vec cost(2 * n - 1, -1), id(n);
    REP(i, n) id[i] = i;
    REP(i, n - 1){
        int i0 = p[i].se;
        int a = UF.find(u[i0]), b = UF.find(v[i0]);
        G.add_Directed_edge(n + i, id[a]);
        G.add_Directed_edge(n + i, id[b]);
        cost[n + i] = w[i0];
        
        UF.unite(a, b);
        a = UF.find(a);
        id[a] = n + i;
    }

    G.euler_tour(2 * n - 2);
    vec vs;
    G.dfs0(2 * n - 2, vs);

    vec pos(n);
    REP(i, n) pos[vs[i]] = i;
    //vdebug(pos);

    LazySegmentTree ST(n, pos);
    REP(_, q){
        int t; cin >> t;
        if(t == 1){
            int l, r; cin >> l >> r;
            l--; r--;
            ST.update(l, r + 1, 1);
        }else if(t == 2){
            int l, r; cin >> l >> r;
            l--; r--;
            ST.update(l, r + 1, -1);
        }else{
            int x; cin >> x;
            x--;
            auto mM = ST.get(0, n);
            //debug(mM);
            int v1 = mM.fi, v2 = mM.se;
            chmin(v1, pos[x]);
            chmax(v2, pos[x]);
            int lca = G.lca(vs[v1], vs[v2]);
            int ans = cost[lca];
            cout << ans << endl;
        }
    }

    return 0;
}