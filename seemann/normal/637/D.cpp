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
const int MAXN = 2e5 + 1000;

int a[MAXN];

int main() {
#ifdef LOCAL
    freopen("d.in", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    int n, m, s, d; 
    scanf("%d%d%d%d", &n, &m, &s, &d);
    forn(i, n) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    int pr = 0;
    vector<pair<int, int>> ans;
    bool fly = false;
    forn(i, n) {
        if (!fly) {
            if (a[i] - pr - 1 < s) {
                printf("IMPOSSIBLE\n");
                return 0;
            }
            if (a[i] - 1 != pr) {
                ans.push_back({0, a[i] - 1 - pr});
            }
            fly = true;
            pr = a[i] - 1;
        }
        if (fly) {
            if (i == n - 1 || a[i + 1] - a[i] >= s + 2) {
                int dist = a[i] + 1 - pr;
                if (dist > d) {
                    printf("IMPOSSIBLE\n");
                    return 0;
                }
                fly = false;
                ans.push_back({1, dist});
                pr = a[i] + 1;
            }
        }
    }
    assert(!fly);
    if (pr < m) {
        ans.push_back({0, m - pr});
    }
    for (auto p : ans) {
        printf(p.first == 1 ? "JUMP " : "RUN ");
        printf("%d\n", p.second);
    }
    return 0;
}