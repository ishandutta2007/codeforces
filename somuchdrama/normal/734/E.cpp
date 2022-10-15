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
const int MAXN = 2e5 + 1;
int comp[MAXN];
vector<int> g[MAXN];
bool col[MAXN];
int lastcomp = 1;
vector<int> comps[MAXN];
void condense(int v, int curcomp = 1) {
    comps[curcomp].pb(v);
    comp[v] = curcomp;
    for (int to : g[v]) {
        if (!comp[to]) {
            if (col[to] != col[v]) {
                ++lastcomp;
                condense(to, lastcomp);
            } else {
                condense(to, curcomp);
            }
        }
    }
}
set<int> g2[MAXN];
int d[MAXN];
bool used[MAXN];
void dfs(int v, int curd = 0) {
    used[v] = true;
    d[v] = curd;
    for (int to : g2[v])
        if (!used[to])
            dfs(to, curd + 1);
}

int main() {

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> col[i];

    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    condense(1);
    for (int i = 1; i <= n; ++i)
        dbg(i, comp[i]);

    for (int c = 1; c <= lastcomp; ++c)
        for (int i : comps[c])
            for (int to : g[i])
                if (comp[to] != c) 
                    g2[c].insert(comp[to]);

    dfs(1);
    int wmx = 1;
    for (int i = 1; i <= lastcomp; ++i)
        if (d[wmx] < d[i])
            wmx = i;

    for (int i = 1; i <= lastcomp; ++i)
        dbg(i, d[i]);

    dbg(wmx);
    std::fill(used, used + n + 1, false);
    dfs(wmx);   

    int ans = 0;
    for (int i = 1; i <= lastcomp; ++i)
        ans = max(ans, (d[i] + 1) / 2);

    cout << ans << '\n';

    return 0;
}