#include <bits/stdc++.h>

const int ar[10] = {119, 18, 93, 91, 58, 107, 111, 82, 127, 123};

const int N = 3e3 + 5;

int n, k, a[N], ans[N];
char c[N][10];
bool f[N][N];

void dfs(int i, int x) {
    if (x > k) { return; }  
    if (f[i][x]) { return; }
    f[i][x] = true;
    if (i == n) {
        if (x == k) {
            for (int j = 0; j < n; j++) {
                printf("%d", ans[j]);
            }
            exit(0);
        } else {
            return;
        }
    }
    for (int j = 9; j >= 0; j--) {
        ans[i] = j;
        if ((ar[j] & a[i]) == a[i]) {
            dfs(i + 1, x + __builtin_popcount(ar[j] ^ a[i]));
        }
    }
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%s", c[i]);
        for (int j = 0; j < 7; j++) {
            a[i] = a[i] * 2 + (c[i][j] - '0');
        }
    }
    dfs(0, 0);
    printf("-1\n");
    return 0;
}