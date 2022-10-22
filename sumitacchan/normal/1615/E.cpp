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

struct LazySegmentTree
{
    //A: data, B: 
    using T_A = Pii;
    using T_B = int;
    T_A id_A = T_A(-1, -1);
    T_B id_B = 0;
    int N;
    vector<T_A> dat;
    vector<T_B> ope;

    T_A F_AA(T_A &u, T_A &v){
        return max(u, v);
    }

    T_A F_AB(T_A &u, T_B &v, int sz){
        return T_A(u.fi + v, u.se);
    }

    T_B F_BB(T_B &u, T_B &v){
        return u + v;
    }

    LazySegmentTree(int n){
        N = 1;
        while(n > N) N = N << 1;
        dat = vector<T_A>(2 * N - 1, id_A);
        ope = vector<T_B>(2 * N - 1, id_B);
    }

    LazySegmentTree(int n, vector<T_A> &v){
        N = 1;
        while(n > N) N = N << 1;
        dat = vector<T_A>(2 * N - 1, id_A);
        ope = vector<T_B>(2 * N - 1, id_B);
        REP(i, n) dat[i + N - 1] = v[i];
        IREP(i, N - 1) dat[i] = F_AA(dat[i * 2 + 1], dat[i * 2 + 2]); 
    }

    //
    void eval(int k, int l, int r){
        if(ope[k] != id_B){
            dat[k] = F_AB(dat[k], ope[k], r - l);
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

template<typename T> 
struct edge{ int to; T cost; int id; };

template<typename T = long long>
struct Graph
{

    int N;
    vector<vector<edge<T>>> E;
    vec idx, sz, par, depth;

    Graph(int N): N(N){
        E = vector<vector<edge<T>>>(N, vector<edge<T>>(0));
        idx.resize(N);
        sz.resize(N);
        par.resize(N);
        depth.resize(N);
    }

    void add_Directed_edge(int from, int to, T cost = 1, int id = 0){
        E[from].push_back(edge<T>({ to, cost, id }));
    }

    void add_Undirected_edge(int v1, int v2, T cost = 1, int id = 0){
        add_Directed_edge(v1, v2, cost, id);
        add_Directed_edge(v2, v1, cost, id);
    }

    void dfs(int v, int &k, int p = -1, int d = 1){
        par[v] = p;
        sz[v] = 1;
        idx[v] = k;
        depth[v] = d;
        k++;
        for(auto e: E[v]) if(e.to != p){
            dfs(e.to, k, v, d + 1);
            sz[v] += sz[e.to];
        }
    }

};

signed main(){

    int n, k; cin >> n >> k;
    Graph G(n);
    REP(i, n - 1){
        int a, b; cin >> a >> b;
        a--; b--;
        G.add_Undirected_edge(a, b);
    }
    int tmp = 0;
    G.dfs(0, tmp);

    int cnt = 0;
    v_Pii init(n, Pii(-1, -1));
    FOR(i, 1, n) if(SZ(G.E[i]) == 1){
        cnt++;
        init[G.idx[i]] = Pii(G.depth[i], i);
    }
    if(cnt <= k){
        int ans = 0;
        FOR(i, cnt, k + 1) chmax(ans, i * (n - i));
        cout << ans << endl;
        return 0;
    }

    int b = n;
    LazySegmentTree ST(n, init);
    v_bool used(n, false);
    REP(_, k){
        auto q = ST.get(0, n);
        //debug(q);
        b -= q.fi;
        int v = q.se;
        while(v != -1 && !used[v]){
            int idx = G.idx[v], sz = G.sz[v];
            ST.update(idx, idx + sz, -1);
            used[v] = true;
            v = G.par[v];
        }
    }
   
    int r = k, w = n - b - r;
    //int ans = w * (r - b);
    //debug(b);
    int ans = INF;
    REP(b0, b + 1){
        chmin(ans, (n - r - b0) * (r - b0));
    }

    cout << ans << endl;

    return 0;
}