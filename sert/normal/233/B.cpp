#include <cstdio>
#include <cmath>

typedef long long ll;

ll ta;
ll get_sum(ll x) {
    ta = 0;
    while (x) {
        ta += x % 10;
        x /= 10;
    }
    return ta;
}

ll l, r, m, ans, n;

int main() {
    scanf("%I64d", &n);
    ans = n + 34;
    for (ll i = 1; i < 2014; i++) {
        l = 1;
        r = sqrt(n) + 5;
        while (r - l > 1) {
            m = (l + r) / 2;
            if (m * m + i * m <= n)
                l = m;
            else
                r = m;
        }
        //printf("%d\n", l);
        if (get_sum(l) == i && l < ans && l * l + i * l == n)
            ans = l;        
    }
    if (ans == n + 34)
        printf("-1\n");
    else
        printf("%I64d\n", ans);
}