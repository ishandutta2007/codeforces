#include <bits/stdc++.h>
using namespace std;

#define N 500500

int m, k, n, s, a[N], cur[N], cnt[N];

bool solve() {
    int rem = 0, d = m - k * n;
    for (int i = 0; i < N; i ++) if (cnt[i]) rem ++;
    for (int i = 0, j = -1; i < m; i ++) {
        while (rem) {
            j ++;
            if (j >= m) break;
            cur[a[j]] ++;
            if (cur[a[j]] == cnt[a[j]]) rem --;
        }
        if (j >= m) break;
        if (max(j - i + 1 - k, 0) + i % k <= d) {
            d = max(j - i + 1 - k, 0);
            printf("%d\n", d + i % k);
            for (int x = 0; x < i % k; x ++) printf("%d ", x + 1);
            for (int x = i; x <= j && d; x ++) {
                if (!cnt[a[x]]) printf("%d ", x + 1), d --;
                else if (cnt[a[x]] < cur[a[x]]) printf("%d ", x + 1), d --, cur[a[x]] --;
            }
            return 0;
        }
        if (cnt[a[i]] && cur[a[i]] == cnt[a[i]]) rem ++;
        cur[a[i]] --;
    }
    return 1;
}

int main() {
    scanf("%d %d %d %d", &m, &k, &n, &s);
    for (int i = 0; i < m; i ++) scanf("%d", &a[i]);
    for (int i = 0, x; i < s; i ++) scanf("%d", &x), cnt[x] ++;
    if (solve()) puts("-1");
}