#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdint>
#include <cstddef>
#include <queue>

using namespace std;

constexpr size_t MAXN = (size_t) 1e5 + 5;

int a[MAXN], b[MAXN];

int main()
{
    int T; scanf("%d", &T);
    while (T--) {
        int asum = 0, bsum = 0;

        int n; scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", a + i);
            asum += a[i];
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", b + i);
            bsum += b[i];
        }

        sort(a + 1, a + n + 1);
        sort(b + 1, b + n + 1);

        for (int i = 1; i <= n / 4; i++) {
            asum -= a[i];
            bsum -= b[i];
        }

        int ans = 0;

        while (asum < bsum) {
            int prek = ans + n;

            ans++;

            int k = ans + n;

            asum += 100;
            for (int i = prek / 4 + 1; i <= k / 4 && i <= n; i++) {
                asum -= a[i];
            }
            for (int i = n - (prek - prek / 4); i >= n - (k - k / 4) + 1 && i >= 1; i--) {
                bsum += b[i];
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}