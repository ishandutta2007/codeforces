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

vector<int> z_algorithm(vector<int> A){
    int N = A.size();
    vector<int> Z(N);
    Z[0] = N;
    int i = 1, j = 0;
    while(i < N){
        while(i + j < N && A[j] == A[i + j]) j++;
        Z[i] = j;
        if(j == 0) { i++; continue; }
        int k = 1;
        while(i + k < N && k + Z[k] < j){
            Z[i + k] = Z[k];
            k++;
        }
        i += k; j -= k;
    }
    return Z;
}

vector<int> z_algorithm(string S){
    int N = S.size();
    vector<int> A(N);
    for(int i = 0; i < N; i++) A[i] = (int)S[i];
    return z_algorithm(A);
}

signed main(){

    int n, q; cin >> n >> q;
    string s0; cin >> s0;
    string t; cin >> t;

    mvec pow2(n + 1);
    REP(i, n + 1) pow2[i] = pow((mint)2, i);
    mvec invpow2(n + 1);
    invpow2[n] = (mint)1 / pow2[n];
    IREP(i, n) invpow2[i] = invpow2[i + 1] * 2;

    mmat SS(26, mvec(n + 1, 0));
    REP(i, n) SS[t[i] - 'a'][i + 1] += invpow2[i + 1];
    REP(a, 26){
        REP(i, n) SS[a][i + 1] += SS[a][i];
    }

    string s = s0;
    vec L({SZ(s)});
    REP(i, SZ(t)){
        s = s + t[i] + s;
        L.pb(SZ(s));
        if(SZ(s) >= 1000000) break;
    }

    REP(_, q){
        int k; cin >> k;
        string w; cin >> w;

        mint ans = 0;
        if(SZ(w) <= L[min(k, SZ(L) - 1)]){
            int u = Lower_bound(L, SZ(w));
            string s1 = s.substr(0, L[u]);

            string T1 = w + s1;
            Reverse(w); Reverse(s1);
            string T2 = w + s1;
            vec Z1 = z_algorithm(T1);
            vec Z2 = z_algorithm(T2);
            Reverse(w); Reverse(s1);

            REP(i, SZ(s1) + 1){
                if(i + SZ(w) <= SZ(s1)){
                    if(Z1[i + SZ(w)] >= SZ(w)) ans += pow2[k - u];
                }else{
                    int nl = SZ(s1) - i, nr = SZ(w) - nl - 1;
                    if((nl == 0 || Z1[i + SZ(w)] >= nl) && (nr == 0 || Z2[SZ(w) + SZ(s1) - nr] >= nr)){
                        int a = w[nl] - 'a';
                        ans += (SS[a][k] - SS[a][u]) * pow2[k];
                    } 
                }
            }
        } 
        cout << ans << '\n';
    }

    return 0;
}