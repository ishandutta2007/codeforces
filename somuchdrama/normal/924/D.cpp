//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#include <bits/stdc++.h>

using std::cerr;
using std::cin;
using std::cout;

using std::abs;
using std::min;
using std::max;
using std::swap;

using std::map;
using std::pair;
using std::set;
using std::string;
using std::vector;

using ll = long long;
using uint = unsigned int;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define ff first
#define ss second
#define pb emplace_back
template<typename T> 
void _dbg(const char* _s, T _h) {
    cerr << _s << " = " << _h <<"\n"; 
}
template<typename T, typename... Ts>
void _dbg(const char* _s, T _h, Ts... _t) {
    int _b = 0;
    while (((_b += *_s == '(') -= *_s == ')') != 0 || *_s != ',')
        cerr << *_s++; 
    cerr << " = " << _h << ","; 
    _dbg(_s+1, _t...);
}
#ifdef LOCAL
#define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 
#endif

struct init {
    init() {
        cin.tie(0);
        std::iostream::sync_with_stdio(0);
        cout << std::fixed << std::setprecision(10);
        cerr << std::fixed << std::setprecision(5);
    }
    ~init() {
        #ifdef LOCAL
        cerr << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC << "s.\n";
        #endif
    }
} init;


const int MAXN = 1e5;
struct meow{
    ll x, v, i;
} a[MAXN];
ll wind;
bool operator < (const meow& p1, const meow& p2) {
    ll r1 = abs(p1.x) * abs(p2.v);
    ll r2 = abs(p2.x) * abs(p1.v);
    return r1 < r2;
}
// bool comp2(const meow& p1, const meow& p2) {
//     ll r1 = abs(p1.x) * abs(p2.v);
//     ll r2 = abs(p2.x) * abs(p1.v);
//     // return r1 < r2;
//     return r1 == r2 ? p1.v < p2.v : r1 < r2;
// }

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using ordered_set = tree<pii, null_type, std::greater<pii>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {

    int n;
    cin >> n >> wind;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].x >> a[i].v;
        a[i].i = i;
    }

    for (int i = 0; i < n; ++i) {
        a[i].v += wind;
    }
    std::sort(a, a + n);
    int num = 0;
    for (int i = 0; i < n; ++i) {
        num += (i && a[i - 1] < a[i]);
        a[i].i = num;
        dbg(a[i].x, a[i].v, a[i].i, num);
    }
    for (int i = 0; i < n; ++i) {
        a[i].v -= 2 * wind;
    }
    std::reverse(a, a + n);
    std::stable_sort(a, a + n);
    ordered_set s;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        int x = a[i].i;
        int add = s.order_of_key({x, -1});
        ans += add;
        s.insert({x, i});
    }

    cout << ans << '\n';


    return 0;
}