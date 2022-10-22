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
        if(fact.size() < n + 1) fact_initialize(n);
        return fact[n] * invfact[r] * invfact[n - r];
    }

    mint nPr(int n, int r){
        if(n < 0 || r < 0 || r > n) return mint(0);
        if(fact.size() < n + 1) fact_initialize(n);
        return fact[n] * invfact[n - r];
    }

    mint Catalan(int n){
        if(n < 0) return 0;
        else if(n == 0) return 1;
        if(fact.size() < 2 * n + 1) fact_initialize(2 * n);
        return fact[2 * n] * invfact[n + 1] * invfact[n];
    }

};

//C...P
mint calc_ans(vec a, int U){
    int n = SZ(a);
    vec S1(n + 1, 0), S2(n + 2, 0);
    REP(i, n){
        S1[i + 1] = S1[i] + a[i];
        S2[i + 2] = S2[i] + a[i];
    }

    mint ans = 0;
    FOR(l, 1, n){
        if(S1[n] - S1[l] < U) continue;
        int mm = n - 1 - l;
        if(mm % 2) mm--;
        mm /= 2;

        int P = S1[n] - S1[l + 2 * mm] + S2[l + 2 * mm] - S2[l];
        if(P >= U){
            ans += 1 + mm;
        }else{
            int ok = 0, ng = mm;
            while(ng - ok > 1){
                int mid = (ng + ok) / 2;
                P = S1[n] - S1[l + 2 * mid] + S2[l + 2 * mid] - S2[l];
                if(P >= U) ok = mid;
                else ng = mid;
            }
            ans += 1 + ok;
        }
    }
    return ans;
}

signed main(){

    int t; cin >> t;
    REP(q, t){
        int n; cin >> n;
        vec a(n); cin >> a;
        int T = 0;
        vec S1(n + 1, 0), S2(n + 2, 0);
        REP(i, n){
            T += a[i];
            S1[i + 1] = S1[i] + a[i];
            S2[i + 2] = S2[i] + a[i];
        }

        int U = T / 2 + 1;
        mint ans = 0;
        if(n >= 2){
            ans += calc_ans(a, U);
        }
        //debug(ans);
        if(n >= 3){
            vec b(n - 1);
            REP(i, n - 1) b[i] = a[i + 1];
            ans += calc_ans(b, U - a[0]);
        }
        //debug(ans);
        if(n >= 3){
            vec b(n - 1);
            REP(i, n - 1) b[i] = a[i];
            ans += calc_ans(b, U);
        }
        //debug(ans);
        if(n >= 4){
            vec b(n - 2);
            REP(i, n - 2) b[i] = a[i + 1];
            ans += calc_ans(b, U - a[0]);
        }
        //debug(ans);

        FOR(i, 1, n + 1) if(S1[i] >= U) ans += 1;

        cout << ans << '\n';
    }

    return 0;
}