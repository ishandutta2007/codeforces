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

struct LazySegmentTree
{
    //A: data, B: 
    using T_A = int;
    using T_B = int;
    T_A id_A = -INF;
    T_B id_B = -INF;
    int N;
    vector<T_A> dat;
    vector<T_B> ope;

    T_A F_AA(T_A &u, T_A &v){
        return max(u, v);
    }

    T_A F_AB(T_A &u, T_B &v, int sz){
        return max(u, v);
    }

    T_B F_BB(T_B &u, T_B &v){
        return max(u, v);
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

signed main(){

    int n; cin >> n;
    vec h(n); cin >> h;
    REP(i, n) h[i]--;
    vec b(n); cin >> b;

    v_Pii q(n), v;
    v.pb(Pii(-1, -1));
    REP(i, n){
        while(v.back().fi >= h[i]){
            q[v.back().se].se = i - 1;
            v.pop_back();
        }
        q[i].fi = v.back().se + 1;
        v.pb(Pii(h[i], i));
    }
    for(auto p: v) if(p.se >= 0) q[p.se].se = n - 1;
    //vdebug(q);

    LazySegmentTree ST(n + 1);
    ST.update(0, 1, 0);
    REP(i, n){
        int l = q[i].fi, r = q[i].se;
        int M = ST.get(l, i + 1) + b[i];
        ST.update(i + 1, r + 1 + 1, M);
    }
    int ans = ST.val(n);

    Out(ans);

    return 0;
}