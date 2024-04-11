#include<bits/stdc++.h>
using namespace std;

int n, a[111];

int main() {
    scanf("%d", &n);
    a[n+1] = 1001;
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    int ans = 0, cur = 0;
    for(int i = 1; i <= n; i ++) {
        if(a[i+1] - a[i-1] == 2) cur ++;
        else cur = 0;
        if(cur > ans) ans = cur;
    }
    printf("%d\n", ans);
}