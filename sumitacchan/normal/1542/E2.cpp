//Optimization
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx")

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
//const int mod = 998244353;

int MOD;
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

//using mint = ModInt; mint pow(mint x, long long n) { return x.pow(n); }
//using mint = double; //for debug
using mint = int;
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

signed main(){

    int n; cin >> n >> MOD;
    int M = n * (n - 1) / 2;
    mmat dp0(2, mvec(2 * M + 1, 0)), dq0(2, mvec(2 * M + 1, 0));
    mmat dp1(2, mvec(2 * M + 1, 0)), dq1(2, mvec(2 * M + 1, 0));
    dq0[1][M] = 1;

    mvec Q(n + 1);
    Q[0] = 1;
    REP(i, n) (Q[i + 1] = Q[i] * (n - i)) %= MOD;
    mint ans = 0;
    FOR(i, 2, n + 1){
        /*int m = (i - 1) * (i - 2) / 2;
        FOR(j, M - m, M + m + 1){
            dq[i][j] += dp[i - 1][j] + dq[i - 1][j];
            FOR(k, 1, i){
                dp[i][j - k] += dp[i - 1][j] + dq[i - 1][j];
                dq[i][j + k] += dp[i - 1][j] + dq[i - 1][j];
            }
            FOR(k, -(i - 1), i){
                dp[i][j + k] += dp[i - 1][j] * (i - 1 - abs(k));
                dq[i][j + k] += dq[i - 1][j] * (i - 1 - abs(k));
            }
        }*/
        fill(all(dp0[i % 2]), 0);
        fill(all(dq0[i % 2]), 0);
        fill(all(dp1[i % 2]), 0);
        fill(all(dq1[i % 2]), 0);

        int m = (i - 1) * (i - 2) / 2;
        FOR(j, M - m, M + m + 1){
            dp0[i % 2][j - (i - 1)] += dp0[(i - 1) % 2][j] + dq0[(i - 1) % 2][j];
            dp0[i % 2][j] -= dp0[(i - 1) % 2][j] + dq0[(i - 1) % 2][j];

            dq0[i % 2][j + 1] += dp0[(i - 1) % 2][j] + dq0[(i - 1) % 2][j];
            if(j + i <= 2 * M) dq0[i % 2][j + i] -= dp0[(i - 1) % 2][j] + dq0[(i - 1) % 2][j];
            
            dp1[i % 2][j - (i - 1)] += dp0[(i - 1) % 2][j];
            dp1[i % 2][j] -= dp0[(i - 1) % 2][j];
            dp0[i % 2][j - (i - 1)] -= dp0[(i - 1) % 2][j] * (j - (i - 1));
            dp0[i % 2][j] += dp0[(i - 1) % 2][j] * (j - (i - 1));
            dp1[i % 2][j] -= dp0[(i - 1) % 2][j];
            if(j + i <= 2 * M) dp1[i % 2][j + i] += dp0[(i - 1) % 2][j];
            dp0[i % 2][j] += dp0[(i - 1) % 2][j] * (i - 1 + j);
            if(j + i <= 2 * M) dp0[i % 2][j + i] -= dp0[(i - 1) % 2][j] * (i - 1 + j);

            dq1[i % 2][j - (i - 1)] += dq0[(i - 1) % 2][j];
            dq1[i % 2][j] -= dq0[(i - 1) % 2][j];
            dq0[i % 2][j - (i - 1)] -= dq0[(i - 1) % 2][j] * (j - (i - 1));
            dq0[i % 2][j] += dq0[(i - 1) % 2][j] * (j - (i - 1));
            dq1[i % 2][j] -= dq0[(i - 1) % 2][j];
            if(j + i <= 2 * M) dq1[i % 2][j + i] += dq0[(i - 1) % 2][j];
            dq0[i % 2][j] += dq0[(i - 1) % 2][j] * (i - 1 + j);
            if(j + i <= 2 * M) dq0[i % 2][j + i] -= dq0[(i - 1) % 2][j] * (i - 1 + j);

            //dq0[i % 2][j] += dp0[(i - 1) % 2][j] + dq0[(i - 1) % 2][j];
        }

        int m2 = i * (i - 1) / 2;
        FOR(j, M - m2 + 1, M + m2 + 1){
            dp0[i % 2][j] += dp0[i % 2][j - 1];
            dp1[i % 2][j] += dp1[i % 2][j - 1];
            dq0[i % 2][j] += dq0[i % 2][j - 1];
            dq1[i % 2][j] += dq1[i % 2][j - 1];
        }
        FOR(j, M - m2, M + m2 + 1){
            dp0[i % 2][j] += dp1[i % 2][j] * j;
            dq0[i % 2][j] += dq1[i % 2][j] * j;
            if(M - m <= j && j <= M + m) dq0[i % 2][j] += dp0[(i - 1) % 2][j] + dq0[(i - 1) % 2][j];

            dp0[i % 2][j] = (dp0[i % 2][j] % MOD + MOD) % MOD;
            dq0[i % 2][j] = (dq0[i % 2][j] % MOD + MOD) % MOD;
        }

        mint t = 0;
        FOR(j, M + 1, 2 * M + 1) t += dp0[i % 2][j];
        (ans += (t % MOD) * Q[n - i]) %= MOD;
    }

    Out(ans);

    return 0;
}