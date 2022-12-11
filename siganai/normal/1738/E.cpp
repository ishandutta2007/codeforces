#line 1 "test.cpp"
//#pragma GCC target("avx")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#ifdef LOCAL
#include <debug.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif
//#include "atcoder/string.hpp"
//#include "atcoder/mincostflow.hpp"
//#include "atcoder/maxflow.hpp"
using namespace std;
//using namespace atcoder;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vvvl = vector<vvl>;
using vs = vector<string>;
template<class T> using pq = priority_queue<T, vector<T>, greater<T>>;
#define overload4(_1, _2, _3, _4, name, ...) name
#define overload3(a,b,c,name,...) name
#define rep1(n) for (ll UNUSED_NUMBER = 0; UNUSED_NUMBER < (n); ++UNUSED_NUMBER)
#define rep2(i, n) for (ll i = 0; i < (n); ++i)
#define rep3(i, a, b) for (ll i = (a); i < (b); ++i)
#define rep4(i, a, b, c) for (ll i = (a); i < (b); i += (c))
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define rrep1(n) for(ll i = (n) - 1;i >= 0;i--)
#define rrep2(i,n) for(ll i = (n) - 1;i >= 0;i--)
#define rrep3(i,a,b) for(ll i = (b) - 1;i >= (a);i--)
#define rrep4(i,a,b,c) for(ll i = (a) + ((b)-(a)-1) / (c) * (c);i >= (a);i -= c)
#define rrep(...) overload4(__VA_ARGS__, rrep4, rrep3, rrep2, rrep1)(__VA_ARGS__)
#define all1(i) begin(i) , end(i)
#define all2(i,a) begin(i) , begin(i) + a
#define all3(i,a,b) begin(i) + a , begin(i) + b
#define all(...) overload3(__VA_ARGS__, all3, all2, all1)(__VA_ARGS__)
#define sum(...) accumulate(all(__VA_ARGS__),0LL)
template<class T> bool chmin(T &a, const T &b){ if(a > b){ a = b; return 1; } else return 0; }
template<class T> bool chmax(T &a, const T &b){ if(a < b){ a = b; return 1; } else return 0; }
template<class T> auto min(const T& a){ return *min_element(all(a)); }
template<class T> auto max(const T& a){ return *max_element(all(a)); }
template<class... Ts> void in(Ts&... t);
#define elif else if
#define vec(type,name,...) vector<type> name(__VA_ARGS__)
#define vv(type,name,h,...) vector<vector<type>>name(h,vector<type>(__VA_ARGS__))
#define INT(...) int __VA_ARGS__; in(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__; in(__VA_ARGS__)
#define STR(...) string __VA_ARGS__; in(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__; in(__VA_ARGS__)
#define DBL(...) double __VA_ARGS__; in(__VA_ARGS__)
#define LD(...) ld __VA_ARGS__; in(__VA_ARGS__)
#define VEC(type, name, size) vector<type> name(size); in(name)
#define VV(type, name, h, w) vector<vector<type>> name(h, vector<type>(w)); in(name)
ll intpow(ll a, ll b){ ll ans = 1; while(b){if(b & 1) ans *= a; a *= a; b /= 2;} return ans;}
ll modpow(ll a, ll b, ll p){ ll ans = 1; a %= p;while(b){ if(b & 1) (ans *= a) %= p; (a *= a) %= p; b /= 2; } return ans; }
ll GCD(ll a,ll b) { if(a == 0 || b == 0) return a + b; if(a % b == 0) return b; else return GCD(b,a%b);}
ll LCM(ll a,ll b) { if(a == 0) return b; if(b == 0) return a;return a / GCD(a,b) * b;}
namespace IO{
#define VOID(a) decltype(void(a))
struct setting{ setting(){cin.tie(nullptr); ios::sync_with_stdio(false);fixed(cout); cout.precision(12);}} setting;
template<int I> struct P : P<I-1>{};
template<> struct P<0>{};
template<class T> void i(T& t){ i(t, P<3>{}); }
void i(vector<bool>::reference t, P<3>){ int a; i(a); t = a; }
template<class T> auto i(T& t, P<2>) -> VOID(cin >> t){ cin >> t; }
template<class T> auto i(T& t, P<1>) -> VOID(begin(t)){ for(auto&& x : t) i(x); }
template<class T, size_t... idx> void ituple(T& t, index_sequence<idx...>){
    in(get<idx>(t)...);}
template<class T> auto i(T& t, P<0>) -> VOID(tuple_size<T>{}){
    ituple(t, make_index_sequence<tuple_size<T>::value>{});}
#undef VOID
}
#define unpack(a) (void)initializer_list<int>{(a, 0)...}
template<class... Ts> void in(Ts&... t){ unpack(IO :: i(t)); }
#undef unpack
//constexpr int mod = 1000000007;
constexpr int mod = 998244353;
static const double PI = 3.1415926535897932;
template <class F> struct REC {
    F f;
    REC(F &&f_) : f(forward<F>(f_)) {}
    template <class... Args> auto operator()(Args &&...args) const { return f(*this, forward<Args>(args)...); }};

