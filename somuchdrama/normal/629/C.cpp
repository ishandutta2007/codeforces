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

const int MAXN = 2018;
const ll MOD = 1e9 + 7;
ll dp[MAXN][MAXN];

int main() {
    int n, m;
    string s;
    cin >> n >> m >> s;

    dp[0][0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        for (int j = 0; j < MAXN - 1; ++j) {
            if (j > 0)
                dp[i][j] += dp[i - 1][j - 1];
            dp[i][j] += dp[i - 1][j + 1];
            dp[i][j] %= MOD;
        }
    }

    int sbal = 0, mn = 0;
    for (char c : s) {
        if (c == '(') ++sbal; 
        else --sbal;
        if (mn > sbal)
            mn = sbal;
    }

    ll ans = 0;
    for (int p = 0; p + m <= n; ++p) {
        for (int pbal = max(0, -mn); pbal <= p; ++pbal) {
            int q = n - m - p, qbal = pbal + sbal;
            if (qbal >= MAXN) continue;
            ans += (dp[p][pbal] * dp[q][qbal]) % MOD;
            ans %= MOD;
        }
    }

    cout << ans << '\n';

    return 0;
}