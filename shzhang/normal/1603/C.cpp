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

#define MOD 998244353
#define mul(a, b) (((ll)(a) * (ll)(b)) % MOD)

int n;
int a[100005];
int pieces[100005];
int val[100005];
int f[100005][305];

static inline int updiv(int x, int y)
{
    if (x % y == 0) return x / y;
    return x / y + 1;
}

void work()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 300; j++) {
            int p = updiv(a[i], j);
            f[i][j] = f[i-1][a[i] / p] + mul(p - 1, i);
            if (f[i][j] >= MOD) f[i][j] -= MOD;
            //if (j < 6) printf("%d %d: %d\n", i, j, f[i][j]);
        }
    }
    int ans = 0;
    int left = 0;
    int addval = 0;
    for (int r = 1; r <= n; r++) {
        val[r] = a[r];
        pieces[r] = 1;
        for (int l = r - 1; l > left; l--) {
            int newp = updiv(a[l], val[l+1]);
            if (newp == pieces[l]) break;
            //printf("here %d ", addval);
            //addval -= pieces[l]; addval += newp;
            addval += mul(newp - pieces[l], l);
            if (addval >= MOD) addval -= MOD;
            pieces[l] = newp;
            val[l] = a[l] / pieces[l];
        }
        /*printf("addval %d\n", addval);
        for (int i = left; i <= r; i++) {
            printf("val[%d] = %d\n", i, val[i]);
            printf("pieces[%d] = %d\n", i, pieces[i]);
        }*/
        while (left < r - 1 && val[left + 2] <= 300) {
            left++;
            if (left)
                addval -= mul(pieces[left] - 1, left);
            if (addval < 0) addval += MOD;
        }
        //printf("addval %d, left %d, f %d\n", addval, left, f[left][val[left + 1]]);
        ans += addval;
        if (ans >= MOD) ans -= MOD;
        if (left) {
            ans += f[left][val[left + 1]];
            if (ans >= MOD) ans -= MOD;
        }
    }
    printf("%d\n", ans);
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}