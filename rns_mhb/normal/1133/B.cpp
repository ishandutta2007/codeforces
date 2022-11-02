#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k, x, cnt[111] = {};
    scanf("%d%d", &n, &k);
    while(n --) {
        scanf("%d", &x);
        cnt[x%k] ++;
    }
    int ans = cnt[0] / 2 * 2;
    for(int i = 1, j = k - 1; i <= j; i ++, j --) {
        if(i == j) ans += cnt[i] / 2 * 2;
        else ans += 2 * min(cnt[i], cnt[j]);
    }
    printf("%d\n", ans);
}