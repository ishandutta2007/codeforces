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

int n;
ll a[200005];
ll f[200005][18];

ll Gcd(ll A, ll b)
{
    if (b == 0) return A;
    return Gcd(b, A % b);
}

int log_2[200005];

ll query(int l, int r)
{
    int val = log_2[r-l+1];
    //printf("%d %d: %d %d\n", l, r, val, r - (1 << val) + 1);
    return Gcd(f[l][val], f[r - (1 << val) + 1][val]);
}

void work()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", a + i);
    }
    if (n == 1) {
        printf("1\n"); return;
    }
    for (int i = 1; i < n; i++) {
        f[i][0] = max(a[i+1] - a[i], a[i] - a[i+1]);
    }
    n--;
    for (int pwr = 1; (1 << pwr) <= n; pwr++) {
        for (int i = 1; i + (1 << pwr) - 1 <= n; i++) {
            f[i][pwr] = Gcd(f[i][pwr-1], f[i + (1 << (pwr-1))][pwr-1]);
        }
    }
    //printf("! %lld\n", query(3, 5));
    int l = 1;
    int ans = 0;
    for (int r = 1; r <= n; r++) {
        while (l <= r && query(l, r) == 1) l++;
        //rintf("%d %d\n", l, r);
        ans = max(ans, r - l + 2);
    }
    printf("%d\n", ans);
}

int main()
{
    for (int i = 0; i < 18; i++) {
        for (int j = (1 << i); j < min(1 << (i + 1), 200001); j++) {
            log_2[j] = i;
        }
    }
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}