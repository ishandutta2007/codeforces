#include <bits/stdc++.h>
using namespace std;
#define f1(i, a, b) for (int i = a; i <= b; i ++)

#define N 1000005

const int mod = 1e9 + 7;

int n, a[N], b[N], coe = 1;

int inv[N] = {0, 1};

void init() {
	f1(i, 2, n) {
        inv[i] = 1ll * (mod / i) * (mod - inv[mod % i]) % mod;
        coe = 1ll * coe * i % mod;
	}
    return;
}

int main() {
    scanf("%d", &n);
    init();
    f1(i, 1, n) scanf("%d", &a[i]), b[i] = a[i];
    sort(b + 1, b + n + 1);
    int ans = 0;
    f1(i, 1, n) {
        if (a[i] == b[n]) continue;
        int k = lower_bound(b + 1, b + n + 1, a[i]) - b - 1;
        ans = (ans + 1ll * inv[n-k] * a[i]) % mod;
        if (ans >= mod) ans -= mod;
    }
    ans = 1ll * ans * coe % mod;
    printf("%d\n", ans);
	return 0;
}