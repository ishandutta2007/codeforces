#include<bits/stdc++.h>
using namespace std;

int a[111];
bool e[111][111];

int main() {
    int n, m, i, j, k, ans = 1e9;
    scanf("%d%d", &n, &m);
    for(i = 1; i <= n; i ++) scanf("%d", a + i);
    while(m --) {
        scanf("%d%d", &i, &j);
        e[i][j] = e[j][i] = 1;
    }
    for(i = 1; i < n; i ++) for(j = i + 1; j < n; j ++) for(k = j + 1; k <= n; k ++)
        if(e[i][j] == 1 && e[i][k] == 1 && e[j][k] == 1) ans = min(ans, a[i] + a[j] + a[k]);
    if(ans == 1e9) ans = -1;
    printf("%d\n", ans);
}