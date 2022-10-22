#include <bits/stdc++.h>
using namespace std;
/*#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T> using gpp_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename L> using gpp_map = tree<T, L, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T> using gpp_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;*/
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

struct RollingHash{

    using ll = long long;
    static const ll MOD = 1000000007;
    int N;
    ll x, invx;
    vector<ll> pow_x, pow_invx, hash_vec, invhash_vec;

    template<typename T>
    RollingHash(int x, vector<T> S, bool calcinv = false): x(x) {
        N = S.size();

        pow_x.resize(N + 1);
        pow_x[0] = 1;
        REP(i, N) pow_x[i + 1] = (pow_x[i] * x) % MOD;
        pow_invx.resize(N + 1);
        invx = inv();
        pow_invx[0] = 1;
        REP(i, N) pow_invx[i + 1] = (pow_invx[i] * invx) % MOD;

        hash_vec.resize(N + 1);
        hash_vec[0] = 0;
        REP(i, N) hash_vec[i + 1] = (hash_vec[i] + pow_x[i] * S[i]) % MOD;

        if(calcinv){
            invhash_vec.resize(N + 1);
            invhash_vec[N] = 0;
            REP(i, N) invhash_vec[N - 1 - i] = (invhash_vec[N - i] + pow_x[i] * S[N - 1 - i]) % MOD;
        }
    }

    RollingHash(int x, string S, bool calcinv = false){
        vector<int> s(S.size());
        REP(i, SZ(S)) s[i] = (int)S[i];
        *this = RollingHash(x, s, calcinv);
    }

    ll inv(){
        ll a = 1, n = MOD - 2;
        for(int i = 63; i >= 0; i--){ a = (a * a) % MOD; if((n >> i) & 1) a = (a * x) % MOD; }
        return a;
    }

    //0<=l<=r<N
    //Hash of (S_l,S_(l+1),...,S_r)
    ll hash(int l, int r){
        return (((hash_vec[r + 1] - hash_vec[l] + MOD) % MOD) * pow_invx[l]) % MOD;
    }

    //0<=l<=r<N
    //Hash of (S_r,S_(r-1),...,S_l)
    ll invhash(int l, int r){
        return (((invhash_vec[l] - invhash_vec[r + 1] + MOD) % MOD) * pow_invx[N - 1 - r]) % MOD;
    }

};

signed main(){

    int n, m; cin >> n >> m;
    string p; cin >> p;
    vec y(m); cin >> y;

    string s(n, '?');
    int M = -1, np = SZ(p);
    RollingHash RH(114514, p);

    REP(i, m){
        y[i]--;
        if(M < y[i]) M = y[i] - 1;
        else{
            int len = M - y[i] + 1;
            if(RH.hash(0, len - 1) != RH.hash(np - len, np - 1)){
                Out(0);
                return 0;
            }
        }
        FOR(j, M + 1, y[i] + np) s[j] = p[j - y[i]];
        M = y[i] + np - 1;
    }
    int cnt = 0;
    REP(i, n) if(s[i] == '?') cnt++;
    mint ans = pow((mint)26, cnt);
    Out(ans);

    return 0;
}