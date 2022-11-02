#include <bits/stdc++.h>
using namespace std;

#define N 200200

int n, m, ta, tb, k, a[N], b[N];

int main() {
    scanf("%d %d %d %d %d", &n, &m, &ta, &tb, &k);
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    for (int i = 1; i <= m; i ++) scanf("%d", &b[i]);
    if (k >= n || k >= m) puts("-1");
    else {
        int ans = 0;
        for (int i = 0, j = 1, p; i <= k; i ++) {
            while (j <= m && b[j] < a[i+1] + ta) j ++;
            if (j + k - i > m) return puts("-1"), 0;
            ans = max(ans, b[j+k-i] + tb);
        }
        printf("%d\n", ans);
    }
    return 0;
}