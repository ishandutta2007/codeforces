#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define ll long long

using namespace std;

const int N = 200500;
const int inf = 1e9 + 50;
const int mod = 998244353;

pii ans[N];

int main() {
    int tcase;
    scanf("%d", &tcase);
    while (tcase--) {
        int n, k;
        scanf("%d%d", &n, &k);
        if (n == 4 && k == n - 1) {
            printf("-1\n");
            continue;
        }
        int tot = 0;
        if (k != n - 1) {
            ans[tot++] = pii(k, n - 1);
            if (k) ans[tot++] = pii(0, n - k - 1);
            for (int i = 1; i < n / 2; i++) {
                if (i == k || i == n - k - 1) continue;
                ans[tot++] = pii(i, n - i - 1);
            }
        }
        else {
            ans[tot++] = pii(k / 2, n - 1);
            ans[tot++] = pii(n / 2, n - 2);
            ans[tot++] = pii(0, 1);
            for (int i = 2; i < n / 2 - 1; i++) {
                if (i == k || i == n - k - 1) continue;
                ans[tot++] = pii(i, n - i - 1);
            }
        }
        sort(ans, ans + tot);
        for (int i = 0; i < tot; i++) {
            printf("%d %d\n", ans[i].fi, ans[i].se);
        }
    }

    return 0;
}