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

mint solve(vec &a0, vec &a1, int x, int k){
    if(SZ(a0) == 0 || SZ(a1) == 0 || k == -1) return 0;

    vec a00, a01, a10, a11;
    for(int t: a0){
        if((t >> k) & 1) a01.pb(t);
        else a00.pb(t);
    }
    for(int t: a1){
        if((t >> k) & 1) a11.pb(t);
        else a10.pb(t);
    }

    mint ans = 0;
    if((x >> k) & 1){
        mint c1 = solve(a00, a11, x, k - 1), c2 = solve(a01, a10, x, k - 1);
        /*
        //a00,a01,a10,a111
        ans += c1 * c2;
        //a00,a111a01a10
        ans += c1 * (((mint)2).pow(SZ(a01)) + ((mint)2).pow(SZ(a10)) - 1);
        //a01,a101a00a11
        ans += c2 * (((mint)2).pow(SZ(a00)) + ((mint)2).pow(SZ(a11)) - 1);
        //(a00,a11)(a01,a10)
        ans += (((mint)2).pow(SZ(a00)) - 1) * (((mint)2).pow(SZ(a10)) - 1);
        ans += (((mint)2).pow(SZ(a01)) - 1) * (((mint)2).pow(SZ(a11)) - 1);*/

        ans += c1 * (c2 + ((mint)2).pow(SZ(a01)) + ((mint)2).pow(SZ(a10)) - 1);
        ans += c2 * (c1 + ((mint)2).pow(SZ(a00)) + ((mint)2).pow(SZ(a11)) - 1);
        ans -= c1 * c2;
        ans += (((mint)2).pow(SZ(a00)) - 1) * (((mint)2).pow(SZ(a10)) - 1);
        ans += (((mint)2).pow(SZ(a01)) - 1) * (((mint)2).pow(SZ(a11)) - 1);
    }else{
        ans += solve(a00, a10, x, k - 1);
        ans += solve(a01, a11, x, k - 1);
    }

    return ans;
}

signed main(){

    int n, x; cin >> n >> x;
    vec a(n); cin >> a;
    x++;

    int i0;
    IREP(i, 31) if((x >> i) & 1){
        i0 = i;
        break;
    }

    unordered_map<int, vec> A0, A1;
    set<int> st;
    REP(i, n){
        int t = a[i] >> (i0 + 1);
        if((a[i] >> i0) & 1) A1[t].pb(a[i]);
        else A0[t].pb(a[i]);
        st.insert(t);
    }

    mint ans = 0;
    for(int t: st){
        auto a0 = A0[t], a1 = A1[t];
        ans += ((mint)2).pow(SZ(a0)) + ((mint)2).pow(SZ(a1)) - 2;
        ans += solve(a0, a1, x, i0 - 1);
    }
    cout << ans << endl;

    return 0;
}