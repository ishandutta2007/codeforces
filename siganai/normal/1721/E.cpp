//#pragma GCC target("avx")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

#ifdef LOCAL
#  include <debug.hpp>
#  define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#  define debug(...) (static_cast<void>(0))
#endif

//#include <atcoder/all>
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
ll modpow(ll a, ll b, ll p){ ll ans = 1; while(b){ if(b & 1) (ans *= a) %= p; (a *= a) %= p; b /= 2; } return ans; }
namespace IO{
#define VOID(a) decltype(void(a))
struct setting{
    setting(){
        cin.tie(nullptr); ios::sync_with_stdio(false);
        fixed(cout); cout.precision(12);
    }
} setting;
template<int I> struct P : P<I-1>{};
template<> struct P<0>{};
template<class T> void i(T& t){ i(t, P<3>{}); }
void i(vector<bool>::reference t, P<3>){ int a; i(a); t = a; }
template<class T> auto i(T& t, P<2>) -> VOID(cin >> t){ cin >> t; }
template<class T> auto i(T& t, P<1>) -> VOID(begin(t)){ for(auto&& x : t) i(x); }
template<class T, size_t... idx> void ituple(T& t, index_sequence<idx...>){
    in(get<idx>(t)...);
}
template<class T> auto i(T& t, P<0>) -> VOID(tuple_size<T>{}){
    ituple(t, make_index_sequence<tuple_size<T>::value>{});
}

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
    template <class... Args> auto operator()(Args &&...args) const { return f(*this, forward<Args>(args)...); }
};

vector<long long> divisor(long long n) {
    vector<long long> ret;
    for(long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if(i * i != n) {ret.push_back(n / i);}
        }
    }
    sort(ret.begin(),ret.end());
    return ret;
}

vector<long long> prime_fact(long long n) {
    vector<long long> ret;
    for(long long i = 2; i * i <= n; i++) {
        if (i * i > n) break;
        while(n % i == 0) {
            ret.push_back(i);
            n /= i;
        }
    }
    if (n != 1) ret.push_back(n);
    return ret;
}
template<typename Container>
vector<int> z_algorithm(Container s) {
    int n = s.size();
    vector<int> a(n);
    a[0] = n;
    int i = 1, j = 0;
    while (i < n) {
        while (i + j < n && s[j] == s[i + j]) ++j;
        a[i] = j;
        if (j == 0) {
            ++i;
            continue;
        }
        int k = 1;
        while (i + k < n && k + a[k] < j) a[i + k] = a[k], ++k;
        i += k;
        j -= k;
    }
    return a;
}



int main() {
    STR(S);
    INT(q);
    vi zal = z_algorithm(S);
    map<string,int> mp;
    int n = S.size();
    rrep(i,1,n) {
        if(zal[i] + i == n) {
            string tmps;
            int now = 0;
            rep(j,1,11) {
                if(zal[i] + j - 1 < n) tmps += S[zal[i] + j - 1];
                else {
                    tmps += tmps[now];
                    now++;
                }
                chmax(mp[tmps],zal[i] + (int)j);
            }
        }
    }
    string tmps;
    int now = 0;
    debug(mp);
    map<string,int> mp2;
    rep(i,1,11) {
        if(i - 1 < n) tmps += S[i - 1];
        else {
            tmps += tmps[now];
            now++;
        }
        chmax(mp2[tmps],(int)i);
    }
    rep(i,q) {
        STR(T);
        int ts = T.size();
        string t;
        rep(i,ts) {
            t += T[i];
            if (i > 0) cout << " ";
            int ans = 0;
            if(mp.count(t)) ans = mp[t];
            else {
                rep(j,i+1) {
                    if(mp2.count(T.substr(j,i - j + 1))) {ans = mp2[T.substr(j,i - j + 1)];break;}
                }
            }
            cout << ans;
        }
        cout << '\n';
    }
    debug(mp);
}