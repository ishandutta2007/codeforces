#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <cassert>

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define forn(i, n) for(int i = 0 ; (i) < (n) ; ++i)
#define forit(it,v) for(typeof((v).begin()) it = v.begin() ; it != (v).end() ; ++it)
#define eprintf(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(),a.end()

using namespace std;

typedef long long ll;
typedef double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;

const int inf = (int)1e9;
const ld eps = 1e-9;


#define TASK "a"
int a[1000];
int b[1000];
int go[1000];
int was[1000];
ll sum[1000];
int h[1000];
vi g[1000];
int n, C, m;
int up(int x) {
    if (go[x] == x) {
        return x;
    }
    return go[x] = up(go[x]);
}
bool dsu_merge(int x, int y) {
    x = up(x);
    y = up(y);
    if (x == y) return false;
    go[x] = y;
    return true; 
}
void dfs(int v) {
    was[v] = 1;
    sum[v] = a[v] - b[v];
    for (int i = 0; i < sz(g[v]); i++) {
        int e = g[v][i];
        if (was[e] == 0) {
            h[e] = h[v] + 1;
            dfs(e);
            sum[v] += sum[e];
        }
    }
}
ll calc(int x, int y) {
    if (h[x] < h[y]) {
        return sum[y];
    } else {
        return -sum[x];
    }
}
int main()
{
    #ifdef home
        assert(freopen(TASK".in", "r", stdin));
        assert(freopen(TASK".out", "w", stdout));
    #endif
    scanf("%d %d %d", &n, &C, &m);
    for (int i = 0; i < n; i++) {
        go[i] = i;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        x--, y--;
        if (dsu_merge(x, y)) {
            g[x].pb(y);
            g[y].pb(x);
        }
    }
    vector<pair<pi, int> > ans;
    for (int it = 0; it < 2 * n * n; it++) {
        for (int i = 0; i < n; i++) {
            was[i] = 0;
        }
        for (int i = 0; i < n; i++) if (was[i] == 0) {
            dfs(i);
        }
        int mx = 0;
        int x1 = 0;
        int y1 = 0;        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < sz(g[i]); j++) {
                int e = g[i][j];
                ll d = calc(i, e);
                int can = min(a[i], C - a[e]);                
                if (d < 0) {                    
                    can = min((ll)can, -d);
                    if (can > mx) {
                        mx = can;
                        x1 = i;
                        y1 = e;
                    }
                }
            }
        }
        if (mx == 0) break;
        ans.pb(mp(mp(x1, y1), mx));
        a[x1] -= mx;
        a[y1] += mx;
    }
//    cerr<<sz(ans)<<endl;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            printf("NO\n");
            return 0;
        }
    }
    printf("%d\n", sz(ans));
    for (int i = 0; i < sz(ans); i++) {
        printf("%d %d %d\n", ans[i].x.x + 1, ans[i].x.y + 1, ans[i].y);
    }
    #ifdef home
        eprintf("Time: %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
    #endif
    return 0;
}