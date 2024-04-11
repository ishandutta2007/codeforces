// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>

using namespace std;
#define int long long
const int N = (int) 4e5 + 6, mod = (int) 0;
struct data {
    int res, sz, pre0, suf0, pre1, suf1;
    data(int _res = 0, int _sz = 0, int _pre0 = 0, int _pre1 = 0, int _suf0 = 0, int _suf1 = 0) {
        res = _res;
        sz = _sz;
        pre0 = _pre0;
        pre1 = _pre1;
        suf0 = _suf0;
        suf1 = _suf1;
    }
};
int n, a[N], f[N];
data seg[N << 2];
int query(int m, int res = 0) { m++;
    if (m <= 0) return 0;
    while (m < N)
        res += f[m], m += m & -m;
    return res;
}

void update(int m, int x) { m++;
    while (m > 0)
        f[m] += x, m -= m & -m;
}
data merge(data l, data r) {
    data ret;
    ret.sz = l.sz + r.sz;
    ret.res = max(max(l.res, r.res), max(l.suf0 + r.pre1, l.suf1 + r.pre0));
    ret.suf0 = (r.sz == r.suf0? r.suf0 + l.suf0: r.suf0);
    ret.pre0 = (l.sz == l.pre0? l.pre0 + r.pre0: l.pre0);
    ret.suf1 = (r.sz == r.suf1? r.suf1 + l.suf0: r.suf1);
    ret.pre1 = (l.sz == l.pre1? l.pre1 + r.pre0: l.pre1);
    if (l.sz == l.suf0) {
        ret.pre1 = max(ret.pre1, l.sz + r.pre1);
    }
    if (r.sz == r.pre0) {
        ret.suf1 = max(ret.suf1, r.sz + l.suf1);
    }
    return ret;
}
data init(int val) {
    data ret;
    if (val == 1) {
        ret.pre0 = 0;
        ret.pre1 = 1;
        ret.suf0 = 1;
        ret.suf1 = 1;
        ret.res = 1;
        ret.sz = 1;
    } else if (val == 0) {
        ret.pre0 = 1;
        ret.pre1 = 1;
        ret.sz = 1;
        ret.res = 1;
        ret.suf0 = 0;
        ret.suf1 = 1;
    } else {
        ret.sz = 1;
    }
    return ret;
}
void build(int v = 1, int b = 0, int e = n - 1) {
    if (b + 1 == e) {
       int val = (a[b] == a[b + 1]? -1: a[b] < a[b + 1]);
        seg[v] = init(val);
        return;
    }
    int m = b + e >> 1, l = v << 1, r = l | 1;
    build(l, b, m);
    build(r, m, e);
    seg[v] = merge(seg[l], seg[r]);
}
void seg_upd(int pos, int val, int v = 1, int b = 0, int e = n - 1) {
    if (b + 1 == e) {
        seg[v] = init(val);
        return;
    }
    int m = b + e >> 1, l = v << 1, r = l | 1;
    if (pos < m)
        seg_upd(pos, val, l, b, m);
    else
        seg_upd(pos, val, r, m, e);
    seg[v] = merge(seg[l], seg[r]);
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        update(i, a[i]);
        update(i - 1, -a[i]);
    }
    if (n > 1) build();
    int q;
    cin >> q;
    while (q--) {
        int l, r, d;
        cin >> l >> r >> d; --l;
        update(r - 1, +d);
        update(l - 1, -d);
        if (l - 1 >= 0) {
            int v0 = query(l - 1);
            int v1 = query(l);
            seg_upd(l - 1, (v0 == v1? -1: v0 < v1));
        }
        if (r < n) {
            int v0 = query(r - 1);
            int v1 = query(r);
            seg_upd(r - 1, (v0 == v1? -1: v0 < v1));
        }
        if (n != 1) cout << seg[1].res + 1 << '\n';
        else cout << 1 << '\n';
    }
}