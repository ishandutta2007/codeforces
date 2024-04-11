#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll s, x;
ll ans;

int main() {
    scanf("%I64d %I64d", &s, &x);
    if ((s - x) % 2 || s < x || ((s - x) >> 1) & x) return puts("0"), 0;
    bool fg = s == x;
    ans = 1;
    while (x) {
        if (x & 1) ans *= 2;
        x >>= 1;
    }
    if (fg) ans -= 2;
    printf("%I64d\n", ans);
    return 0;
}