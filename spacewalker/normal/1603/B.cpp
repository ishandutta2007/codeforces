#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int x, y; scanf("%d %d", &x, &y);
        ll q = y / x;
        ll r = (y - x * q) / 2;
        ll n = x * q + r;
        if (y < x) {
            n = x + y;
        }
//        printf("q %lld r %lld\n", q, r);
        printf("%lld\n", n);
        assert(n % x == y % n);
    }
}