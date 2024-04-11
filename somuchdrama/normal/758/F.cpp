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

const int C = 33, KAL = 3333, MX = 1e9;
ll pws[C][KAL];

int main() {
    int n, l, r;
    cin >> n >> l >> r;
    ll ans(0);
    if (n == 1) 
        ans = r - l + 1;
    else if (n == 2)
        ans = (r - l) * 1LL * (r - l + 1);
    else if (n >= C) 
        ans = 0;
    else {
        for (int i = 1; i < KAL; ++i) {
            pws[0][i] = 1;
            for (int j = 1; j < n; ++j) {
                pws[j][i] = pws[j - 1][i] * i;
                if (pws[j][i] > MX) pws[j][i] = MX;
            }
        }
        for (int y = 1; y < KAL; ++y)
            for (int x = y + 1; x < KAL; ++x)
                if (std::__gcd(x, y) == 1) {
                    int cnt = r / pws[n - 1][x] - l / pws[n - 1][y];
                    if (l % pws[n - 1][y] == 0) ++cnt;
                    if (cnt > 0) ans += cnt;
                }
        ans += ans;
    }

    cout << ans << '\n';
    
    return 0;
}