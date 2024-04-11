#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

#define ll long long

#ifndef ONLINE_JUDGE
#define debug(format, ...) fprintf(stderr, \
    "%s:%d: " format "\n", __func__, __LINE__,##__VA_ARGS__)
#else
#define debug(format, ...)
#define NDEBUG
#endif

#define MOD 1000000007
#define mul(a, b) (((ll)(a) * (ll)(b)) % MOD)

int fpow(int base, int exponent)
{
    int ans = 1;
    int cur = base;
    while (exponent) {
        if (exponent & 1) ans = mul(ans, cur);
        cur = mul(cur, cur); exponent >>= 1;
    }
    return ans;
}

int n;
int a[20];
int p[20][20];
int all_win[100000][20];
int strong[100000];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                p[i][j] = mul(a[i], fpow(a[i] + a[j], MOD - 2));
            }
        }
    }
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            all_win[i][j] = 1;
            for (int k = 0; k < n; k++) {
                if (i & (1 << k)) {
                    all_win[i][j] = mul(all_win[i][j],
                        p[k][j]);
                }
            }
        }
    }
    for (int i = 1; i < (1 << n); i++) {
        strong[i] = 1;
        for (int j = ((i - 1) & (i)); j > 0; j--, j &= i) {
            int val = strong[j];
            for (int k = 0; k < n; k++) {
                if ((i - j) & (1 << k)) {
                    val = mul(val, all_win[j][k]);
                }
            }
            strong[i] -= val;
            if (strong[i] < 0) strong[i] += MOD;
        }
    }
    int ans = 0;
    for (int i = 1; i < (1 << n); i++) {
        int prob = strong[i];
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (!(i & (1 << j))) {
                prob = mul(prob, all_win[i][j]);
            } else {
                cnt++;
            }
        }
        ans += mul(prob, cnt);
        if (ans >= MOD) ans -= MOD;
    }
    printf("%d", ans);
    return 0;
}