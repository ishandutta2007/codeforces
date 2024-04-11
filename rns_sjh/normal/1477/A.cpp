#include<bits/stdc++.h>
using namespace std;

int t, n;
long long x, y, k;

int main() {
    for(scanf("%d", &t); t --; ) {
        scanf("%d%lld", &n, &k);
        long long d = 0;
        scanf("%lld", &x);
        for(int i = 1; i < n; i ++) scanf("%lld", &y), d = __gcd(d, abs(x - y));
        if(d == 0) {
            puts(x == k ? "YES" : "NO");
        }
        else puts(abs(x - k) % d == 0 ? "YES" : "NO");
    }
}