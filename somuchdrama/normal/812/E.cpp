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

const int MAXN = 1e5 + 1;
vector<int> g[MAXN];
int a[MAXN];
int c[MAXN];

void dfs(int v) {
    for (int to : g[v]) {
        dfs(to);
        c[v] = c[to] ^ 1;
    }
}

int main() {

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) 
        cin >> a[i];
    for (int i = 2; i <= n; ++i) {
        int p; cin >> p;
        g[p].pb(i);
    }

    dfs(1);
    map<int, ll> ms[2];
    for (int i = 1; i <= n; ++i) {
        dbg(i, a[i], c[i]);
        ++ms[c[i]][a[i]];
    }

    ll ans = 0;

    int s = 0;
    for (auto p : ms[0])
        if (p.ss & 1)
            s ^= p.ff;
    dbg(s);

    for (int i = 0; s == 0 && i < 2; ++i) {
        ll sz = 0;
        for (auto p : ms[i])
            sz += p.ss;
        ans += (sz * (sz - 1)) / 2;
    }

    dbg(ans);   

    for (auto p : ms[0]) {
        int x = p.ff;
        int y = s ^ x;
        ans += p.ss * ms[1][y];
    }

    cout << ans << '\n';

    return 0;
}