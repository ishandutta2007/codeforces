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

int main() {
    ll n, m, k, s, x;
    cin >> n >> m >> k >> x >> s;
    vector<ll> a(m), b(m), c(k), d(k);
    for (ll & i : a)
        cin >> i;
    for (ll & i : b)
        cin >> i;
    for (ll & i : c)
        cin >> i;
    for (ll & i : d)
        cin >> i;
    a.pb(x);
    b.pb(0);
    reverse(c.begin(), c.end());
    reverse(d.begin(), d.end());

    ll ans = x * n;

    for (int i = 0; i <= m; ++i) {
        ll left = s - b[i];
        if (left < 0) continue;
        int pos = lower_bound(d.begin(), d.end(), left, std::greater<ll>()) - d.begin();
        ll aa;
        if (pos == c.size()) 
            aa = n;
        else 
            aa = n - c[pos];
        ll cur = aa * a[i];
        // dbg(i, pos, c[pos], cur, left, aa);
        ans = min(ans, cur);
    }

    cout << ans << '\n';


    return 0;
}