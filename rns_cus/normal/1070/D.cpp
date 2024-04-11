#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long k, x = 0, y, ans;
    scanf("%d%I64d", &n, &k);
    for(int i = 1; i <= n; i ++) {
        scanf("%I64d", &y);
        long long cnt = (x + k - 1) / k;
        ans += cnt;
        x = x + y - cnt * k;
        if(x < 0) x = 0;
    }
    ans += (x + k - 1) / k;
    printf("%I64d\n", ans);
}