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
        using namespace std::chrono;
        srand(duration_cast<nanoseconds>(high_resolution_clock::now().time_since_epoch()).count()); 
    }
    ~init() {
        cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";
    }
} init;

const int MAXN = 1e5 + 1;
                                                                                                                                                        #define int ll
int a[MAXN];
int ans[MAXN];
int sum[MAXN];
int32_t main() {

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        int v2 = std::lower_bound(a + 1, a + i + 1, a[i] - 89) - a;
        int a2 = max(0LL, 50 - (sum[i - 1] - sum[v2 - 1]));
        int v3 = std::lower_bound(a + 1, a + i + 1, a[i] - (1440 - 1)) - a;
        int a3 = max(0LL, 120 - (sum[i - 1] - sum[v3 - 1]));
        int a1 = 20;
        dbg(i, a1, a2, a3, v2, v3);
        ans[i] = min({a1, a2, a3});
        sum[i] = ans[i] + sum[i - 1];
        cout << ans[i] << '\n';
    }



    return 0;
}