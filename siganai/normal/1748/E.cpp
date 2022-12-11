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
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll,ll>;
using pii = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vvvl = vector<vvl>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using vs = vector<string>;
template<class T> using pq = priority_queue<T,vector<T>,greater<T>>;
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
#define all1(i) begin(i),end(i)
#define all2(i,a) begin(i),begin(i)+a
#define all3(i,a,b) begin(i)+a,begin(i)+b
#define all(...) overload3(__VA_ARGS__, all3, all2, all1)(__VA_ARGS__)
#define sum(...) accumulate(all(__VA_ARGS__),0LL)
template<class T> bool chmin(T &a, const T &b){ if(a > b){ a = b; return 1; } else return 0; }
template<class T> bool chmax(T &a, const T &b){ if(a < b){ a = b; return 1; } else return 0; }
template<class T> auto min(const T& a){ return *min_element(all(a)); }
template<class T> auto max(const T& a){ return *max_element(all(a)); }
template<class... Ts> void in(Ts&... t);
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
constexpr int mod = 1000000007;
//constexpr int mod = 998244353;
static const double PI = 3.1415926535897932;
template <class F> struct REC {
    F f;
    REC(F &&f_) : f(forward<F>(f_)) {}
    template <class... Args> auto operator()(Args &&...args) const { return f(*this, forward<Args>(args)...); }};

#line 3 "library/tree/CartesianTree.hpp"
using namespace std;
#line 3 "library/graph/graph-template.hpp"
using namespace std;
template <typename T> 
struct Edge {
	int from, to;
	T cost;
	Edge() = default;
	Edge(int _to, T _cost) : from(-1), to(_to), cost(_cost) {}
	Edge(int _from, int _to, T _cost) : from(_from), to(_to), cost(_cost) {}
	bool operator < (const Edge &a) const { return cost < a.cost; }
	bool operator > (const Edge &a) const { return cost > a.cost; }
    Edge &operator = (const int &x) {
        to = x;
        return *this;
    }
    operator int() const { return to; }
    friend ostream operator<<(ostream &os, Edge &edge) { return os << edge.to; }
};
 
template <typename T>
using Edges = vector<Edge<T>>;
template <typename T>
using Wgraph = vector<Edges<T>>;
using Ugraph = vector<vector<int>>;
Ugraph uinput(int N, int M = -1, bool is_directed = false, int origin = 1) {
    Ugraph g(N);
    if (M == -1) M = N - 1;
    while(M--) {
        int a,b;
        cin >> a >> b;
        a -= origin, b -= origin;
        g[a].push_back(b);
        if(!is_directed) g[b].push_back(a);
    }
    return g;
}
template <typename T>
Wgraph<T> winput(int N, int M = -1, bool is_directed = false,int origin = 1) {
    Wgraph<T> g(N);
    if (M == -1) M = N - 1;
    while(M--) {
        int a,b;
        T c;
        cin >> a >> b >> c;
        a -= origin, b -= origin;
        g[a].emplace_back(b,c);
        if(!is_directed) g[b].emplace_back(a,c);
    }
    return g;
}
#line 5 "library/tree/CartesianTree.hpp"
// return value : pair<graph, root>
template <typename T>
pair<vector<vector<int>>,int> CartesianTree(vector<T> &a,bool is_min) {
    int N = (int)a.size();
    vector<vector<int>> g(N);
    vector<int> p(N,-1), st;
    st.reserve(N);
    for (int i = 0;i < N;i++) {
        int prv = -1;
        if(is_min) while (!st.empty() && a[i] < a[st.back()]) {
            prv = st.back();
            st.pop_back();
        }
        else while (!st.empty() && a[i] > a[st.back()]) {
            prv = st.back();
            st.pop_back();
        }
        if (prv != -1) p[prv] = i;
        if (!st.empty()) p[i] = st.back();
        st.push_back(i);
    }
    int root = -1;
    for (int i = 0;i < N;i++) {
        if (p[i] != -1)
        g[p[i]].push_back(i);
        else
        root = i;
    }
    return make_pair(g, root);
}
#line 2 "library/modint/Modint.hpp"
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
#line 88 "test.cpp"
using mint = Modint<mod>;
using vm = vector<mint>;
using vvm = vector<vm>;
using vvvm = vector<vvm>;
int main() {
    INT(TT);
    while(TT--) {
        INT(n,m);
        VEC(int,a,n);
        vvi g;
        int root;
        tie(g,root) = CartesianTree<int>(a,false);
        vvm dp(n,vm(m));
        vvm cs(n,vm(m+1));
        auto dfs = REC([&](auto f,int now) -> void {
            for(auto &nex:g[now]) {
                f(nex);
            }
            rep(i,m) {
                mint tmp = 1;
                for(auto &nex:g[now]) {
                    if(nex < now) tmp *= cs[nex][i];
                    else tmp *= cs[nex][i+1];
                }
                dp[now][i] = tmp;
            }
            rep(i,m) cs[now][i+1] = cs[now][i] + dp[now][i];
        });
        dfs(root);
        cout << cs[root][m] << '\n';
    }
}