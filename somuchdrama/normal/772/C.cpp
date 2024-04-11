#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#include <bits/stdc++.h>
using std::cerr;using std::cin;using std::cout;using std::abs;using std::min;using std::max;using std::swap;using std::map;using std::pair;using std::set;using std::string;using std::vector;
using ll = long long;using uint = unsigned int;using pii = pair<int, int>;using pll = pair<ll, ll>;using std::gcd;using std::lcm;
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

ll rev(ll a, ll m) {
    if (a == 1) return 1;
    return (1 - rev(m % a, a) * m) / a + m;
}

const int MAXN = 3e5;

vector<int> g[MAXN];
int a[MAXN];
set<int> s[MAXN];
int dp[MAXN];
int from[MAXN];
int32_t main() {
    
    int n, m;
    cin >> n >> m;

    set<int> booms;
    for (int i = 0; i < m; ++i) {
        int g = gcd(i, m);
        booms.insert(g);
        s[g].insert(i);
    }

    vector<int> boom(booms.begin(), booms.end());

    for (int i = 0; i < boom.size(); ++i)
        for (int j = i + 1; j < boom.size(); ++j)
            if (boom[j] % boom[i] == 0)
                g[boom[i]].pb(boom[j]);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        s[gcd(m, a[i])].erase(a[i]);
    }

    reverse(boom.begin(), boom.end());

    dp[m] = s[m].size();
    for (int i : boom) {
        for (int to : g[i]) {
            if (dp[i] < s[i].size() + dp[to]) {
                dp[i] = s[i].size() + dp[to];
                from[i] = to;
            }
        }
    }

    int v = std::max_element(dp, dp + m) - dp;
    
    if (v == 0) v = 1;

    cout << dp[v] << '\n';

    int prev = 1;
    while (v) {
        for (int i : s[v]) {
            int g = gcd(prev, m);
            assert(i % g == 0);
            int x = ((i / g * rev(prev / g, m / g))) % (m / g);
            cout << x << ' ';
            dbg(prev, i, g, x);
            prev = i;
        }
        v = from[v];
    }

    cout << '\n';

    return 0;
}