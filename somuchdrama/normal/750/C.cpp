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
#define int ll
const ll INF = 2e9;
const int kal = 1900;
void no() {
    cout << "Impossible\n";
    exit( 0  );
}
int32_t main() {

    int n;
    cin >> n;
    vector<pii> a(n);
    bool was2 = false;
    for (pii & p : a) {
        cin >> p.ff >> p.ss;
        was2 |= p.ss == 2;
    }

    if (!was2) {
        cout << "Infinity\n";
        return 0;
    }
    
    int mx = -INF, cur = 0, w = -1;
    for (int i = 0; i < n; ++i) {
        dbg(a[i].ff, a[i].ss, mx, cur);
        if (a[i].ss == 2 && mx < cur) {
            mx = cur;
            w = i;
        }
        cur += a[i].ff;
    }

    dbg(mx, cur, w);

    cur = kal - 1;
    for (int j = w - 1; j >= 0; --j) {
        cur -= a[j].ff;
    }

    for (int i = 0; i < n; ++i) {
        if (a[i].ss == 1 && cur < kal) no();
        if (a[i].ss == 2 && cur >= kal) no();
        cur += a[i].ff;
    }

    cout << cur << '\n';

    return 0;
}