#line 2 "library/Modint.hpp"
template <int mod>
struct Modint{
    int x;
    Modint():x(0) {}
    Modint(long long y): x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}
    Modint &operator += (const Modint &p) {
        if((x += p.x) >= mod) x -= mod;
        return *this;}
    Modint &operator -= (const Modint &p) {
        if ((x += mod - p.x) >= mod) x -= mod;
        return *this;}
    Modint &operator *= (const Modint &p) {
        x = (int)(1LL * x * p.x % mod);
        return *this;}
    Modint &operator /= (const Modint &p) {
        *this *= p.inverse();
        return *this;}
    Modint operator -() const{return Modint(-x);}
    Modint operator +(const Modint &p) const {return Modint(*this) += p;}
    Modint operator -(const Modint &p) const {return Modint(*this) -= p;}
    Modint operator *(const Modint &p) const {return Modint(*this) *= p;}
    Modint operator /(const Modint &p) const {return Modint(*this) /= p;}
    Modint &operator ++() {if(x == mod - 1) x = 0; else x++; return *this;}
    Modint &operator --() {if(x == 0) x = mod - 1; else x--; return *this;} 
    bool operator == (const Modint &p) const {return x == p.x;}
    bool operator != (const Modint &p) const {return x != p.x;}
    Modint inverse() const {
        int a = x, b = mod, u = 1, v = 0, t;
        while (b > 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return Modint(u);}
    Modint pow(long long n) const {
        Modint ret(1), mul(x);
        while (n > 0) {
            if (n & 1) ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;}
    friend ostream &operator<<(ostream &os, const Modint &p) { return os << p.x; }
    friend istream &operator>>(istream &is, Modint &a) {
        long long t;
        is >> t;
        a = Modint<mod>(t);
        return (is);
    }
    static constexpr int get_mod() {return mod;}
};
#line 92 "test.cpp"
using mint = Modint<mod>;
using vm = vector<mint>;
using vvm = vector<vm>;
using vvvm = vector<vvm>;
vector<mint> fact, fact_inv;
void make_fact(int n){
    fact.resize(n+1), fact_inv.resize(n+1);
    fact[0] = mint(1); rep(i,1,n+1) fact[i] = fact[i-1] * mint(i);
    fact_inv[n] = fact[n].inverse(); rrep(i,0,n) fact_inv[i] = fact_inv[i+1] * mint(i+1);
}
mint ncr(int n, int r){ if(n < 0 || r < 0 || n < r) return mint(0); return fact[n] * fact_inv[r] * fact_inv[n-r];}
mint npr(int n, int r){ if(n < 0 || r < 0 || n < r) return mint(0); return fact[n] * fact_inv[n-r]; }
int main() {
    make_fact(100100);
    INT(TT);
    while(TT--) {
        INT(n);
        VEC(int,a,n);
        ll sa = sum(a);
        if(sa == 0) {
            cout << modpow(2,n-1,mod) << '\n';
            continue;
        }
        vl cs(n+1);
        rep(i,n) cs[i+1] = cs[i] + a[i];
        map<ll,int> mp1,mp2;
        rep(i,1,n+1) {
            if(cs[i] * 2 > sa) break;
            mp1[cs[i]]++;
        }
        rrep(i,1,n) {
            if((cs[n] - cs[i]) * 2 > sa) break;
            mp2[cs[n] - cs[i]]++;
        }
        debug(mp1,mp2);
        mint ans = 1;
        for(auto &x:mp1) {
            if(mp2.find(x.first) != mp2.end()) {
                int y = mp2[x.first];
                mint tmp = 0;
                if(x.first * 2 < sa) {
                    rep(i,min(x.second,y)+1) {
                        tmp += ncr(x.second,i) * ncr(y,i);
                    }
                }
                else {
                    tmp = modpow(2,y,mod);
                }
                ans *= tmp;
            }
        }
        cout << ans << '\n';
    }
}