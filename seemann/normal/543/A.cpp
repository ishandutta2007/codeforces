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
#define print(a) cerr << #a << ": " << a << '\n';
#else
#define print(a)
#endif

typedef long long ll;
typedef long double ldb;

const int INF = 1e9;
const ldb EPS = 1e-8;
const ldb PI = acos(-1.0);
const int MAXN = 510;

int dp[MAXN][MAXN];
bool is[MAXN];
int mod;
inline void add(int & a, int b) {
    a += b;
    if (a >= mod)
        a -= mod;
}

int pr[MAXN][MAXN];
int a[MAXN];

int main() {
#ifdef LOCAL
    freopen("a.in", "r", stdin);
    //freopen("", "w", stdout);
    //freopen("", "w", stderr);
#endif
    int n, m, b;
    scanf("%d%d%d%d", &n, &m, &b, &mod);
    FOR(i, n) {
        scanf("%d", &a[i]);
//        is[a] = true;
    }
    pr[0][0] = 1;
    FOR(i, m) {
        FOR(j, n) {
            FOR(k, b + 1) {
                if (k + a[j] <= b) {
                    add(dp[j][k + a[j]], pr[j][k]);
                }
                add(pr[j + 1][k], pr[j][k]);
            }
        }
        FOR(j, n + 1)
            FOR(k, b + 1) {
                pr[j][k] = dp[j][k];
                dp[j][k] = 0;
            }
    }
    int ans = 0;
    FOR(j, n + 1)
        FOR(k, b + 1) {
            ans = (ans + pr[j][k]) % mod;
        }
    cout << ans << '\n';
    /*
    FOR(i, b + 1) {
        if (!is[i])
            continue;
        for (int j = m - 1; j >= 0; --j) {
            for (int k = b; k >= 0; --k) {
//                cerr << j << ' ' << k << ' ' << dp[j][k] << '\n';
                for (int g = 1; g + j <= m && g * i + k <= b; ++g) {
                    int nj = g + j;
                    int nk = g * i + k;
                    add(dp[nj][nk], dp[j][k] * a % mod);
                }
            }
        }
    }
    int ans = 0;
    FOR(i, b + 1) {
        add(ans, dp[m][i]);
    }*/
    
    return 0;
}