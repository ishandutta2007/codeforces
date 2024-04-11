#include <bits/stdc++.h>
using namespace std;

#define N 200100

int n, m, a[N], b[N], dp[N];
typedef pair <int, int> pii;
pii p[N], v[N];

bool check(int st, int g, int sz) {
    int x = lower_bound(v, v + sz, pii(st + g, 1e9), greater <pii> () ) -> second;
    return b[lower_bound(p + 1, p + m + 1, pii(x, 0))-p] >= g + 1;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
        scanf("%d", &m);
        for (int i = 1; i <= m; i ++) scanf("%d %d", &p[i].first, &p[i].second);
        sort(p + 1, p + m + 1);
        b[m+1] = 0;
        for (int i = m; i; i --) b[i] = max(b[i+1], p[i].second);
        dp[n+1] = 0;
        for (int i = n, sz = 0; i; i --) {
            while (sz && v[sz-1].second < a[i]) sz --;
            v[sz++] = pii(i, a[i]);
            int le = -1, ri = n - i + 1;
            while (ri - le > 1) {
                int mi = le + ri >> 1;
                if (check(i, mi, sz)) le = mi;
                else ri = mi;
            }
            if (le < 0) {
                dp[1] = -1; break;
            }
            else dp[i] = dp[i+le+1] + 1;
        }
        printf("%d\n", dp[1]);
    }

    return 0;
}