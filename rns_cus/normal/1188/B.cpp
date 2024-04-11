#include <bits/stdc++.h>
using namespace std;

#define N 300300

int n, p, k, a[N];

map <int, int> mp;

int main() {
    scanf("%d %d %d", &n, &p, &k);
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    for (int i = 2; i * i <= p; i ++) assert(p % i != 0);
    for (int i = 1; i <= n; i ++) {
        int b = 1ll * a[i] * a[i] % p;
        b = (1ll * b * b - 1ll * k * a[i]) % p;
        if (b < 0) b += p;
        mp[b] ++;
    }
    long long rlt = 0;
    for (auto x : mp) rlt += 1ll * x.second * (x.second - 1) / 2;
    printf("%I64d\n", rlt);
}