#line 1 "test.cpp"
//#pragma GCC target("avx2")
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


#line 2 "library/graph/graph-template.hpp"
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
#line 3 "library/graph/TopologicalSort.hpp"
template<typename T>
vector<int>TopologicalSort(T &g) {
    int N = g.size();
    vector<int> marked(N),tmp(N),v;
    auto visit = [&](auto f,int i) -> bool {
        if(tmp[i] == 1) return false;
        if(marked[i] == 0) {
            tmp[i] = 1;
            for(auto &e:g[i]) {
                if(f(f,e) == false) return false;
            }
            marked[i] = 1;
            v.push_back(i);
            tmp[i] = 0;
        }
        return true;
    };
    for(int i = 0;i < N;i++) {
        if(marked[i] == 0) {
            if(visit(visit,i) == false) return vector<int>();
        }
    }
    reverse(v.begin(),v.end());
    return v;
}
#line 88 "test.cpp"
int main() {
    INT(TT);
    while(TT--) {
        INT(n);
        VEC(string,s,n);
        vvi g(n);
        vvi rg(n);
        rep(i,n) {
            rep(j,n) {
                if(s[i][j] == '1') {
                    g[j].emplace_back(i);
                    rg[i].emplace_back(j);
                }
            }
        }
        vector<set<int>> ss(n);
        rep(i,n) ss[i].insert(i+1);
        auto ret = TopologicalSort(g);
        rrep(i,n) {
            for(auto &nex:rg[ret[i]]) {
                for(auto &x:ss[ret[i]]) ss[nex].insert(x);
            }
        }
        rep(i,n) {
            cout << ss[i].size();
            for(auto &x:ss[i]) cout << " " << x;
            cout << '\n';
        }
    }

}