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

using mint = ModInt<1000000007>;
using mint2 = ModInt<1000000006>;

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
};

signed main(){

    int n, f1, f2, f3, c; cin >> n >> f1 >> f2 >> f3 >> c;

    Matrix<mint2> M(9, 9);
    REP(i, 3) REP(j, 3) M.at(i, i + 3 * j) = 1;
    REP(i, 6) M.at(i + 3, i) = 1;
    //M.Print();
    Matrix<mint2> v(9, 1);
    v.at(2, 0) = 1; v.at(4, 0) = 1;v.at(6, 0) = 1;
    //v.Print();

    v = M.pow(n - 3) * v;
    int r1 = v.at(0, 0).val, r2 = v.at(1, 0).val, r3 = v.at(2, 0).val;
    //debug(r1); debug(r2); debug(r3);

    Matrix<mint2> M2(5, 5);
    M2.at(0, 0) = 1; M2.at(0, 1) = 1; M2.at(0, 2) = 1; M2.at(0, 3) = 1;
    M2.at(1, 0) = 1; M2.at(2, 1) = 1;
    M2.at(3, 3) = 1; M2.at(3, 4) = 2;
    M2.at(4, 4) = 1;
    Matrix<mint2> v2(5, 1);
    v2.at(3, 0) = 2; v2.at(4, 0) = 1;

    v2 = M2.pow(n - 3) * v2;
    int r0 = v2.at(0, 0).val;

    mint ans = ((mint)c).pow(r0) * ((mint)f1).pow(r1) * ((mint)f2).pow(r2) * ((mint)f3).pow(r3);
    Out(ans);

    return 0;
}