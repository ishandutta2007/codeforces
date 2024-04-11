#include<bits/stdc++.h>
using namespace std;

#define N 2010

int n, d, b[N];

int main() {
    scanf("%d%d", &n, &d);
    for(int i = 1; i <= n; i ++) scanf("%d", &b[i]);
    int ans = 0;
    for(int i = 2; i <= n; i ++) {
        if(b[i] > b[i-1]) continue;
        int cnt = (b[i-1] - b[i]) / d + 1;
        ans += cnt;
        b[i] += d * cnt;
    }
    printf("%d\n", ans);
}