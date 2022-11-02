#include<bits/stdc++.h>
using namespace std;

int f[55][105], x[30], who[5005];

int main() {
    int a, b, c, d, e, n, i, j;
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &n);
    for(i = 1; i <= b; i ++) for(j = 1; j <= a; j ++) f[i][j] = (b - i) * a + j;
    for(i = 1; i <= b; i ++) if(!(i & 1)) reverse(f[i] + 1, f[i] + a + 1);
    for(i = 1; i <= d; i ++) for(j = 1; j <= c; j ++) f[i][j + a] = b * a + (i - 1) * c + j;
    for(i = 1; i <= d; i ++) if(!(i & 1)) reverse(f[i] + a + 1, f[i] + a + c + 1);
    for(i = 1; i <= n; i ++) scanf("%d", x + i), x[i] += x[i - 1];
    for(i = 1; i <= n; i ++) for(j = x[i - 1] + 1; j <= x[i]; j ++) who[j] = i;
    puts("YES");
    for(i = 1; i <= max(b, d); i ++) {
        for(j = 1; j <= a + c; j ++) {
            e = who[f[i][j]];
            putchar(e?e-1+'a':'.');
        }
        putchar('\n');
    }
}