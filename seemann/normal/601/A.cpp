#include <cassert>
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

using namespace std;

#define FOR(a, b) for (int a = 0; a < (b); ++a)
#define clr(a) memset(a, 0, sizeof(a))
#define pb(i) push_back(i)
#define forab(i, a, b) for(int i = int(a); i < int(b); ++i)
#define forba(i, b, a) for(int i = int(b) - 1; i >= int(a); --i)
#define forn(i, n) forab(i, 0, n)
#ifdef LOCAL
#define debug(a) cerr << #a << ": " << a << '\n';
#else
#define debug(a)
#endif

typedef long long ll;
typedef long double ldb;

const int INF = 1e9;
const ldb EPS = 1e-8;
const ldb PI = acos(-1.0);
const int MAXN = 510;

bool used[MAXN];
int d[MAXN];

int e[MAXN][MAXN];

int main() {
#ifdef LOCAL
    freopen("a.in", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    FOR(i, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        e[u][v] = e[v][u] = 1;
    }
    if (e[0][n - 1] == 1) {
        FOR(i, n)
            FOR(j, n) {
                if (i != j) {
                    e[i][j] = 1 - e[i][j];
                }
            }
    }
    /*
    FOR(i, n) {
        FOR(j, n) {
            cerr << e[i][j] << ' ' ;
        }
        cerr << '\n';
    }*/
    queue<int> q;
    used[0] = true;
    d[0] = 0;
    q.push(0);
    while (!q.empty()) {
        int v = q.front();
       // cerr << v << '\n';
        q.pop();
        FOR(u, n) {
            if(e[v][u] == 0 || used[u])
                continue;
            used[u] = true;
            d[u] = d[v] + 1;
            q.push(u);
        }
    }
    if (!used[n - 1])
        printf("-1\n");
    else
        printf("%d\n", d[n - 1]);

        
    return 0;
}