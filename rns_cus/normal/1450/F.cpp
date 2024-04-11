#include <bits/stdc++.h>
using namespace std;

#define N 100100

int n, a[N], cnt[N];

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
        for (int i = 1; i <= n; i ++) cnt[i] = 0;
        for (int i = 1; i <= n; i ++) cnt[a[i]] ++;
        if (*max_element(cnt + 1, cnt + n + 1) * 2 > n + 1) {
            puts("-1"); continue;
        }
        for (int i = 1; i <= n; i ++) cnt[i] = 0;
        int tot = 0;
        for (int i = 1; i < n; i ++) if (a[i] == a[i+1]) cnt[a[i]] += 2, tot ++;
        cnt[a[1]] ++, cnt[a[n]] ++;
        printf("%d\n", tot + max(0, *max_element(cnt + 1, cnt + n + 1) - tot - 2));
    }

    return 0;
}