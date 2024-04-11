#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int t, n;
ll k;

int main() {
    scanf("%d", &t);
    while (t --) {
        scanf("%d %I64d", &n, &k);
        int t = 1;
        while (t <= n && (1ll << t + 1) - t - 2 <= k) t ++;
        t --;
        if (n >= 31) printf("YES %d\n", n - t);
        else {
            ll x = (1ll << 2 * n) - (1ll << 2 * (n - t)) * ((1ll << t + 1) - 1) + (1ll << t + 1) - 2;
            assert(x % 3 == 0), x /= 3;
            if (x < k) puts("NO");
            else printf("YES %d\n", n - t);
        }
    }
}