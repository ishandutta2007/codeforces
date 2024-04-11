#include<bits/stdc++.h>
using namespace std;

#define N 200010

int n, a[N];

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    int ans = 0;
    for(int i = 1, j = 1; i <= n; i ++) {
        while(j <= n && a[j] <= a[i] + 5) j ++;
        ans = max(ans, j - i);
    }
    printf("%d\n", ans);
}