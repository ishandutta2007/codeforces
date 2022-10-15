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

const int MAXN = 2e5 + 1;
bool good[MAXN];
bool used[MAXN];
vector<int> g[MAXN];
set<int> dd[MAXN];
int s = -1;
void dfs(int v) {
    dbg(v);
    if (s != -1) return;
    used[v] = true;
    vector<int> sons;
    for (int to : g[v]) {
        if (!used[to]) {
            dfs(to);
            sons.pb(to);
        }
        if (s != -1) return;
    }
    if (sons.empty()) {
        good[v] = true;
        dd[v].insert(0);
    } else {
        good[v] = true;
        for (int to : sons) {
            good[v] &= good[to];
            dd[v].insert(*dd[to].begin() + 1);
        }
        if (!good[v] || dd[v].size() > 1) {
            s = v;
            return;
        }
    }
    dbg(dd[v].size());
    // cerr << v << ": ";for (int i : dd[v]) cerr << i << ' ';
    // cerr << '\n';
}
int t = -1;
void solve(int v) {
    dbg(v);
    if (t != -1) return;
    used[v] = true;
    vector<int> sons;
    for (int to : g[v]) {
        if (!used[to]) {
            solve(to);
            sons.pb(to);
        }
        if (t != -1) return;
    }
    if (sons.empty()) {
        good[v] = true;
        dd[v].insert(0);
    } else {
        good[v] = true;
        for (int to : sons) {
            good[v] &= good[to];
            dd[v].insert(*dd[to].begin() + 1);
        }
        if ((!good[v] || dd[v].size() > 1) && s != v) {
            t = v;
            return;
        }
    }
    // cerr << v << ": ";for (int i : dd[v]) cerr << i << ' ';
    // cerr << '\n';
}

int kek(int sz) {
    while (sz % 2 == 0)
        sz /= 2;
    return sz;
}

int main() {

    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    dfs(1);

    dbg(s);
    if (s == -1) {
        dbg(dd[1].size());;
        int sz = *dd[1].begin();
        dbg("ye");
        cout << kek(sz) << '\n';
        return 0;
    }

    std::fill(used + 1, used + n + 1, false);
    std::fill(good + 1, good + n + 1, false);
    for (int i = 1; i <= n; ++i)
        dd[i].clear();


    solve(s);
    dbg(t);
    if (t == -1 && good[s] && dd[s].size() <= 2) {
        if (dd[s].size() == 1) {
            cout << kek(*dd[s].begin()) << '\n';
        } else {
            cout << kek(*dd[s].begin() + *(std::next(dd[s].begin()))) << '\n';
        }
    } else {
        cout << "-1\n";
    }

    return 0;
}