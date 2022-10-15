//   

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
const ll MOD = 1e9 + 7;
ll binpow(ll a, ll pw) {
    ll res(1);
    for (; pw; a = (a * a) % MOD, pw /= 2, res %= MOD) 
        res *= (pw & 1) * (a - 1) + 1;
    return res;
}

const int MAXN = 1e5;
set<int> g[2][MAXN];
vector<int> crd[2];
int a[MAXN][2], c = 0;
bool used[2][MAXN];
set<int> pts;
vector<int> at[2][MAXN];
void dfs(int t, int v) {
    used[t][v] = 1;
    c++;
    for (int i : at[t][v])
        pts.insert(i);
    for (int to : g[t][v])
        if (!used[t ^ 1][to])
            dfs(t ^ 1, to);
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            cin >> a[i][j];
            crd[j].pb(a[i][j]);
        }
    }

    for (int j = 0; j < 2; ++j) {
        sort(crd[j].begin(), crd[j].end());
        crd[j].resize(unique(crd[j].begin(), crd[j].end()) - crd[j].begin());
    }

    for (int i = 0; i < n; ++i) {
        int x = lower_bound(crd[0].begin(), crd[0].end(), a[i][0]) - crd[0].begin();
        int y = lower_bound(crd[1].begin(), crd[1].end(), a[i][1]) - crd[1].begin();
        g[0][x].insert(y);
        g[1][y].insert(x);
        at[0][x].pb(i);
        at[1][y].pb(i);
    }
    ll ans = 1;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 2; ++j)
            if (!used[j][i]) {
                pts.clear();
                c = 0;
                dfs(j, i);
                if (c <= pts.size())
                    ans *= binpow(2, c);
                else
                    ans *= binpow(2, c) - 1;
                ans %= MOD;
            }
    cout << ans << '\n';

    return 0;
}