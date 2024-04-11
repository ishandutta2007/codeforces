#include <bits/stdc++.h>

using namespace std;

#ifdef SG
    #include <debug.h>
#else 
    #define show(...)
    #define debug(...)
    #define deepen(...)
    #define timer(...)
#endif

#define ARG4(_1,_2,_3,_4,...) _4

#define forn3(i,l,r) for (int i = int(l); i < int(r); ++i)
#define forn2(i,n) forn3 (i, 0, n)
#define forn(...) ARG4(__VA_ARGS__, forn3, forn2) (__VA_ARGS__)

#define ford3(i,l,r) for (int i = int(r) - 1; i >= int(l); --i)
#define ford2(i,n) ford3 (i, 0, n)
#define ford(...) ARG4(__VA_ARGS__, ford3, ford2) (__VA_ARGS__)

#define ve vector
#define pa pair
#define tu tuple
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define fs first
#define sc second
#define all(a) (a).begin(), (a).end()
#define sz(a) ((int)(a).size())

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;
typedef pa<int, int> pii;
typedef pa<int, ll> pil;
typedef pa<ll, int> pli;
typedef pa<ll, ll> pll;
typedef ve<int> vi;

const ld pi = 3.1415926535897932384626433832795l;

template<typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template<typename T1, typename T2> inline bool umx (T1& a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T1, typename T2> inline bool umn (T1& a, T2 b) {if (b < a) {a = b; return 1;} return 0;}

int n, m;
int ans;
ve< vi > g;
int dist[2015];
int used[2015];
int q[2015];

int
get_ans(const vi &cc)
{
    int ans = -1;
    for (auto v : cc) {
        for (auto u : cc) {
            dist[u] = -1;
        }
        int qh = 0, qt = 0;
        q[qt++] = v;
        dist[v] = 0;
        while (qh < qt) {
            int cur_v = q[qh++];
            for (auto to : g[cur_v]) {
                if (dist[to] == -1) {
                    dist[to] = dist[cur_v] + 1;
                    q[qt++] = to;
                }
            }
        }
        int len = 0;
        for (auto u : cc) {
            umx(len, dist[u]);
            for (auto to : g[u]) {
                if (abs(dist[to] - dist[u]) != 1) {
                    len = -1;
                    break;
                }
            }
            if (len == -1) {
                break;
            }
        }
        umx(ans, len);
    }
    return ans;
}

void
dfs(int x, vi &vals)
{
    used[x] = true;
    vals.pb(x);
    for (auto to : g[x]) {
        if (!used[to]) {
            dfs(to, vals);
        }
    }
}

int
main()
{
    ios_base::sync_with_stdio(false);
    cout.setf(ios::showpoint | ios::fixed);
    cout.precision(20);
    cin >> n >> m;
    g.assign(n, vi());
    forn(i, m) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].pb(v);
        g[v].pb(u);
    }
    int ans = 0;
    memset(used, 0, sizeof(used));
    forn(i, n) {
        if (used[i]) {
            continue;
        }
        vi tmp;
        dfs(i, tmp);
        int cur_cc = get_ans(tmp);
        if (cur_cc == -1) {
            ans = -1;
            break;
        }
        ans += cur_cc;
    }
    cout << ans << '\n';
    return 0;
}