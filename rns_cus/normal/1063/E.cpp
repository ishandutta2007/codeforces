#include <bits/stdc++.h>
using namespace std;

#define N 1010

int n, a[N], vis[N];
char s[N][N];

int main() {
    scanf("%d", &n);
    int fg = 0;
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]), fg += abs(a[i] - i);
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++) s[i][j] = '.';
    if (!fg) {
        printf("%d\n", n);
        for (int i = 1; i <= n; i ++) puts(s[i] + 1);
    }
    else {
        printf("%d\n", n - 1);
        int cnt = 0;
        for (int i = n; i; i --) {
            if (a[i] == i) continue;
            if (!vis[i]) {
                int x = 0, sz = 0;
                for (int j = i; !vis[j]; j = a[j]) vis[j] = 1, x = max(x, j), sz ++;
                if (x < n) {
                    s[cnt+sz][x] = s[cnt+sz][n] = '/';
                    s[cnt+1][n] = s[cnt+1][a[x]] = '\\';
                }
                x = a[x];
                for (int i = 2; i <= sz; i ++, x = a[x]) {
                    char c = x > a[x] ? '\\' : '/';
                    s[cnt+i][x] = s[cnt+i][a[x]] = c;
                }
                cnt += sz;
            }
        }
        for (int i = 1; i <= n; i ++) puts(s[i] + 1);
    }
}