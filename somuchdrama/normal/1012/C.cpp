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


const int MAXN = 5018, INF = 1e9;
int a[MAXN];
pii aaa[MAXN][2];
pii bbb[MAXN][2];
int ans[MAXN];

std::ostream & operator <<(std::ostream & os, pii & p) {
    return os << '(' << p.ff << ' ' << p.ss << ')';
}

void up0(pii & p, pii q) {
    if (p.ff > q.ff || (p.ff == q.ff && p.ss > q.ss)) {
        p = q;
    }
}

int32_t main() {

    int n; 
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    a[n + 1] = -INF;

    auto dp = aaa, dq = bbb;
    for (int k = 0; k <= n; ++k) {
        ans[k] = INF;
        dp[k][0] = dp[k][1] = {INF, INF};
    }

    dp[0][0] = {0, -INF};

    for (int i = 1; i <= n + 1; ++i) {
        swap(dp, dq);
        for (int k = 0; k <= (i + 1) / 2; ++k) {
            dp[k][0] = {dq[k][0].ff, a[i]};
            int delta = max(0, a[i] - dq[k][1].ss + 1);
            dbg(delta);
            up0(dp[k][0], {dq[k][1].ff + delta, a[i] - delta});
            if (k) {
                delta = max(0, dq[k - 1][0].ss - a[i] + 1);
                dp[k][1] = {dq[k - 1][0].ff + delta, a[i]};
            }
            ans[k] = min(ans[k], dp[k][0].ff);
            dbg(i, k, dp[k][0], dp[k][1]);
        }
    }

    for (int i = 1; i <= (n + 1) / 2; ++i)
        cout << ans[i] << ' ';
    cout << '\n';


    return 0;
}