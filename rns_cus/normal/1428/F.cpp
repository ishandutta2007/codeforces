#include <bits/stdc++.h>
using namespace std;

#define N 500100

int n;
char s[N];

#define le v << 1
#define ri v << 1 | 1
#define mi (vl + vr >> 1)

typedef long long ll;

int add[N<<2], sum[N<<2];
ll vsum[N<<2];

void push_up(int v) {
    sum[v] = sum[le] + sum[ri];
    vsum[v] = vsum[le] + vsum[ri];
}

void modify(int v, int vl, int vr, int d) {
    add[v] = d;
    sum[v] = d * (vr - vl + 1);
    vsum[v] = 1ll * (vr - vl + 1) * (vr + vl - 2) / 2 * d;
}

void push_dn(int v, int vl, int vr) {
    if (add[v] >= 0) {
        modify(le, vl, mi, add[v]);
        modify(ri, mi + 1, vr, add[v]);
        add[v] = -1;
    }
}

void modify(int v, int vl, int vr, int l, int r, int d) {
    if (l > r || vl > r || l > vr) return;
    if (l <= vl && vr <= r) modify(v, vl, vr, d);
    else {
        push_dn(v, vl, vr);
        modify(le, vl, mi, l, r, d);
        modify(ri, mi + 1, vr, l, r, d);
        push_up(v);
    }
}

int query(int v, int vl, int vr, int l, int r) {
    if (l > r || vl > r || l > vr) return 0;
    if (l <= vl && vr <= r) return sum[v];
    push_dn(v, vl, vr);
    return query(le, vl, mi, l, r) + query(ri, mi + 1, vr, l, r);
}

ll vquery(int v, int vl, int vr, int l, int r) {
    if (l > r || vl > r || l > vr) return 0;
    if (l <= vl && vr <= r) return vsum[v];
    push_dn(v, vl, vr);
    return vquery(le, vl, mi, l, r) + vquery(ri, mi + 1, vr, l, r);
}

int main() {
    scanf("%d %s", &n, s + 1);
    memset(add, -1, sizeof add);
    ll ans = 0;
    for (int i = 1, j = 1; i <= n; i = j) {
        while (j <= n && s[j] == '1') j ++;
        int k = j - i, l = query(1, 1, n, 1, k + 1);
        if (k) {
            for (int x = 1; x <= k; x ++) {
                ans += 1ll * x * query(1, 1, n, 1, x) + vquery(1, 1, n, x + 1, n);
            }
            ans += 1ll * k * (k + 1) * (k + 2) / 6;
            modify(1, 1, n, 2, k, 1), modify(1, 1, n, k + 1, k + 1, l + 1);
        }

        ll S = vsum[1];
        int p = 0;
        while (j <= n && s[j] == '0') {
            ans += S, p ++, j ++;
        }
        modify(1, 1, n, 1, 1, p);

    }
    printf("%I64d\n", ans);

    return 0;
}