#include <bits/stdc++.h>
using namespace std;

#define N 2020

int n, b[N], a[N], x, ans[N*N][2], cnt, sum;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) scanf("%d", &x), b[x] = i;
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &x);
        a[b[x]] = i - b[x];
        if (a[b[x]] > 0) sum += a[b[x]];
    }
    printf("%d\n", sum);
    for (int i = n; i; i --) {
		for (int j = i + 1, k = i; a[k] > 0 && j <= n; j ++) if (a[j] < 0) {
            ans[++cnt][0] = k;
            ans[cnt][1] = j;
            swap(a[j], a[k]);
            a[j] -= j - k; a[k] += j - k;
            k = j;
        }
    }
    printf("%d\n", cnt);
    for (int i = 1; i <= cnt; i ++) printf("%d %d\n", ans[i][0], ans[i][1]);
}