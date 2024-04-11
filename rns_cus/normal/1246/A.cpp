#include <bits/stdc++.h>
using namespace std;

#define N 100100

int n, p, k;

int main() {
    scanf("%d %d", &n, &p);
    bool fg = 0;
    for (k = 1; k < N; k ++) {
        int x = n - p * k;
        if (x >= k && __builtin_popcount(x) <= k) {
            fg = 1; break;
        }
    }
    if (!fg) puts("-1");
    else printf("%d\n", k);

    return 0;
}