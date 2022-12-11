#line 1 "test.cpp"
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
//#include "atcoder/convolution.hpp"
//#include "atcoder/modint.hpp"
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
ll GCD(ll a,ll b) { if(a % b == 0) return b; else return GCD(b,a%b);}
ll LCM(ll a,ll b) { return a / GCD(a,b) * b;}
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

#line 2 "library/data-structure/unionfind.hpp"
using namespace std;
struct unionfind {
  public:
    unionfind() : _n(0) {}
    explicit unionfind(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = find(a), y = find(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return find(a) == find(b);
    }

    int find(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = find(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[find(a)];
    }

    vector<vector<int>> groups() {
        vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = find(i);
            group_size[leader_buf[i]]++;
        }
        vector<vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            remove_if(result.begin(), result.end(),
                           [&](const vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    // root node: -1 * component size
    // otherwise: parent
    vector<int> parent_or_size;
};
#line 94 "test.cpp"

int main() {
    INT(TT);
    while(TT--) {
        INT(n,m);
        vector<pii> pp;
        vi cnt(n);
        vvi g(n);
        rep(i,m) {
            INT(a,b);
            a--,b--;
            g[a].emplace_back(b);
            g[b].emplace_back(a);
            pp.emplace_back(a,b);
            cnt[a]++;
            cnt[b]++;
        }
        vi ans(m);
        unionfind uf(n);
        if(m == n + 2) {
            vi que;
            rep(i,n) {
                if(cnt[i] == 1) {
                    que.push_back(i);
                }
            }
            while(!que.empty()) {
                int now = que.back();
                que.pop_back();
                cnt[now]--;
                for(auto nex:g[now]) {
                    if(cnt[nex] > 0) {
                        cnt[nex]--;
                        if(cnt[nex] == 1) que.push_back(nex);
                    }
                }
            }
            vi se;
            set<int> see;
            int r = -1;
            debug(cnt);
            rep(i,n) {
                if (cnt[i] == 2) {
                    r = i;
                    break;
                }
            }
            if(r == -1) {
                rep(i,n) {
                    if(cnt[i] > 0) {
                        se.push_back(i);
                        see.insert(i);
                    }
                }
                sort(all(se));
                rep(i,m) {
                    int x = pp[i].first, y = pp[i].second;
                    if(x > y) swap(x,y);
                    if (see.count(x) && see.count(y)) {
                        rep(j,3) {
                            if(se[j+1] == y && se[j] == x) {
                                uf.merge(x,y);
                                ans[i] = 1;
                            }
                        }
                    }
                }
            }
            else {
                rep(i,m) {
                    if(pp[i].first == r || pp[i].second == r) {
                        int x = pp[i].first + pp[i].second - r;
                        if (cnt[x]) {
                            uf.merge(pp[i].first,pp[i].second);
                            ans[i] = 1;
                            break;
                        }
                    }  
                }
                rep(i,m) {
                    if(pp[i].first == r || pp[i].second == r) {
                        int x = pp[i].first + pp[i].second - r;
                        if(cnt[x]) continue;
                    }
                    if(!uf.same(pp[i].first,pp[i].second)) {
                        uf.merge(pp[i].first,pp[i].second); 
                        ans[i] = 1;
                    }
                }
            }               
        }
        rep(i,m) {
            if(!uf.same(pp[i].first,pp[i].second)) {
                uf.merge(pp[i].first,pp[i].second); 
                ans[i] = 1;
            }
        }
        rep(i,m) cout << ans[i];
        cout << '\n';
    }
}