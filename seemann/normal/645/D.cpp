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
const int MAXN = 1e5 + 100;
vector<int> e[MAXN];
int ef[MAXN], es[MAXN];
bool used[MAXN];
vector<int> ord;
void dfs(int v) {
    used[v] = true;
    for (auto u : e[v]) {
        if (!used[u])
            dfs(u);
    }
    ord.pb(v);
}

int n;
bool check(int m) {
    forn(i, n) {
        e[i].clear();
        used[i] = false;
    }
    forn(i, m) {
        e[ef[i]].pb(es[i]);
    }
    ord.clear();
    forn(i, n) {
        if (!used[i])
            dfs(i);
    }
    reverse(ord.begin(), ord.end());
    forn(i, n - 1) {
        bool flag = false;
        for (auto u : e[ord[i]]){
            if (u == ord[i + 1]) {
                flag = true;
                break;
            }
        }
        if (!flag)
            return false;
    }
    return true;
}
int main() {
#ifdef LOCAL
    freopen("d.in", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    int m;
    scanf("%d%d", &n, &m);
    forn(i, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        ef[i] = u, es[i] = v;
    }
    int l = 0, r = m + 1;
    while (l < r - 1) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    if (r > m ) {
        cout << -1 << '\n';
    } else {
        cout << r<< '\n';
    }

    return 0;
}