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


const int INF = 1e9 + 7;
const int MAXN = 2016;
int n;

struct edge {
    int to, f, c, w;
    edge(int _to, int _f, int _c, int _w): to(_to), f(_f), c(_c), w(_w) {}
};

vector<edge> edges;
vector<int> g[MAXN];
vector<pii> gt[MAXN];
vector<int> pot;

void dfs(int v, vector <char> &used, vector <int> &d) {
    used[v] = true;
    for (pii i : gt[v]) {
        if (!used[i.ff])
            dfs(i.ff, used, d);
        d[v] = min(d[v], d[i.ff] + i.ss);
    }
}

vector<int> very_bad_function(int s) {
    vector<int> d(n + n + 2, INF);
    d[s] = 0;
    for (int i = 0; i < n + n + 2; ++i)
        for (int j : g[i])
            if (edges[j].f < edges[j].c)
                gt[edges[j].to].pb(i, edges[j].w);
    vector<char> used(n + n + 2, false);
    for (int i = 0; i < n + n + 2; ++i) 
       if (!used[i])
           dfs(i, used, d);
    return std::move(d);
}


vector<int> phi;

vector<int> jonson(int start, int t) {
    vector<int> dist(n + n + 2, INF), last_e(n + n + 2, -1), last_v(n + n + 2, -1);
    dist[start] = 0;
    vector<char> used(n + n + 2);
    for (int it = 1; it < n + n + 2; ++it) {
        int p = -1;
        for (int i = 0; i <= n + n + 1; ++i)
            if (!used[i] && dist[i] != INF && (p == -1 || dist[i] < dist[p]))
                p = i;
        if (p == -1)
            break;
        used[p] = true;
        for (int i = 0; i < g[p].size(); ++i) {
            edge e = edges[g[p][i]];
            if (e.f < e.c && dist[e.to] > dist[p] + phi[p] + e.w - phi[e.to]) {
                dist[e.to] = dist[p] + phi[p] + e.w - phi[e.to];
                //cout << p << ' ' << e.to << ' ' << dist[e.to] << std::endl;
                last_e[e.to] = g[p][i];
                last_v[e.to] = p;
            }
        }
    }
    //cout << "dijkstra end\n";
    vector<int> ans;
    if (dist[t] == INF) return ans;
    for (int i = 0; i <= n + n + 1; ++i)
        phi[i] += dist[i];
    while (t != start) {
        ans.pb(last_e[t]);
        t = last_v[t];
    }
    return ans;
}

int32_t main() {
    int k;
    cin >> n >> k;
    vector<int> s(n + 1), t(n + 1), c(n + 1);

    for (int i = 1; i <= n; ++i)
        cin >> s[i] >> t[i] >> c[i];

    for (int i = 1; i <= n; ++i) {
        int sz = edges.size();
        edges.pb(i + n, 0, 1, -c[i]);
        edges.pb(i, 0, 0, c[i]);
        g[i].pb(sz);
        g[i + n].pb(sz + 1);
    }

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            if (i == j) continue;
            if (s[i] + t[i] <= s[j]) {
                int sz = edges.size();
                edges.pb(j, 0, 1, 0);
                edges.pb(i + n, 0, 0, 0);
                g[i + n].pb(sz);
                g[j].pb(sz + 1);
            }
        }

    for (int i = 1; i <= n; ++i) {
        int sz = edges.size();
        edges.pb(i, 0, 1, 0);
        edges.pb(0, 0, 0, 0);
        g[0].pb(sz);
        g[i].pb(sz + 1);
    }

    for (int i = 1; i <= n; ++i) {
        int sz = edges.size();
        edges.pb(n + n + 1, 0, 1, 0);
        edges.pb(i + n, 0, 0, 0);
        g[i + n].pb(sz);
        g[n + n + 1].pb(sz + 1);
    }

    phi = very_bad_function(0);
    for (int i : phi)
        dbg(i);

    for (int it = 0; it < k; ++it) {
        vector <int> cnt = jonson(0, n + n + 1);
        for (int i : cnt) {
            edges[i].f++;
            edges[i ^ 1].f--;
        }
    }

    for (int i = 0; i < n; ++i)
        cout << edges[i + i].f << ' ';
    cout << '\n';
    return 0;
}