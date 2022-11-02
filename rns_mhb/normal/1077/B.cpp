#include<bits/stdc++.h>
using namespace std;

int n, a[111];

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    int ans = 0;
    for(int i = 2; i < n; i ++) if(a[i-1] == 1 && a[i] == 0 && a[i+1] == 1) {
        ans ++;
        a[i+1] = 0;
    }
    printf("%d\n", ans);
}