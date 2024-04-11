#include <bits/stdc++.h>
using namespace std;

const int M = 5001;

int ans[M];
int cnt;

int main() {
    //freopen("B.in", "r", stdin);
    int n, k;
    scanf("%d %d", &n, &k);
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if(k <= n || n == 4) return puts("-1");
    ans[cnt ++] = a;
    ans[cnt ++] = c;
    for(int i = 1; i <= n; i ++) {
        if(i == a || i == b || i == c || i == d) continue;
        ans[cnt ++] = i;
    }
    ans[cnt ++] = d;
    ans[cnt ++] = b;
    for(int i = 0; i < cnt; i ++) printf("%d ", ans[i]); puts("");
    printf("%d %d", c, a);
    for(int i = 2; i < cnt - 2; i ++) printf(" %d", ans[i]);
    printf(" %d %d\n", ans[cnt-1], ans[cnt-2]);
}