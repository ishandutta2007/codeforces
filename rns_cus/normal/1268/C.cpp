#include <bits/stdc++.h>
using namespace std;

#define N 200200

int p[N], a[N];

typedef long long ll;

ll sum[N<<2];

#define le v << 1
#define ri v << 1 | 1
#define mi (vl + vr >> 1)

inline void push_up(int v) {
    sum[v] = sum[le] + sum[ri];
}

void build(int v, int vl, int vr) {
    if (vl == vr) sum[v] = 1;
    else {
        build(le, vl, mi), build(ri, mi + 1, vr);
        push_up(v);
    }
}

void update(int v, int vl, int vr, int p) {
    if (vl == vr) sum[v] = 0;
    else {
        if (p <= mi) update(le, vl, mi, p);
        else update(ri, mi + 1, vr, p);
        push_up(v);
    }
}

ll query(int v, int vl, int vr, int l, int r) {
    if (vl > r || l > vr) return 0;
    if (l <= vl && vr <= r) return sum[v];
    return query(le, vl, mi, l, r) + query(ri, mi + 1, vr, l, r);
}

int n, fen[N];

void update(int x) {
    for (; x <= n; x += x & -x) fen[x] ++;
}

int query(int x) {
    int rlt = 0;
    for (; x; x -= x & -x) rlt += fen[x];
    return rlt;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) scanf("%d", &p[i]), a[p[i]] = i;
    ll ans = 0;
    set <int> S; build(1, 1, n);
    for (int k = 1, m = -1; k <= n; k ++) {
        int p = query(a[k]);
        ans -= min(p, k - 1 - p);
        ans += k - 1 - p;
        update(a[k]);
        update(1, 1, n, a[k]);
        if (k == 1) {
            m = a[k];
            S.insert(m);
            putchar('0');
            continue;
        }
        if (k - 1 & 1) {
            S.insert(a[k]);
            if (a[k] > m) ans += query(1, 1, n, m, a[k]);
            else ans += query(1, 1, n, a[k], m), m = *(--S.lower_bound(m));
        }
        else {
            int x = *(S.upper_bound(m)); S.insert(a[k]);
            if (a[k] > x) ans += query(1, 1, n, x, a[k]), m = x;
            else if (a[k] < m) ans += query(1, 1, n, a[k], m);
            else m = a[k];
        }
        printf(" %I64d", ans);
    }
    puts("");

    return 0;
}