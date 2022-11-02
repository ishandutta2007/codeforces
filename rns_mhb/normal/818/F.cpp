#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int q, n;
ll ans;

void update(int t) {
    if (t >= 0 && t < n) {
        ans = max(ans, t + min(1ll * t, 1ll * (n - t) * (n - t - 1) / 2));
    }
}

int main() {
    scanf("%d", &q);
    while (q --) {
        scanf("%d", &n);
        ans = n - 1;
        int t = n + 0.5 - sqrt((long double)(8.0 * n + 1)) / 2;
        update(t), update(t + 1);
        printf("%I64d\n", ans);
    }
    return 0;
}