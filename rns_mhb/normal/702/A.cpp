#include<bits/stdc++.h>
using namespace std;

int a[100010];

int main() {
    int n, i, ans, len;
    scanf("%d", &n);
    scanf("%d", a + 1); ans = len = 1;
    for(i = 2; i <= n; i ++) {
        scanf("%d", a + i);
        if(a[i] > a[i - 1]) len ++, ans = max(ans, len);
        else len = 1;
    }
    printf("%d\n", ans);
}