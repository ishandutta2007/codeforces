#include <bits/stdc++.h>
using namespace std;

#define N 1000005

int n, m;
int a[N], b[N];
int cnt[N];
int ans, mx;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i ++) {
        scanf("%d", &a[i]);
        if (a[i] < N) cnt[a[i]] ++;
    }
    for (int i = 1; i < N; i ++) {
        for (int j = 1; i * j < N; j ++) {
            b[i*j] += cnt[i];
        }
    }
    for (int i = 1; i <= m; i ++) if (mx < b[i]) {
        mx = b[i];
        ans = i;
    }
    if (!ans) {
        printf("1 0\n");
        return 0;
    }
    printf("%d %d\n", ans, b[ans]);
    for (int i = 0; i < n; i ++) {
        if (ans % a[i] == 0) printf("%d ", i + 1);
    }
    return 0;
}