//   

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
        using namespace std::chrono;
        srand(duration_cast<nanoseconds>(high_resolution_clock::now().time_since_epoch()).count()); 
        #endif
    }
    ~init() {
        #ifdef LOCAL
        cerr << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC << "s.\n";
        #endif
    }
} init;

const int MAXN = 2e5 + 1;
const ll MOD = 1e9 + 7;

vector<int> g[MAXN];
vector<int> trees;
int cycles = 0;
bool used[MAXN];
bool used2[MAXN];
bool used3[MAXN];
int go[MAXN];
int sz =0;
void dfs(int v) {
    ++sz;
    used[v] = 1;
    for (int to : g[v]) 
        if (!used[to]) 
            dfs(to);
}


int main() {

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int a, b;
        cin >> a >> b;
        g[b].pb(a);
        go[a] = b;
    }

    ll ans = 1;
    for (int i = 1; i <= n + n; ++i) {
        if (!used[i]) {
            int start = i;
            bool cyc = 0;
            vector<int> path;
            while (go[start]) {
                path.pb(start);
                if (used2[start]) {
                    cyc = 1;
                    dfs(start);
                    assert(path.size() > 1);
                    if (path[path.size() - 1] != path[path.size() - 2]) {
                        ans *= 2;
                        ans %= MOD;
                    }
                    break;
                }
                used2[start] = 1;
                start = go[start];
            }
            dbg(i, start, cyc);
            if (g[start].empty() || used[start]) 
                continue;
            if (!cyc) {
                sz = 0;
                dfs(start);
                ans *= sz;
                ans %= MOD;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}