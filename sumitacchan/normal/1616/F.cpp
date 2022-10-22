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

template<long long MOD>
struct ModInt{

    using ll = long long;
    ll val;

    void setval(ll v) { val = v % MOD; };
    ModInt(): val(0) {}
    ModInt(ll v) { setval(v); };

    ModInt operator+(const ModInt &x) const { return ModInt(val + x.val); }
    ModInt operator-(const ModInt &x) const { return ModInt(val - x.val + MOD); }
    ModInt operator*(const ModInt &x) const { return ModInt(val * x.val); }
    ModInt operator/(const ModInt &x) const { return *this * x.inv(); }
    ModInt operator-() const { return ModInt(MOD - val); }
    ModInt operator+=(const ModInt &x) { return *this = *this + x; }
    ModInt operator-=(const ModInt &x) { return *this = *this - x; }
    ModInt operator*=(const ModInt &x) { return *this = *this * x; }
    ModInt operator/=(const ModInt &x) { return *this = *this / x; }
    bool operator==(const ModInt &x) const { return (*this).val == x.val; }

    friend ostream& operator<<(ostream &os, const ModInt &x) { os << x.val; return os; }
    friend istream& operator>>(istream &is, ModInt &x) { is >> x.val; x.val = (x.val % MOD + MOD) % MOD; return is; }

    ModInt pow(ll n) const {
        ModInt a = 1;
        if(n == 0) return a;
        int i0 = 64 - __builtin_clzll(n);
        for(int i = i0 - 1; i >= 0; i--){
            a = a * a;
            if((n >> i) & 1) a *= (*this); 
        }
        return a;
    }
    ModInt inv() const { return this->pow(MOD - 2); }
};

using mint = ModInt<mod>; mint pow(mint x, long long n) { return x.pow(n); }
//using mint = double; //for debug
using mvec = vector<mint>;
using mmat = vector<mvec>;

struct Combination{

    vector<mint> fact, invfact;

    Combination(int N){
        fact = vector<mint>({mint(1)});
        invfact = vector<mint>({mint(1)});
        fact_initialize(N);
    }

    void fact_initialize(int N){
        int i0 = fact.size();
        if(i0 >= N + 1) return;
        fact.resize(N + 1);
        invfact.resize(N + 1);
        for(int i = i0; i <= N; i++) fact[i] = fact[i - 1] * i;
        invfact[N] = (mint)1 / fact[N];
        for(int i = N - 1; i >= i0; i--) invfact[i] = invfact[i + 1] * (i + 1); 
    }

    mint nCr(int n, int r){
        if(n < 0 || r < 0 || r > n) return mint(0);
        if((int)fact.size() < n + 1) fact_initialize(n);
        return fact[n] * invfact[r] * invfact[n - r];
    }

    mint nPr(int n, int r){
        if(n < 0 || r < 0 || r > n) return mint(0);
        if((int)fact.size() < n + 1) fact_initialize(n);
        return fact[n] * invfact[n - r];
    }

    mint Catalan(int n){
        if(n < 0) return 0;
        else if(n == 0) return 1;
        if((int)fact.size() < 2 * n + 1) fact_initialize(2 * n);
        return fact[2 * n] * invfact[n + 1] * invfact[n];
    }

};

//solve Ax=b
template <typename T>
bool solve_equation(vector<vector<T>> A, vector<T> b, vector<T> &x){
    if(A.size() == 0){
        assert(b.size() == 0);
        fill(x.begin(), x.end(), 0);
        return true;
    }

    int N = A.size(), M = A[0].size();
    for(int i = 0; i < N; i++) assert((int)A[i].size() == M);
    assert((int)b.size() == N);
    
    int i_now = 0;
    for(int j = 0; j < M; j++){
        int i0 = -1;
        for(int i = i_now; i < N; i++) if(!(A[i][j] == 0)){
            i0 = i; 
            break;
        }
        if(i0 == -1) continue;
        if(i0 != i_now){
            A[i_now].swap(A[i0]);
            swap(b[i_now], b[i0]);
        }
        for(int i = i_now + 1; i < N; i++){
            if(A[i][j] == 0) continue;
            T alpha = A[i][j] / A[i_now][j];
            for(int k = j; k < M; k++){
                A[i][k] -= A[i_now][k] * alpha;
            }
            b[i] -= b[i_now] * alpha;
        }
        i_now++;
        if(i_now == N) break;
    }

    const int rank = i_now;
    for(int i = rank; i < N; i++) if(!(b[i] == 0)) return false;

    x = vector<T>(M, 0);
    for(int i = rank - 1; i >= 0; i--){
        int j0 = -1;
        for(int j = 0; j < M; j++) if(!(A[i][j] == 0)){
            j0 = j;
            break;
        }
        for(int j = j0 + 1; j < M; j++){
            b[i] -= A[i][j] * x[j];
        }
        x[j0] = b[i] / A[i][j0];
    }

    return true;
}

signed main(){

    using F3 = ModInt<3>;
    using F3v = vector<F3>;
    using F3m = vector<F3v>;

    int t; cin >> t;
    REP(_, t){
        int n, m; cin >> n >> m;
        mat id(n, vec(n, -1));
        vec v(m), u(m), c(m);
        REP(i, m){
            cin >> v[i] >> u[i] >> c[i];
            v[i]--; u[i]--;
            if(c[i] > 0) c[i]--;
            id[v[i]][u[i]] = id[u[i]][v[i]] = i;
        }
        F3m A(0);
        F3v b(0);
        bool ok = true;
        REP(x, n) REP(y, x) REP(z, y){
            if(id[x][y] != -1 && id[y][z] != -1 && id[z][x] != -1){
                F3v a0(m);
                F3 b0 = 0;
                if(c[id[x][y]] == -1) a0[id[x][y]] = 1;
                else b0 -= c[id[x][y]];
                if(c[id[y][z]] == -1) a0[id[y][z]] = 1;
                else b0 -= c[id[y][z]];
                if(c[id[z][x]] == -1) a0[id[z][x]] = 1;
                else b0 -= c[id[z][x]];
                A.pb(a0);
                b.pb(b0);

                if(c[id[x][y]] != -1 && c[id[y][z]] != -1 && c[id[z][x]] != -1 && !(b0 == 0)) ok = false;
            }
        }
        //mdebug(A); vdebug(b);
        F3v x(m);
        if(ok && solve_equation(A, b, x)){
            REP(i, m) if(c[i] == -1) c[i] = x[i].val;
            for(int c0: c) cout << c0 + 1 << ' ';
            cout << endl;
        }else{
            cout << -1 << endl;
        }
    } 

    return 0;
}