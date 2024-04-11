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
        while (count(_cur.begin(), _cur.end(), '(') != count(_cur.begin(), _cur.end(), ')') || \
               count(_cur.begin(), _cur.end(), '[') != count(_cur.begin(), _cur.end(), ']') || \
               count(_cur.begin(), _cur.end(), '{') != count(_cur.begin(), _cur.end(), '}')) {\
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
vector<int> g[MAXN], t[MAXN];
bool used[MAXN];
bool used2[MAXN];
int col[MAXN];

void dfs1(int v) {
    used[v] = true;
    for (int to : g[v]) {
        if (!used[to]) {
            used[to] = true;
            if (col[to] != 1)
                dfs1(to);
        }
    }
}

void dfs2(int v) {
    used2[v] = true;
    for (int to : t[v]) {
        if (!used2[to]) {
            used2[to] = true;
            if (col[to] != 1)
                dfs2(to);
        }
    }
}

int32_t main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> col[i];
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        t[b].pb(a);
    }

    for (int i = 1; i <= n; ++i)
        if (col[i] == 1)
            dfs1(i);

    for (int i = 1; i <= n; ++i)
        if (col[i] == 2)
            dfs2(i);

    for (int i = 1; i <= n; ++i)
        cout << (used[i] & used2[i]) << '\n';

    return 0;
}