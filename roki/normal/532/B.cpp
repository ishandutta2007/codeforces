#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <list>
#include <iomanip>
#include <stack>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <ctime>

#define all(a) a.begin(),a.end()
#define pb push_back
#define mp make_pair
#define forn(i,n) for(int i = 0; i < int(n); ++i)
#define sz(a) int(a.size())

using namespace std;

typedef long long li;
typedef long double ld;

typedef pair<int,int> pt;
#define ft first
#define sc second

const int N = 400 * 1000 + 5;

int n, a[N];

li dp[N][2];
vector <int> g[N];

li calcdp(int v, int b) {
    li& res = dp[v][b];

    if (res != -1)
        return res;

    li tdp[2][2];

    forn(i, 2)
        forn(j, 2)
            tdp[i][j] = -1e18;

    int t = 0;
    tdp[t][0] = 0;

    forn(i, sz(g[v])) {
        int to = g[v][i];

        forn(k, 2)
            tdp[!t][k] = -1e18;

        forn(k, 2) {
            li d = calcdp(to, k);
            forn(j, 2) {
                int nj = (j + k) % 2;
                tdp[!t][nj] = max(tdp[!t][nj], tdp[t][j] + d);
            }
        }

        t = !t;
    }

    dp[v][0] = tdp[t][0];
    dp[v][1] = max(tdp[t][1], tdp[t][0] + a[v]);
    
    return dp[v][b];
}

bool read() {
    if (scanf("%d", &n) != 1)
        return false;

    forn(i, n) {
        int p;
        scanf("%d%d", &p, &a[i]);
        --p;
        if (p >= 0)
            g[p].pb(i);
    }

    return true;
}

void solve() {
    memset(dp, -1, sizeof dp);
    li ans = -1;

    forn(t, 2)
        ans = max(ans, calcdp(0, t));

    printf("%I64d\n", ans);
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif

#ifdef TASK_NAME
    freopen(TASK_NAME ".in", "r", stdin);
    freopen(TASK_NAME ".out", "w", stdout);
#endif

    while (read())
        solve();
    
    return 0;
}