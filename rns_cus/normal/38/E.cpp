#include <bits/stdc++.h>
using namespace std;

#define N 3030

typedef long long ll;

int n, x[N], c[N], id[N];
ll ep[N];

inline void chkmin(ll &x, ll y) {
    if (x > y) x = y;
}

const ll inf = 1e18;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) scanf("%d %d", &x[i], &c[i]), ep[i] = inf, id[i] = i;
    sort(id + 1, id + n + 1, [&](int i, int j) {return x[i] < x[j];});
    ep[1] = c[id[1]];
    ll ans = inf;
    for (int i = 2; i <= n; i ++) {
        ll s = 0;
        for (int j = i - 1; j; j --) {
            int ii = id[i], jj = id[j];
            if (i == n) chkmin(ans, ep[j] + s - 1ll * (i - j - 1) * x[jj] + x[ii] - x[jj]);
            chkmin(ep[i], ep[j] + s - 1ll * (i - j - 1) * x[jj] + c[ii]);
            s += x[jj];
        }
    }
    chkmin(ans, ep[n]);
    printf("%I64d\n", ans);

    return 0;
}