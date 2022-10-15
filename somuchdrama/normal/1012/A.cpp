#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#include <bits/stdc++.h>
using std::cerr;using std::cin;using std::cout;using std::abs;using std::min;using std::max;using std::swap;using std::map;using std::pair;using std::set;using std::string;using std::vector;
using ll = long long;using uint = unsigned int;using pii = pair<int, int>;using pll = pair<ll, ll>;
#define ff first
#define ss second
#define pb emplace_back
template<typename T> void _dbg(const char* _s,T _h){cerr<<_s<<" = "<<_h <<"\n";}
template<typename T,typename... Ts>void _dbg(const char* _s,T _h,Ts... _t){int _b = 0;while(((_b+=*_s=='(')-=*_s==')')!=0||*_s!=',')cerr<<*_s++;cerr<<" = "<<_h<<",";_dbg(_s+1,_t...);}
#ifdef LOCAL
#define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 
#endif

struct init { init() {cin.tie(0);std::iostream::sync_with_stdio(0);cout << std::fixed << std::setprecision(10);cerr << std::fixed << std::setprecision(5);}~init() {
        #ifdef LOCAL
        cerr << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC << "s.\n";
        #endif
}} init;


const int MAXN =2e5 + 1;
ll a[MAXN];
int32_t main() {

    int n; 
    cin >> n;
    for (int i = 0; i < n + n; ++i) {
        cin >> a[i];
    }
    std::sort(a, a + n + n);
    ll ans = (a[n - 1] - a[0]) * (a[n + n - 1] - a[n]);
    for (int i = 1; i < n; ++i) {
        ll pot = (a[n + n - 1] - a[0]) * (a[i + n - 1] - a[i]);
        if (pot < ans)
            ans = pot;
    }

    cout << ans << '\n';


    return 0;
}