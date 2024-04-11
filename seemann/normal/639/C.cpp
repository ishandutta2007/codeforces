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
    freopen("c.in", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    int n, k;
    scanf("%d%d", &n, &k);
    forn(i, n + 1)
        scanf("%d", &a[i]);
    int mx = n;
    ll inf = ((ll)1000 ) * k;
    ll down = 0;
    forn(i, n + 1) {
        down += a[i];
        if (down % 2 != 0) {
            mx = i;
            break;
        }
        if (i < n)
            down /= 2;
    }
    bool fail = false;
    ll rem = 0;
    for (int i = n; i > mx; --i) {
        rem += a[i];
        rem *= 2;
        if (abs(rem) > inf) {
            fail = true;
            break;
        }
    }
    if (fail) {
        cout << 0 << '\n';
        return 0;
    }
    ll ans = 0;
    rem += down;
    for (int i = mx; i >= 0; --i) {
        if (abs(a[i] - rem) <= k) {
            if (a[i] - rem != 0 || i != n)
                ans++;
        }
        rem *= 2;
        if (abs(rem) > inf)
            break;
    }
    cout << ans << '\n';
    return 0;
}