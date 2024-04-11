#include <bits/stdc++.h>
using namespace std;
int n;
int x;

int solve() {
    n++;
    for (int y = x - 1; y >= 2 && y >= x - 100; y--) if (__gcd(n, y) == 1) {
        for (int z = 1, t = 1; t < n - 1; t++) {
            z = 1ll * z * y % n;
            if (z == 1) {
                goto la;
            }
        }
        return y;
        la:;
    }
    return -1;
}

int main() {
    scanf("%d %d", &n, &x);
    printf("%d\n", solve());
    return 0;
}