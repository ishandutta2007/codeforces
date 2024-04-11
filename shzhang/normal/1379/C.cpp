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

ll a[100005];
ll a2[100005];
ll a2psum[100005];
ll b[100005];

void work(void)
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%lld%lld", a + i, b + i);
        a2[i] = a[i];
    }

    sort(a2 + 1, a2 + m + 1);
    reverse(a2 + 1, a2 + m + 1);

    ll ans = 0;
    for (int i = 1; i <= m; i++) {
        a2psum[i] = a2psum[i-1] + a2[i];
        if (i <= n) ans = max(ans, a2psum[i]);
    }
    a2[0] = 1500000000;
    for (int i = 1; i <= m; i++) {
        int l = 0; int r = m;
        while (l < r) {
            int mid = (l + r) / 2 + 1;
            if (a2[mid] >= b[i]) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        l = min(l, (a[i] < b[i] ? n-1 : n));
        ans = max(ans, a2psum[l] + (a[i] < b[i] ? a[i] + (n - l - 1) * b[i] : (n - l) * b[i]));
    }
    printf("%lld\n", ans);
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}