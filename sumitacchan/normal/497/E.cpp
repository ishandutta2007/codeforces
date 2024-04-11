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
//#define Add(x, y) x = (x + (y)) % mod
//#define Mult(x, y) x = (x * (y)) % mod
 
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
        if(fact.size() < n + 1) fact_initialize(n);
        return fact[n] * invfact[r] * invfact[n - r];
    }
 
    mint nPr(int n, int r){
        if(n < 0 || r < 0 || r > n) return mint(0);
        if(fact.size() < n + 1) fact_initialize(n);
        return fact[n] * invfact[n - r];
    }
 
};

template<typename T>
struct Matrix{

    int R, C;
    vector<T> element;

    __inline__ T &at(int i, int j) { return element[i * C + j]; }

    Matrix(int R, int C, vector<T> &element): R(R), C(C), element(element) {
        assert(element.size() == R * C);
    }
    Matrix(vector<vector<T>> &_element) {
        R = _element.size();
        C = _element[0].size();
        element.resize(R * C);
        for(int i = 0; i < R; i++) for(int j = 0; j < C; j++) element[i * C + j] = _element[i][j];
    }

    Matrix(int R, int C): R(R), C(C) { element = vector<T>(R * C, (T)0); }

    //Make an identity matrix
    Matrix(int N): R(N), C(N) { 
        element = vector<T>(N * N, (T)0);
        for(int i = 0; i < N; i++) element[(N + 1) * i] = (T)1;
    }

    Matrix() :R(0), C(0) {}

    Matrix operator+(Matrix &x) { 
        assert(R == x.R && C == x.C);
        Matrix M(R, C);
        for(int i = 0; i < R * C; i++) M.element[i] = element[i] + x.element[i];
        return M;
    }
    Matrix operator-(Matrix &x) { 
        assert(R == x.R && C == x.C);
        Matrix M(R, C);
        for(int i = 0; i < R * C; i++) M.element[i] = element[i] - x.element[i];
        return M;
    }
    Matrix operator*(Matrix &x) { 
        assert(C == x.R);
        Matrix M(R, x.C);
        for(int i = 0; i < R; i++) for(int j = 0; j < x.C; j++){
            for(int k = 0; k < C; k++) M.at(i, j) += at(i, k) * x.at(k, j);
        }
        return M;
    }
    Matrix operator*(const T &a) {
        Matrix M(R, C);
        for(int i = 0; i < R * C; i++) M.element[i] = element[i] * a;
        return M;
    }
    Matrix operator+=(Matrix &x) { return *this = *this + x; }
    Matrix operator-=(Matrix &x) { return *this = *this - x; }
    Matrix operator*=(Matrix &x) { return *this = *this * x; }
    Matrix operator*=(const T &a) { 
        for(int i = 0; i < R * C; i++) element[i] *= a;
        return *this;
    }

    Matrix pow(long long n) {
        assert(R == C);
        Matrix M(R);
        if(n == 0) return M;
        int i0 = 64 - __builtin_clzll(n);
        for(int i = i0 - 1; i >= 0; i--){
            M *= M;
            if((n >> i) & 1) M *= (*this); 
        }
        return M;
    }

    void Print(){
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++) cout << element[i * C + j] << " ";
            cout << endl;
        }
    }

    Matrix slide(){
        Matrix A(R, C);
        REP(i, R) REP(j, C){
            int i0 = i, j0 = j;
            if(i0) i0 = i0 % (R - 1) + 1;
            if(j0) j0 = j0 % (C - 1) + 1;
            A.at(i0, j0) = at(i, j);
        }
        return A;
    }

};
 
signed main(){
 
    int n, k; cin >> n >> k;
    vec d;
    int n0 = n;
    while(n0){
        d.pb(n0 % k);
        n0 /= k;
    }
    int D = SZ(d);

    Matrix<mint> A0(k + 1);
    REP(j, k + 1) A0.at(1, j) = 1;
    vector<Matrix<mint>> Ms(D);
    Ms[0] = A0;
    REP(i, D - 1){
        A0 = Ms[i];
        Ms[i + 1] = Matrix<mint>(k + 1);
        REP(j, k){
            Ms[i + 1] = A0 * Ms[i + 1];
            A0 = A0.slide();
        }
    }

    Matrix<mint> dp(k + 1, 1);
    dp.at(0, 0) = 1;
    
    int tmp = 0;
    IREP(i, D){
        REP(j, tmp) Ms[i] = Ms[i].slide();
        REP(j, d[i]){
            dp = Ms[i] * dp;
            Ms[i] = Ms[i].slide();
        }
        tmp = (tmp + d[i]) % k;
    }

    mint ans = 0;
    REP(j, k + 1) ans += dp.at(0, j);
    Out(ans);
 
    return 0;
}