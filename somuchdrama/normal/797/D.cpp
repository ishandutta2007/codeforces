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
        #ifdef LOCAL
        srand(300); 
        #else
        srand(time(0));
        #endif
    }
    ~init() {
        cerr << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC << "s.\n";
    }
} init;

const int MAXN = 1e5 + 1, INF = 1e9 + 7;
int l[MAXN], r[MAXN], v[MAXN], p[MAXN];
map<int, int> cnt;
int ans = 0;
void dfs(int node, int tl = -INF, int tr = +INF) {
    if (tl <= v[node] && v[node] <= tr) {
        ans += cnt[v[node]];
        cnt[v[node]] = 0;
    }
    if (l[node] != -1)
        dfs(l[node], tl, min(tr, v[node] - 1));
    if (r[node] != -1)
        dfs(r[node], max(tl, v[node] + 1), tr);
}

int main() {

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i] >> l[i] >> r[i];
        if (l[i] != -1) p[l[i]] = i;
        if (r[i] != -1) p[r[i]] = i;
        ++cnt[v[i]];
    }

    int root;
    for (int i = 1; i <= n; ++i)
        if (!p[i])
            root = i;

    dfs(root);

    cout << n - ans << '\n';

    return 0;
}