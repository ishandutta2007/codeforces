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



int main() {

    int a, b, c, m;
    cin >> a >> b >> c >> m;
    vector<ll> usb, ps2;
    for (int i = 0; i < m; ++i) {
        int x;
        string s;
        cin >> x >> s;
        if (s[0] == 'U') usb.pb(x);
        else ps2.pb(x);
    }

    sort(usb.begin(), usb.end());
    sort(ps2.begin(), ps2.end());

    int u = 0, p = 0;
    ll ans = 0, tot = 0;
    for (; u < usb.size() && a; ++u) {
        ans += usb[u];
        --a;
        ++tot;
    }

    for (; p < ps2.size() && b; ++p) {
        ans += ps2[p];
        --b;
        ++tot;
    }

    vector<ll> all;
    for (; u < usb.size(); ++u)
        all.pb(usb[u]);
    for (; p < ps2.size(); ++p)
        all.pb(ps2[p]);

    sort(all.begin(), all.end());

    for (int i = 0; i < all.size() && c; ++i) {
        ans += all[i];
        --c;
        ++tot;
    }

    cout << tot << ' ' << ans << '\n';

    return 0;
}