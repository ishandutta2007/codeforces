#include <bits/stdc++.h>
using namespace std;

#define N 2020

int n, deg[N], tmp[N], cnt[N];
char s[N][N], t[N][N];

bool check() {
    for (int i = 0; i < n; i ++) cnt[i] = 0;
    for (int i = 1; i <= n; i ++) cnt[deg[i]] ++;
    for (int k = 1, sum = 0, j = n - 1; k < n; k ++) {
        while (!cnt[j]) j --; sum += j, cnt[j] --;
        if (sum == k * (k - 1) / 2 + k * (n - k)) return 0;
    }
    return 1;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) scanf("%s", s[i] + 1);
    if (n < 7) {
        int m = 1 << n, ans = n + 1, cnt = 0;
        for (int i = 0; i < m; i ++) {
            int x = __builtin_popcount(i);
            if (ans < x) continue;
            for (int p = 0; p < n; p ++) for (int q = 0; q < n; q ++) {
                t[p+1][q+1] = s[p+1][q+1];
                if ((i >> p & 1) ^ (i >> q & 1)) t[p+1][q+1] ^= 1;
            }
            for (int i = 1; i <= n; i ++) deg[i] = 0;
            for (int i = 1; i <= n; i ++) for (int j = 1; j <= n; j ++) if (t[i][j] == '1') deg[i] ++;
            if (check()) {
                if (x < ans) ans = x, cnt = 1;
                else cnt ++;
            }
        }
        if (ans > n) puts("-1");
        else {
            for (int i = 1; i <= ans; i ++) cnt *= i;
            printf("%d %d\n", ans, cnt);
        }
        return 0;
    }
    for (int i = 1; i <= n; i ++) for (int j = 1; j <= n; j ++) if (s[i][j] == '1') deg[i] ++;
    if (check()) puts("0 1");
    else {
        for (int i = 1; i <= n; i ++) tmp[i] = deg[i];
        int cnt = 0;
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= n; j ++) deg[j] = tmp[j];
            deg[i] = n - 1 - deg[i];
            for (int j = 1; j <= n; j ++) if (i != j)
                if (s[i][j] == '1') deg[j] ++;
                else deg[j] --;
            if (check()) cnt ++;
        }
        printf("1 %d\n", cnt);
    }

    return 0;
}