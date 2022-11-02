#include <bits/stdc++.h>
using namespace std;

#define N 500500

int n, a[N], prv[N], mx[N], nx[N];

typedef long long ll;
ll ans;

inline void update(int k, int v) {
    if (nx[k] >= v) return;
    nx[k] = v;
    if (v > mx[k]) swap(nx[k], mx[k]);
}

int solve(int y) {
    int up = (N - 1) / y + 1;
    ll cnt = 0, rlt = 0; mx[up] = nx[up] = -1;
    for (int k = up - 1; ~k; k --) {
        cnt += 1ll * k * (a[k*y] - a[min(N-1,(k+1)*y)]);
        int p = prv[min(N,(k+1)*y)-1];
        mx[k] = mx[k+1], nx[k] = nx[k+1];
        if (p < k * y) continue;
        update(k, p - k * y);
        if (a[p] > a[p+1] + 1) update(k, p - k * y);
        else if (p) update(k, prv[p-1] - k * y);
    }
    for (int k = 0; k < up; k ++) {
        if (mx[k] >= 0) rlt = max(rlt, min(cnt - k, 1ll * k * y + mx[k] >> 1));
        if (nx[k] >= 0) rlt = max(rlt, min(cnt - 2 * k, 1ll * k * y + nx[k]));
        ll x = 1ll * k * y + mx[k];
        if (mx[k] >= 0 && a[x] > 1) rlt = max(rlt, min(cnt - 2 * k - 1, x));
    }
    if (rlt < 2) rlt = 0;
    return rlt;
}

int main() {
    scanf("%d", &n);
    for (int i = 0, x; i < n; i ++) scanf("%d", &x), a[x] ++, prv[x] = x;
    for (int i = 1; i < N; i ++) if (!prv[i]) prv[i] = prv[i-1];
    for (int i = N - 2; ~i; i --) a[i] += a[i+1];
    for (int y = 2; y < N; y ++) ans = max(ans, 1ll * solve(y) * y);
    printf("%I64d\n", ans);
}