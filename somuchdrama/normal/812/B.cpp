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


const int MAXN = 111;
char f[MAXN][MAXN];
int ft[MAXN];
int lt[MAXN];
int dp[MAXN][2];

int main() {
    int n, m;
    cin >> n >> m;
    int nn = -1;
    for (int i = n; i > 0; --i) {
        ft[i] = lt[i] = -1;
        for (int j = 0; j <= m + 1; ++j) {
            cin >> f[i][j];
            if (f[i][j] == '1') {
                if (ft[i] == -1)
                    ft[i] = j;
                lt[i] = j;
            }
        }
        if (nn == -1 && ft[i] != -1)
            nn = i;
    }

    if (nn == -1) {
        cout << "0\n";
        return nn + 1;
    }

    dp[0][0] = -1;
    dp[0][1] = m;
    for (int i = 1; i < nn; ++i) {
        if (ft[i] == -1) {
            dp[i][0] = dp[i - 1][0] + 1;
            dp[i][1] = dp[i - 1][1] + 1;
        } else {
            dp[i][0] = min(dp[i - 1][0] + 2 * lt[i], dp[i - 1][1] + m + 1) + 1;
            dp[i][1] = min(dp[i - 1][1] + 2 * (m - ft[i] + 1), dp[i - 1][0] + m + 1) + 1;
        }
    }

    int ans = 1 + min(dp[nn - 1][0] + lt[nn], dp[nn - 1][1] + (m - ft[nn] + 1));

    cout << ans << '\n';

    return 0;
}