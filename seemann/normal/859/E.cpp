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
ll MOD = 1e9 + 7;

int p[MAXN];
bool taken[MAXN];
int used[MAXN];
int timer = 1;
vector<int> c[MAXN];

ll getans(int v) {
    ll ans = 1;
    for (auto u : c[v]) {
        ans += getans(u);
    }
    return ans % MOD;
}
int main() {
#ifdef LOCAL
    freopen("e.in", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n;
//    n = 100000;
    cin >> n;
    forn(i, n) {
        int u, v;
//        u = 2 * i + 1;
//        v = 2 * i + 2;
        cin >> u >> v;
        u--, v--;
        taken[u] = true;
        p[u] = v;
        c[v].pb(u);
    }

    ll ans = 1;
    forn(i, 2 * n) {
        if (!taken[i])
            continue;
        timer++;
        int v = i;
        bool tree = true;
        while(true) {
            if (used[v] != 0) {
                tree = false;
                if (used[v] == timer) {
                    if (p[v] != v) {
                        ans *= 2;
                        ans %= MOD;
                    }
                }
                break;
            }
            used[v] = timer;
            if (!taken[v]) {
                break;
            }
            v = p[v];
        }
        if (tree) {
            ans *= getans(v);
            ans %= MOD;
        }
    }
    cout << ans << '\n';
    
    return 0;
}