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

const int MAXN = 1e5 + 2, KAL = 35, LOG = 17;
int a[MAXN];
int go[KAL][LOG][MAXN];

int main() {

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int k = 1; k < KAL; ++k) {
        for (int i = 1; i <= n; ++i) 
            go[k][0][i] = min(k + i + a[i], n + 1);
        for (int j = 0; j < LOG; ++j)
            go[k][j][n + 1] = n + 1;
        for (int j = 1; j < LOG; ++j) 
            for (int i = 1; i <= n; ++i) 
                go[k][j][i] = go[k][j - 1][go[k][j - 1][i]];
    }

    int q;
    cin >> q;
    while (q--) {
        int p, k;
        cin >> p >> k;
        int ans = 0;
        if (k < KAL) {
            for (int i = LOG - 1; i >= 0; --i)
                if (go[k][i][p] <= n) {
                    ans += 1 << i;
                    p = go[k][i][p];
                }
            ++ans;
        } else {
            for (; p <= n; p += a[p] + k, ++ans);
        }
        cout << ans << '\n';
    }

    return 0;
}