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
const int MAXN = 110;
const int MAXM = 1e5 + 100;


int rk[MAXN];
ldb dp[MAXM], dpn[MAXM];


int main() {
#ifdef LOCAL
    freopen("c.in", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    int s = 0;
    FOR(i, n) {
        scanf("%d", &rk[i]);
        rk[i]--;
        s += rk[i];
    }
    if (m == 1) {
        cout << fixed << setprecision(20) << 1.0L << '\n';
        return 0;
    }
    dp[0] = 1;
    FOR(i, n) {
        ldb sum = 0;
        int k = rk[i];
        FOR(j, s) {
            sum += dp[j];
            if (j - k >= 0)
                sum -= dp[j - k];
            dpn[j] += sum / (m - 1);
        }
        sum = 0;
        FOR(j, s) {
            if (j - k - 1 >= 0)
                sum += dp[j - k - 1];
            if (j - m >= 0)
                sum -= dp[j - m];
            dpn[j] += sum / (m - 1);
        }
        FOR(j, s) {
            dp[j] = dpn[j];
            dpn[j] = 0;
        }
    }
    ldb ans = 0;
    FOR(i, s)
        ans += dp[i];
    ans *= (m - 1);
    cout << fixed << setprecision(20) << ans + 1<< '\n';
        
    return 0;
}