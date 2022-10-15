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
#define int ll
const int MAXN = 2e5 + 1, MAXK = 5;
int n, k;
vector<int> g[MAXN];
bool used[MAXN];
int cnt[MAXK][MAXN];
int size[MAXN];
int dfs1(int v) {
    used[v] = true;
    size[v] = 1;
    cnt[0][v] = 1;
    for (int to : g[v]) 
        if (!used[to]) {
            size[v] += dfs1(to);
            for (int i = 0; i < k; ++i)
                cnt[i][v] += cnt[(i + k - 1) % k][to];
        }
    return size[v];
}
int cup[MAXK][MAXN];
// int sum[MAXK][MAXN];
int ans = 0;
void dfs2(int v, int p = 0) {
    used[v] = true;

    for (int i = 0; i < k; ++i) {
        dbg(cup[(i + k - 1) % k][p] , cnt[(i + k + k - 1) % k][p] , cnt[(i + k + k - 2) % k][v]);
        cup[i][v] = cup[(i + k - 1) % k][p] + cnt[(i + k + k - 1) % k][p] - cnt[(i + k + k - 2) % k][v];
    }

    if (v == 1) {
        for (int i = 0; i < k; ++i)
            cup[i][v] = 0;
    } else 
        cup[1 % k][v]--;
        // for (int i = 1; i < k; ++i)
        //     cup[i][v]--;
    
    cup[0][v]++;

    // dbg(v);
    // dbg(cnt[0][v], cnt[1][v], cup[0][v], cup[1][v], cup[2][v]);
    for (int to : g[v])
        if (!used[to]) 
            dfs2(to, v);

    dbg(v);
    int up = n - size[v];
    dbg(cnt[0][v] * up, cup[1 % k][v] * size[v]);
    ans += cnt[0][v] * up;
    ans += cup[1 % k][v] * size[v];
    dbg(ans);
}

void dfs3(int v) {
    used[v] = true;
    for (int to : g[v])
        if (!used[to])
            dfs3(to);
    int up = n - size[v];
    ans += 2 * size[v] * up;
}

int32_t main() {

    cin >>n >> k;
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    dfs1(1);
    memset(used, 0, sizeof(used));
    if (k == 1) dfs3(1);
    else dfs2(1);

    cout << ans/2 << '\n';


    return 0;
}