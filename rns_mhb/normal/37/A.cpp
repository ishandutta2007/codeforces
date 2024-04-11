#include<bits/stdc++.h>
using namespace std;

int a[1010];

int main() {
    int n, i, x, gas = 0, ans = 0;
    scanf("%d", &n);
    for(i = 1; i <= n; i ++) {
        scanf("%d", &x);
        if(a[x] == 0) gas ++;
        a[x] ++;
        ans = max(ans, a[x]);
    }
    printf("%d %d\n", ans, gas);
}