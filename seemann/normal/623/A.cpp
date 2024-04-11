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

vector<int> e[MAXN];

char s[MAXN];

bool fail = false;

void dfs(int v) {
    s[v] = 'a';
    for (auto u : e[v]) {
        if (s[u])
            continue;
        dfs(u);
    }
}



int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    forn(i, m)  {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        e[u].pb(v);
        e[v].pb(u);
    }
    forn(i, n) {
        if (e[i].size() == n - 1) {
            s[i] = 'b';
        }
    }
    forn(i, n) {
        if (!s[i]) {
            dfs(i);
            break;
        }
    }
    forn(i, n)
        if (!s[i])
            s[i] = 'c';
    int ca = 0, cb = 0,cc= 0;
    forn(i, n) {
        if (s[i] == 'a')
            ca++;
        if (s[i] == 'b')
            cb++;
        if (s[i] == 'c')
            cc++;
    }
    forn(i, n) {
        if (s[i] == 'a') {
            if (e[i].size() != ca + cb - 1)
                fail = true;
        }
        if (s[i] == 'c') {
            if (e[i].size() != cc + cb - 1)
                fail = true;
        }
    }
    if (fail)
        printf("No\n");
    else {
        printf("Yes\n");
        printf("%s\n", s);
    }

    
    return 0;
}