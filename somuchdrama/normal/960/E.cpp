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
        #ifdef LOCAL
        srand(300); 
        #else
        using namespace std::chrono;
        srand(duration_cast<nanoseconds>(high_resolution_clock::now().time_since_epoch()).count()); 
        #endif
    }
    ~init() {
        #ifdef LOCAL
        cerr << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC << "s.\n";
        #endif
    }
} init;

const int MAXN = 2e5 + 2;
const ll MOD = 1000000007;
ll a[MAXN];
vector<int> g[MAXN];
int used[MAXN];
ll d0[MAXN], d1[MAXN];

void dfs1(int v) {
    used[v] = 1;
    d0[v] = 1;
    d1[v] = 0;
    for (int to : g[v]) {
        if (!used[to]) {
            dfs1(to);
            d0[v] += d1[to];
            d1[v] += d0[to];
        }
    }
}

ll ans = 0;
int n;

void dfs2(int v, ll c0 = 0, ll c1 = 0) {
    used[v] = 2;

    ans += (((c0 - c1) * a[v]) % MOD + MOD) % MOD * (d0[v] + d1[v]);
    dbg(ans);
    ans += (n) * a[v];
    ans %= MOD;
    ans += MOD;
    ans %= MOD;

    for (int to : g[v]) {
        if (used[to] != 2) {
            dbg((d1[to] - d0[to]));
            dbg(n - d0[to] - d1[to]);
            ll upways = (((d1[to] - d0[to]) * (n - d0[to] - d1[to])) % MOD) % MOD * a[v];
            upways %= MOD;
            upways += MOD;
            upways %= MOD;

            ans += upways;
            ans %= MOD;
            ans += MOD;
            ans %= MOD;

            dbg(v, to, upways, (n - d0[to] - d1[to]), (d1[to] - d0[to]));
            dfs2(to, c1 + d1[v] - d0[to], c0 + d0[v] - d1[to]);
        }
    }
    
}

ll solve1() {
    ans = 0;
    dfs1(1);
    dfs2(1);
    return ans;
}

ll ans2 = 0;
int dfs(int v, int c, int sign = 1) {
    used[v] = c;
    int res = 1;
    for (int to : g[v]) {
        if (used[to] != c) {
            res += dfs(to, c, -sign);
        }
    }
    ans2 += ((res * a[v] * sign) % MOD + MOD) % MOD;
    ans2 %= MOD;
    return res;
}

ll solve2() {
    ans2 = 0;
    for (int i = 1; i <= n; ++i)
        dfs(i, i + 228);
    return ans2;
}

int main() {

    while(1){
    n = rand() % 10 + 1;
    dbg(n);
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        used[i] = 0;
        g[i].clear();
        a[i] = rand() % 1000000000 + 1;
        dbg(a[i]);
        cin >> a[i];
    }

    for (int i = 1; i < n; ++i) {
        int x, y;
        x = i + 1;
        y = rand() % i + 1;
        dbg(x, y);
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }

    ll x = solve1();
    cout << x << '\n';
    return 0;
    // ll y = solve2();

    // if (x != y) {
    //     dbg(x, y);
    //     break;
    // }


    // cout << ans << '\n';

    }
    return 0;
}