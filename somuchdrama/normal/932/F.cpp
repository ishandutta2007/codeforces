#include <bits/stdc++.h>
using std::cerr;using std::cin;using std::cout;using std::abs;using std::min;using std::max;using std::swap;using std::map;using std::pair;using std::set;using std::string;using std::vector;
using ll = long long;using uint = unsigned int;using pii = pair<int, int>;using pll = pair<ll, ll>;
#define ff first
#define ss second
#define pb emplace_back
template<typename T> void _dbg(const char* _s,T _h){cerr<<_s<<" = "<<_h <<"\n";}
template<typename T,typename... Ts>void _dbg(const char* _s,T _h,Ts... _t){int _b = 0;while(((_b+=*_s=='(')-=*_s==')')!=0||*_s!=',')cerr<<*_s++;cerr<<" = "<<_h<<",";_dbg(_s+1,_t...);}
#ifdef LOCAL
#define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 
#endif

struct init { init() {cin.tie(0);std::iostream::sync_with_stdio(0);cout << std::fixed << std::setprecision(10);cerr << std::fixed << std::setprecision(5);}~init() {
        #ifdef LOCAL
        cerr << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC << "s.\n";
        #endif
}} init;

const ll QUERY = 1LL<<62;
 
struct Line {
    ll m, b;
    mutable std::function<const Line *()> succ;
 
    bool operator<(const Line &rhs) const {
        if (rhs.b != -QUERY) return m < rhs.m;
        const Line *s = succ();
        if (!s) return 0;
        ll x = rhs.m;
        return b - s->b < (s->m - m) * x;
    }
};
 
struct HullDynamic : public std::multiset<Line> {
    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end()) return 0;
            return y->m == z->m && y->b <= z->b;
        }
        auto x = prev(y);
        if (z == end()) return y->m == x->m && y->b <= x->b;
        return (x->b - y->b) * (long double)(z->m - y->m) >= (y->b - z->b) * (long double)(y->m - x->m);
    }
 
    void insert_line(ll m, ll b) {
        auto y = insert({m, b});
        y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
        if (bad(y)) {
            erase(y);
            return;
        }
        while (next(y) != end() && bad(next(y))) erase(next(y));
        while (y != begin() && bad(prev(y))) erase(prev(y));
    }
 
    ll eval(ll x) {
        auto l = *lower_bound((Line) {x, -QUERY});
        return l.m * x + l.b;
    }
};

const int MAXN = 1e5 + 1;
ll dp[MAXN], a[MAXN], b[MAXN];
vector<int> g[MAXN];

HullDynamic cht[MAXN];
int w[MAXN];
int f = 0;

void dfs(int v, int p = -1) {
    int x = -1;
    for (int to : g[v]) {
        if (to ^ p) {
            dfs(to, v);
            if (x == -1 || cht[w[to]].size() > cht[w[x]].size()) 
                x = to;
        }
    }
    for (int to : g[v])
        if ((to ^ p) && (to ^ x)) {
            for (auto i : cht[w[to]])
                cht[w[x]].insert_line(i.m, i.b);
        }
    if (x == -1) {
        dp[v] = 0;
        w[v] = f++;
    } else {
        dp[v] = -cht[w[x]].eval(a[v]);
        w[v] = w[x];
    }
    cht[w[v]].insert_line(-b[v], -dp[v]);
}

int32_t main() {
    
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> b[i];

    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }

    dfs(1);

    for (int i = 1; i <= n; ++i)
        cout << dp[i] << ' ';
    cout << '\n';

    return 0;
}