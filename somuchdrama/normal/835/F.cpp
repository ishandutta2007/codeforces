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
#define int ll

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


const int MAXN = 200001;
vector<pll> g[MAXN];
vector<int> way;
vector<int> cyc;
int used[MAXN];

void dfs1(int v, int p = -1) {
    used[v] = 1;
    way.pb(v);
    for (auto to : g[v]) {
        if (!used[to.ff])
            dfs1(to.ff, v);
        else if (to.ff != p){
            reverse(way.begin(), way.end());
            for (int i : way) {
                cyc.pb(i);
                if (i == to.ff) 
                    break;
            }
        }
        if (!cyc.empty()) 
            return;
    }
    way.pop_back();
}

bool incyc[MAXN];
int d1[MAXN], d2[MAXN];

void dfs2(int v, int dd = 0) {
    way.pb(v);
    used[v] = 2;
    d1[v] = dd;
    for (auto to : g[v]) 
        if (!incyc[to.ff] && used[to.ff] != 2)
            dfs2(to.ff, dd + to.ss);
}

void dfs3(int v, int dd = 0) {
    used[v] = 3;
    d2[v] = dd;
    for (auto to : g[v]) 
        if (!incyc[to.ff] && used[to.ff] != 3)
            dfs3(to.ff, dd + to.ss);
}

int a[MAXN + MAXN], b[MAXN + MAXN];


struct vertex {
    int l = 0, r = 0, m = 0, suma = 0;
    vertex() {}
    vertex(int aa, int bb) {
        l = max(aa, bb);
        m = r = aa + bb;
        suma = aa;
    }
} tree[MAXN * 8];

vertex merge(vertex left, vertex right) {
    vertex res;
    res.l = max(left.l, right.l + left.suma);
    res.r = max(right.r, left.r + right.suma);
    res.m = max({left.m, right.m, left.r + right.l});
    res.suma = left.suma + right.suma;
    return res;
}

int SZ, sz = 0, sh = 1;
void build() {
    while (sh < SZ)
        sh *= 2;
    for (int i = 0; i < SZ; ++i) 
        tree[sh + i] = vertex(a[i], b[i]);
    for (int i = sh - 1; i > 0; --i) 
        tree[i] = merge(tree[i + i], tree[i + i + 1]);
}

void update(int i, int vala, int valb) { 
    for (tree[i += sh] = vertex(vala, valb); i /= 2; ) 
        tree[i] = merge(tree[i + i], tree[i + i + 1]);
}

int32_t main() {

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int u, v, l;
        cin >> u >> v >> l;
        g[u].pb(v, l);
        g[v].pb(u, l);
    }

    dfs1(1);

    for (int i : cyc) {
        dbg(i);
        incyc[i] = 1; 
    }

    int sureans = 0;

    for (int i : cyc) {
        way.clear();
        dfs2(i);
        int w = i;
        for (int j : way)
            if (d1[w] < d1[j])
                w = j;
        b[sz++] = d1[w];

        incyc[i] = 0;
        dfs3(w);
        incyc[i] = 1;

        w = i;
        for (int j : way)
            if (d2[w] < d2[j])
                w = j;

        if (sureans < d2[w])
            sureans = d2[w];
    }

    for (int i = 0; i < sz; ++i) {
        int nx = cyc[(i + 1) % sz];
        for (auto to : g[cyc[i]])
            if (to.ff == nx)
                a[i] = to.ss;
    }

    for (int i = 0; i < sz; ++i)
        dbg(cyc[i], a[i], b[i]);

    SZ = sz * 2;

    int last = a[sz - 1];
    a[sz - 1] = 0;

    build();

    a[sz - 1] = last;

    // for (int v = 0; v < SZ + sh; ++v)
    //     dbg(v, tree[v].l, tree[v].r, tree[v].m, tree[v].suma);

    int mn = max({tree[1].l, tree[1].m, tree[1].r});
    dbg(mn);

    for (int i = 0; i < sz; ++i) {
        dbg("next");
        update(i, 0, 0);
        update(i + sz - 1, last, b[(i + sz - 1) % sz]);
        last = a[i];
        update(i + sz, 0, b[i]);
        int mx = max({tree[1].l, tree[1].m, tree[1].r});
        dbg(mx);
        if (mn > mx)
            mn = mx;

        // for (int v = 0; v < SZ + sh; ++v)
        //     dbg(v, tree[v].l, tree[v].r, tree[v].m, tree[v].suma);
    }

    if (mn < sureans)
        mn = sureans;

    cout << mn << '\n';

    return 0;
}