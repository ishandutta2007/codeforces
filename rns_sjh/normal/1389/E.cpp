#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while(t --) {
        int m, d, w;
        scanf("%d%d%d", &m, &d, &w);
        int k = min(m, d);
        int u = w / __gcd(d - 1, w);
        long long ans;
        int q = (k - 1) / u;
        ans = 1ll * q * k - 1ll * u * q * (q + 1) / 2;
        printf("%I64d\n", ans);
    }
}