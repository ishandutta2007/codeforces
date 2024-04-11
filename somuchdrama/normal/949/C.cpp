//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //
//  //

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
template<typename T> 
void _dbg(const char* _s, T _h) {
    cerr << _s << " = " << _h <<"\n"; 
}
template<typename T, typename... Ts>
void _dbg(const char* _s, T _h, Ts... _t) {
    int _b = 0;
    while (((_b += *_s == '(') -= *_s == ')') != 0 || *_s != ',')
        cerr << *_s++; 
    cerr << " = " << _h << ","; 
    _dbg(_s+1, _t...);
}
#ifdef LOCAL
#define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 
#endif

struct init {
    init() {
        cin.tie(0);
        std::iostream::sync_with_stdio(0);
        cout << std::fixed << std::setprecision(10);
        cerr << std::fixed << std::setprecision(5);
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

const int MAXN = 1e5 + 1;
int u[MAXN];

vector<int> g[MAXN], trans[MAXN], order;
set<int> ans[MAXN];
int col[MAXN], comp = 0;
bool used[MAXN];

int s[MAXN];

void topsort(int v) {
    used[v] = true;
    for (int to : g[v])
        if (!used[to])
            topsort(to);
    order.pb(v);
}

void dfs(int v) {
    col[v] = comp;
    for (int to : trans[v])
        if (!col[to])
            dfs(to);
}

void scc(int n) {
    for (int i = 1; i <= n; ++i)
        if (!used[i])
            topsort(i);

    reverse(order.begin(), order.end());

    for (int i = 1; i <= n; ++i)
        for (int j : g[i])
            trans[j].pb(i);

    for (int v : order) {
        if (!col[v]) {
            ++comp;
            dfs(v);
        }
    }
}

void condense(int n) {
    for (int i = 1; i <= n; ++i)  {
        ++s[col[i]];
        for (int j : g[i]) 
            if (col[i] != col[j]) 
                ans[col[i]].insert(col[j]);
    }
}


int main() {
    
    int n, m, h;
    cin >> n >> m >> h;
    for (int i = 1; i <= n; ++i)
        cin >> u[i];
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        if ((u[a] + 1) % h == u[b])
            g[a].pb(b);
        if (u[a] == (u[b] + 1) % h)
            g[b].pb(a);
    }

    for (int i = 1; i <= n; ++i)
        for (int j : g[i])
            dbg(i, j);

    scc(n);

    for (int i = 1; i <= n; ++i)
        dbg(col[i]);
    condense(n);

    int wans = -1;
    for (int i = 1; i <= comp; ++i) {
        if (ans[i].empty() && (wans == -1 || s[i] < s[wans])) {
            wans = i;
        }
    }

    dbg(wans);

    vector<int> gans;
    for (int i = 1; i <= n; ++i) {
        if (col[i] == wans) {
            gans.pb(i);
        }
    }

    cout << gans.size() << '\n';
    for (int i : gans)
        cout << i << ' ';
    cout << '\n';
    
    return 0;
}