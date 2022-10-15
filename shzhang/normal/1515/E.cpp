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

#define mul(i, j) (((ll)(i) * (ll)(j)) % M)

int n, M;

int f[405][405];
int fact[405];
int ifact[405];

int fpow(int base, int exponent)
{
    int ans = 1;
    int cur = base;
    while (exponent) {
        if (exponent & 1) ans = mul(ans, cur);
        cur = mul(cur, cur);
        exponent >>= 1;
    }
    return ans;
}

int pwr2[1005];

int main()
{
    scanf("%d%d", &n, &M);
    pwr2[0] = 1;
    for (int i = 1; i <= 1000; i++) {
        pwr2[i] = mul(pwr2[i-1], 2);
    }
    fact[0] = 1;
    for (int i = 1; i <= 404; i++) {
        fact[i] = mul(fact[i-1], i);
        ifact[i] = fpow(fact[i], M - 2);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (i == j) {
                f[i][j] = mul(ifact[i], pwr2[i - 1]);
            }
            for (int k = 1; k < i; k++) {
                if (j - (i - k) < 0) continue;
                f[i][j] += mul(f[k-1][j - (i - k)], mul(ifact[i - k], pwr2[i - k - 1]));
                if (f[i][j] >= M) f[i][j] -= M;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        //printf("%d\n", f[n][i]);
        ans += mul(f[n][i], fact[i]);
        if (ans >= M) ans -= M;
    }
    printf("%d", ans);
    return 0;
}