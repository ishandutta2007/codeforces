#include<bits/stdc++.h>
using namespace std;

bool a[300010];

int main() {
    int b, l = 1, r = 1, n, k, i, gas = 0, ans = 0, pos = 0;
    scanf("%d%d", &n, &k);
    for(i = 1; i <= n; i ++) scanf("%d", &b), a[i] = b;
    a[n + 1] = 0;
    for( ; r <= n; r ++) {
        if(!a[r]) gas ++;
        while(gas > k) {
            if(!a[l]) gas --;
            l ++;
        }
        if(r - l + 1 > ans) ans = r - l + 1, pos = l;
    }
    for(i = 0; i < ans; i ++) a[pos + i] = 1;
    printf("%d\n", ans);
    for(printf("%d", a[1]), i = 2; i <= n; i ++) printf(" %d", a[i]); puts("");
}