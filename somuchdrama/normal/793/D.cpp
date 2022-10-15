#pragma GCC optimize("O3")
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
#define sqr(x) ((x) * (x))
#ifdef LOCAL
#define dbg(as...) {\
    vector<string> _v; \
    std::stringstream _ss(#as);\
    string _cur, _loc;\
    while (getline(_ss, _cur, ',')) {\
        while (count(_cur.begin(), _cur.end(), '(') != count(_cur.begin(), _cur.end(), ')')) {\
            getline(_ss, _loc, ',');\
            _cur += "," + _loc;\
        }\
    _v.pb(_cur);\
    }\
    err(_v.begin(), as);\
}
#else
#define dbg(as...)
#endif

template<typename T>
void err(vector<string>::iterator it, T a) {
    cerr << it->substr((*it)[0] == ' ') << " = " << a << '\n';
}
template<typename T, typename...Ts>
void err(vector<string>::iterator it, T a, Ts...as) {
    cerr << it->substr((*it)[0] == ' ') << " = " << a << ", ";
    err(++it, as...);
}

struct init {
    init() {
        cin.tie(0);
        std::iostream::sync_with_stdio(0);
        cout << std::fixed << std::setprecision(10);
        cerr << std::fixed << std::setprecision(10);
        #ifdef LOCAL
        srand(300); 
        #else
        srand(time(0));
        #endif
    }
    ~init() {
        cerr << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC << "s.\n";
    }
} init;

const int MAXN = 81, INF = 1e9;
int dp[MAXN][MAXN][MAXN][2];
vector<pii> g[MAXN];
int solve(int l, int r, int k, bool w) {
    if (dp[l][r][k][w] != -1) return dp[l][r][k][w];
    if (k == 0) return dp[l][r][k][w] = 0;
    dp[l][r][k][w] = INF;
    if (!w) { // l
        for (pii p : g[l]) {
            int to = p.ff, cost = p.ss;
            int pot = INF;
            if (to < l) {
                pot = solve(to, r, k - 1, 0) + cost;
            } else if (to > r) {
                pot = solve(l, to, k - 1, 1) + cost;
            }
            if (dp[l][r][k][w] > pot)
                dp[l][r][k][w] = pot;
        }
    } else {
        for (pii p : g[r]) {
            int to = p.ff, cost = p.ss;
            int pot = INF;
            if (to > r) {
                pot = solve(l, to, k - 1, 1) + cost;
            } else if (to < l) {
                pot = solve(to, r, k - 1, 0) + cost;
            }
            if (dp[l][r][k][w] > pot)
                dp[l][r][k][w] = pot;
        }
    }
    dbg(l, r, k , w, dp[l][r][k][w]);
    return dp[l][r][k][w];
}

int main() {
    int n, k, m;
    cin >> n >> k >> m;;

    for (int l = 1; l <= n; ++l)
        for (int r = 1; r <= n; ++r)
            for (int i = 0; i <= k; ++i)
                for (int w = 0; w < 2; ++w)
                    dp[l][r][i][w] = -1;

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        g[b].pb(a, c);
    }

    int ans = INF;

    for (int l = 1; l <= n; ++l)
        ans = min(ans, solve(l, l, k-1, 0));

    if (ans == INF) ans = -1;
    cout << ans << '\n';

    return 0;
}