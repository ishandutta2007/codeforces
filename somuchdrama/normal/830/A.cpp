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

#define int ll
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
        #ifdef LOCAL
        cerr << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC << "s.\n";
        #endif
    }
} init;


const int MAXN = 2017;
ll a[MAXN], b[MAXN];
int dp[MAXN][MAXN], mn[MAXN][MAXN];
const ll INF = 1e17;

int32_t main() {

    int n, k, p;
    cin >> n >> k >> p;
    for (int i = 1; i <= n; ++i) 
        cin >> a[i];
    std::sort(a + 1, a + n + 1);

    for (int i = 1; i <= k; ++i)
        cin >> b[i];
    std::sort(b + 1, b + k + 1);

    for (int i = 1; i <= n; ++i)
        mn[i][0] = INF;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= k; ++j) {
            dp[i][j] = max(mn[i - 1][j - 1], abs(a[i] - b[j]) + abs(p - b[j]));
            mn[i][j] = min(mn[i][j - 1], dp[i][j]);
            dbg(i, j, dp[i][j]);
        }

    int ans = INF;
    for (int i = 1; i <= k; ++i)
        ans = min(ans, dp[n][i]);
    cout << ans << '\n';


    return 0;
}