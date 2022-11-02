#include<bits/stdc++.h>
using namespace std;

long long g[11111];

int main()
{
    int n = 0, a, b, f, k, p, i, q;
    scanf("%d%d%d%d", &a, &b, &f, &k);
    g[0] = 0;
    g[1] = f;
    for(i = 2; i <= k; i ++) {
        g[i] = 1ll * 2 * (i - 1) * a - g[i - 1];
    }
    g[k + 1] = 1ll * k * a;
    p = 0;
    while(p <= k) {
        q = lower_bound(g, g + k + 2, g[p] + b) - g;
        if(g[q] != g[p] + b) q --;
        if(q == p) {
            printf("-1\n");
            return 0;
        }
        p = q;
        if(1 <= p && p <= k) n ++;
    }
    printf("%d\n", n);
}