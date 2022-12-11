#pragma once
#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
template<class T> using pq = priority_queue<T, vector<T>, greater<T>>;
#define overload4(_1, _2, _3, _4, name, ...) name
#define overload3(a,b,c,name,...) name
#define rep1(n) for (ll i = 0; i < (n); ++i)
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
//constexpr mod = 1000000007;
constexpr int mod = 998244353;

void solve() {
    INT(n,d12,d23,d31);
    int su = d12 + d23 + d31;
    if (d12 == 1 && d23 == 1 && d31 == 1) cout << "NO" << '\n';
    else {
        int mi = min(d12,min(d23,d31));
        if (d12 == mi) {
            int l = 1,r = 2;
            if (abs(d23 - d31) > mi || (su - 2 * mi) % 2) {
                cout << "NO" << '\n';
                return;
            }
            int xx;
            if (abs(d23 - d31) == mi) xx = max(d23,d31) - 3;
            else xx = (su + 2) / 2;
            if (xx > n) {
                cout << "NO" << '\n';
                return;
            }
            cout << "YES" << '\n';
            if (d12 == 1) {
                cout << 1 << " " << 2 << '\n';
            }
            if (d23 == 1) {
                cout << 2 << " " << 3 << '\n';
            }
            if (d31 == 1) {
                cout << 1 << " " << 3 << '\n';
            }
            int x = mi - 1;
            int pre = l;
            int dis = (su - 2 * mi) / 2;
            int prv;
            if (d23 - d31 == mi) prv = 1;
            elif (d31 - d23 == mi) prv = 2;
            else prv = 4 + ((mi - 2) + (d31 - d23)) / 2;
            if (dis == 1 && prv > 3) cout << prv << " " << 3 << '\n';
            rep(i,4,n+1) {
                if (x > 0) {
                    cout << pre << " " << i << '\n';
                    x--;
                    pre = i;
                    if (x == 0) {
                        cout << i << " " << r << '\n';
                    }
                }
                elif (dis > 1) {
                    cout << prv << " " << i << '\n';   
                    dis--;
                    prv = i;
                    if (dis == 1) {
                        cout << i << " " << 3 << '\n';
                        dis--;
                    }             
                }
                else {
                    cout << 1 << " " << i << '\n';
                }
            }
        }
        elif (d23 == mi) {
            int l = 3,r = 2;
            if (abs(d12 - d31) > mi || (su - 2 * mi) % 2) {
                cout << "NO" << '\n';
                return;
            }
            int xx;
            if (abs(d12 - d31) == mi) xx = max(d12,d31) - 3;
            else xx = (su + 2) / 2;
            if (xx > n) {
                cout << "NO" << '\n';
                return;
            }
            cout << "YES" << '\n';
            if (d12 == 1) {
                cout << 1 << " " << 2 << '\n';
            }
            if (d23 == 1) {
                cout << 2 << " " << 3 << '\n';
            }
            if (d31 == 1) {
                cout << 1 << " " << 3 << '\n';
            }
            int x = mi - 1;
            int pre = l;
            int dis = (su - 2 * mi) / 2;
            int prv;
            if (d12 - d31 == mi) prv = 3;
            elif (d31 - d12 == mi) prv = 2;
            else prv = 4 + ((mi - 2) + (d31 - d12)) / 2;
            if (dis == 1 && prv > 3) cout << prv << " " << 1 << '\n';
            rep(i,4,n+1) {
                if (x > 0) {
                    cout << pre << " " << i << '\n';
                    x--;
                    pre = i;
                    if (x == 0) {
                        cout << i << " " << r << '\n';
                    }
                }
                elif (dis > 1) {
                    cout << prv << " " << i << '\n';   
                    dis--;
                    prv = i;
                    if (dis == 1) {
                        cout << i << " " << 1 << '\n';
                        dis--;
                    }             
                }
                else {
                    cout << 1 << " " << i << '\n';
                }
            }
        }
        else {
            int l = 3,r = 1;
            if (abs(d12 - d23) > mi || (su - 2 * mi) % 2) {
                cout << "NO" << '\n';
                return;
            }
            int xx;
            if (abs(d12 - d23) == mi) xx = max(d12,d23) - 3;
            else xx = (su + 2) / 2;
            if (xx > n) {
                cout << "NO" << '\n';
                return;
            }
            cout << "YES" << '\n';
            if (d12 == 1) {
                cout << 1 << " " << 2 << '\n';
            }
            if (d23 == 1) {
                cout << 2 << " " << 3 << '\n';
            }
            if (d31 == 1) {
                cout << 1 << " " << 3 << '\n';
            }
            int x = mi - 1;
            int pre = l;
            int dis = (su - 2 * mi) / 2;
            int prv;
            if (d12 - d23 == mi) prv = 3;
            elif (d23 - d12 == mi) prv = 1;
            else prv = 4 + ((mi - 2) + (d23 - d12)) / 2;
            if (dis == 1 && prv > 3) cout << prv << " " << 2 << '\n';
            rep(i,4,n+1) {
                if (x > 0) {
                    cout << pre << " " << i << '\n';
                    x--;
                    pre = i;
                    if (x == 0) {
                        cout << i << " " << r << '\n';
                    }
                }
                elif (dis > 1) {
                    cout << prv << " " << i << '\n';   
                    dis--;
                    prv = i;
                    if (dis == 1) {
                        cout << i << " " << 2 << '\n';
                        dis--;
                    }             
                }
                else {
                    cout << 1 << " " << i << '\n';
                }
            }
        }
    }
}
int main() {
    INT(T);
    while (T--) {
        solve();
    }
}