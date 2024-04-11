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
const int MAXN = 2e5 + 100;

int a[MAXN];
int d[MAXN];
int c[400];

int main() {
#ifdef LOCAL
    freopen("b.in", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    int n, t;
    scanf("%d%d", &n, &t);
    int mx = 0;
    FOR(i, n) {
        scanf("%d", &a[i]);
        c[a[i]]++;
        mx = max(mx, c[a[i]]);
    }
    int c = min(t, n + 1);
    FOR(i, c) {
        FOR(j, n) {
            a[i * n + j] = a[j];
        }
    }
    int M = c * n;
    FOR(i, M + 1)
        d[i] = INF;
    d[0] = 0;
    int mxl = 0;
    FOR(i, M) {
        int l = 0, r = M + 1;
        while (l < r - 1) {
            int m = (l + r) / 2;
            if (d[m] <= a[i]) {
                l = m;
            } else {
                r = m;
            }
        }
        d[l + 1] = min(d[l + 1], a[i]);
        mxl = max(mxl, l + 1);
    }
    int ans = mxl + mx * (t - c);
    cout << ans << '\n';




    
    return 0;
}