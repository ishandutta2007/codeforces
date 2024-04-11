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
ll altsum[200005];
ll psum[200005];

ll tot;

ll work2(bool left_p, bool right_c)
{
    ll ans = 0;
    for (int i = (left_p ? 4 : 3); i <= (right_c ? n - 2 : n - 1); i++) {
        int l = (left_p ? 3 : 2) - 1; int r = i - 1;
        while (l < r) {
            int mid = (l + r) / 2 + 1;
            ll cval = psum[mid] + altsum[i - 1] - altsum[(i - 1) % 2 == mid % 2 ? mid : mid - 1] - (left_p ? a[1] : 0) + (right_c ? a[n] : 0);
            if (cval * 2 < tot) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        int far_left = (left_p ? 3 : 2);
        if (l >= far_left) {
            //printf("%d add %d\n", i, (l - far_left + 2) / 2);
            ans += (l - far_left + 2) / 2;
        }
    }
    //printf("return %lld\n", ans);
    return ans;
}

void work()
{
    scanf("%d", &n);
    tot = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", a + i); tot += a[i];
        altsum[i] = a[i] + (i >= 3 ? altsum[i-2] : 0);
        psum[i] = a[i] + psum[i-1];
    }
    if (n == 1) {
        printf("1\n"); return;
    }
    ll ans = 1;
    if (tot % 2LL == 0 && altsum[n] == tot / 2LL) ans--;
    for (int i = 1; i < n; i++) {
        ll val_1 = tot - psum[i-1] + (i >= 3 ? altsum[i-2] : 0);
        if (val_1 * 2LL > tot) ans++;
        if (i < n - 1) {
            ll val_2 = val_1 - a[n];
            if (val_2 * 2LL > tot) ans++;
        }
    }
    for (int j = 2; j <= n; j++) {
        ll val_1 = altsum[j % 2 == n % 2 ? n : n - 1] - altsum[j] + psum[j];
        if (val_1 * 2LL < tot) ans++;
        if (j >= 3) {
            ll val_2 = val_1 - a[1];
            if (val_2 * 2LL < tot) ans++;
        }
    }
    //printf("! %lld\n", ans);
    if (n >= 4) {
        for (int i = 2; i < n - 1; i++) {
            if (2LL * psum[i] > tot) ans++;
        }
        ans += work2(false, false);
        //printf("! %lld\n", ans);
        ans += work2(false, true);
        //printf("! %lld\n", ans);
        ans += work2(true, false);
        //printf("! %lld\n", ans);
        ans += work2(true, true);
    }
    printf("%lld\n", ans % 998244353);
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}