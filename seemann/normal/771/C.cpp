#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <queue>
#include <bitset>

using namespace std;

#define FOR(a, b) for (int a = 0; a < (b); ++a)
#define clr(a) memset(a, 0, sizeof(a))
#define pb push_back
#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)
#ifdef LOCAL
#define debug(a) cerr << #a << ": " << a << '\n';
#else
#define debug(a)
#endif

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ld EPS = 1e-8;
const ld PI = acos(-1.0L);
const int MAXN = 2e5 + 100;
const int MAXK = 6;
vector<int> e[MAXN];
ll c[MAXN][MAXK];
ll len[MAXN][MAXK];
ll a[MAXN];


ll ans = 0;

int n, k;
void dfs(int v, int par) {
    c[v][0] = 1;
    for (auto u : e[v]) {
        if (u == par)
            continue;
        dfs(u, v);
    }
//        a[v] += a[u] + c[u][0];
//    cerr << "Vertex " << v << '\n';
    for (auto u : e[v]) {
        if (u == par)
            continue;
        forn(i, k) {
            forn(j, k) {
                /*
                if (c[u][j] != 0 && c[v][i] != 0) {
                    cerr << u << ' ' <<  i + j << ' ' << c[u][j] << ' ' << c[v][i] << '\n';
                    cerr <<  c[u][j] * len[v][i] + c[v][i] * len[u][j] + ((i + j + k) / k) * c[u][j] * c[v][i] << '\n';;

                }*/
                a[v] += c[u][j] * len[v][i] + c[v][i] * len[u][j] + ((i + j + k) / k) * c[u][j] * c[v][i];
            }
        }
        forn(i, k) {
            c[v][(i + 1) % k] += c[u][i];
            len[v][(i + 1) % k] += len[u][i];
        }
        len[v][0] += c[u][k - 1];
    }
    /*
    cerr << a[v] << '\n';
    forn(i ,k)
        cerr << c[v][i] << ' ';
    cerr << '\n';
    forn(i ,k)
        cerr << len[v][i] << ' ';
    cerr << '\n';*/
    ans += a[v];
}
int main() {
#ifdef LOCAL
    freopen("a.in", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    forn(i, n - 1) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        e[u].pb(v);
        e[v].pb(u);
    }
    dfs(0, -1);
    cout << ans << '\n';

    return 0;
}