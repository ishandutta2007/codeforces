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

const int MAXN = 2e5 + 1;
vector<int> g[MAXN];
bool used[MAXN];
int x;
int mx = 0;
int p[MAXN];
void dfs(int v, int from = -1) {
    used[v] = 1;
    p[v] = from;
    for (int to : g[v]) 
        if (!used[to])
            dfs(to, v);
}

void dfs2(int v, int dd = 0, bool upd = 0) {
    used[v] = 1;
    if (v == x)
        upd = 1;
    if (upd)
        mx = max(mx, dd);
    for (int to : g[v]) 
        if (!used[to])
            dfs2(to, dd + 1, upd);

}


int main() {

    int n;
    cin >> n >> x;
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    dfs(1);

    int cur = x;
    vector<int> way;
    while (cur != -1) {
        way.pb(cur);
        cur = p[cur];
    }

    int sz = way.size();
    int up = sz / 2 - 1;
    for (int i = 0; i < up; ++i)
        x = p[x];

    memset(used, 0, sizeof used);

    dfs2(1);

    cout << mx * 2 << '\n';

    return 0;
}