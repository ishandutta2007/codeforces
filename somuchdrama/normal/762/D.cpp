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
        srand(228); 
    }
    ~init() {
        cerr << "Time elapsed: " << 1.0 * (double)clock() / CLOCKS_PER_SEC << "s.\n";
    }
} init;

const int MAXN = 1e5 + 15;
const ll INF = 1e16;
ll a[MAXN][3];
ll dp[MAXN][3][2];

int main() {

    int n;
    cin >> n;
    for (int i = 0; i <= n; ++i)
        for(int j = 0; j < 3; ++j) 
            for (int k = 0; k < 2; ++k)
                dp[i][j][k] = -INF;    

    for (int i = 0; i < 3; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> a[j][i];


    a[0][1] = a[0][2] = -INF;
    dp[0][0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        dp[i][0][0] = max({
                            dp[i - 1][0][0] + a[i][0], 
                            dp[i - 1][1][0] + a[i - 1][0] + a[i][0],
                            dp[i - 1][2][0] + a[i - 1][1] + a[i - 1][0] + a[i][0],
                            i > 1 ? dp[i - 1][2][1] + a[i - 1][1] + a[i - 2][1] + a[i - 2][0] + a[i - 1][0] + a[i][0] : -INF
                        });
        dp[i][0][1] = dp[i - 1][0][0] + a[i][0];
        dp[i][1][0] = max({
                            dp[i - 1][0][0] + a[i - 1][1] + a[i][1],
                            dp[i - 1][1][0] + a[i][1],
                            dp[i - 1][2][0] + a[i - 1][1] + a[i][1]
                        });
        dp[i][1][1] = -INF;
        dp[i][2][0] = max({
                            dp[i - 1][0][0] + a[i - 1][1] + a[i - 1][2] + a[i][2],
                            dp[i - 1][1][0] + a[i - 1][2] + a[i][2],
                            dp[i - 1][2][0] + a[i][2],
                            i > 1 ? dp[i - 1][0][1] + a[i - 1][1] + a[i - 2][1] + a[i - 2][2] + a[i - 1][2] + a[i][2] : -INF
                        });
        dp[i][2][1] = dp[i - 1][2][0] + a[i][2];
        for (int j = 0; j < 3; ++j)
            dbg(i, j, dp[i][j][0], dp[i][j][1]);
    }
    ll ans = max({
                dp[n][0][0] + a[n][1] + a[n][2],
                dp[n][1][0] + a[n][2],
                dp[n][2][0],
                dp[n][0][1] + a[n][1] + a[n - 1][1] + a[n - 1][2] + a[n][2]
            }); 
    cout << ans << '\n';


    return 0;
}