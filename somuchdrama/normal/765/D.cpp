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
    _err(_v.begin(), as);\
}
#else
#define dbg(as...)
#endif

template<typename T>
void _err(vector<string>::iterator it, T a) {
    cerr << it->substr((*it)[0] == ' ') << " = " << a << '\n';
}
template<typename T, typename...Ts>
void _err(vector<string>::iterator it, T a, Ts...as) {
    cerr << it->substr((*it)[0] == ' ') << " = " << a << ", ";
    _err(++it, as...);
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
int f[MAXN], g[MAXN], h[MAXN];
void no() {
    cout << "-1\n";
    exit( 0 );
}

int main() {

    int n, c = 1;
    cin >> n;
    for (int i = 1; i <= n; ++i) 
        cin >> f[i];

    bool ok = true;
    for (int i = 1; i <= n; ++i) 
        ok &= f[f[i]] == f[i];
    if (!ok) no();
    for (int i = 1; i <= n; ++i) {
        if (!g[f[i]]) 
            g[f[i]] = c++;
        g[i] = g[f[i]];
        h[g[i]] = f[i];
    }
    cout << c - 1 << '\n';
    for (int i = 1; i <= n; ++i) 
        cout << g[i] << ' ';
    cout << '\n'; 
    for (int i = 1; i < c; ++i) 
        cout << h[i] << ' ';
    cout << '\n';

    return 0;
}