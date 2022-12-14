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

const int N = (int) 2e5 + 6, mod = (int) 0;
int n, k, m, have[N][5], par[N];
int find(int v) { return v == par[v]? v: par[v] = find(par[v]); }
int unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return 0;
    par[u] = v;
    return 1;
}
struct data {

    int a[11], b[11], m0, m1, sz, comp;
    data(int x = 0) {
        if (x < 0) {
            m0 = m1 = sz = comp = 0;   
        } else {
          m0 = 1;
             m1 = 2;
         sz = 1;
          comp = 1;
         a[0] = a[1] = x;
         b[0] = b[1] = 0;
        }
    }
};
data merge(data lhs, data rhs) {
    if (lhs.sz == 0) return rhs;
    if (rhs.sz == 0) return lhs;
    data res;
    for (int j = 0; j < 20; ++j)
        par[j] = j;
    res.m0 = res.m1 = 0;
    res.sz = lhs.sz + rhs.sz;
    res.comp = lhs.comp + rhs.comp;
    for (int x = 0; x < lhs.m1; ++x)
        for (int y = x + 1; y < lhs.m1; ++y)
            if (lhs.b[x] == lhs.b[y])
                unite(x, y);
    for (int x = 0; x < rhs.m1; ++x)
        for (int y = x + 1; y < rhs.m1; ++y)
            if (rhs.b[x] == rhs.b[y])
                unite(x + lhs.m1, y + lhs.m1);
    for (int x = lhs.m0; x < lhs.m1; ++x)
        for (int y = 0; y < 5; ++y)
            if (have[lhs.a[x]][y]) {
                int len = (x + y + 1) - lhs.m1;
                if (len < 0 || len >= rhs.sz) continue;
                res.comp -= unite(x, lhs.m1 + len);
            }
    while (res.m0 < 5) {
        if (lhs.sz + rhs.sz <= res.m0) break;
        if (lhs.sz <= res.m0) {
            res.a[res.m0] = rhs.a[res.m0 - lhs.sz];
            res.b[res.m0] = find(lhs.m1 + res.m0 - lhs.sz);
            res.m0++;
        } else {
            res.a[res.m0] = lhs.a[res.m0];
            res.b[res.m0] = find(res.m0);
            res.m0++;
        }
    }
    while (res.m1 < 5) {
        if (lhs.sz + rhs.sz <= res.m1) break;
        if (rhs.sz <= res.m1) {
            res.a[res.m0 + res.m1] = lhs.a[lhs.m1 - (res.m1 - rhs.sz) - 1];
            res.b[res.m0 + res.m1] = find(lhs.m1 - (res.m1 - rhs.sz)  - 1);
            res.m1++;
        } else {
            res.a[res.m0 + res.m1] = rhs.a[rhs.m1 - res.m1 - 1];
            res.b[res.m0 + res.m1] = find(lhs.m1 + rhs.m1 - res.m1 - 1);
            res.m1++;
        }
    }
    res.m1 += res.m0;
    reverse(res.a + res.m0, res.a + res.m1);
    reverse(res.b + res.m0, res.b + res.m1);
    return res;
        
}
data seg[N << 2];

void build(int v = 1, int b = 0, int e = n) {
    if (b + 1 == e) {
        seg[v] = data(b);
        return;
    }
    int m = b + e >> 1, l = v << 1, r = l | 1;
    build(l, b, m);
    build(r, m, e);
    seg[v] = merge(seg[l], seg[r]);
}

data query(int i, int j, int v = 1, int b = 0, int e = n) {
    if (i >= e || b >= j) return data(-1);
    if (i <= b && e <= j) return seg[v];
    int m = b + e >> 1, l = v << 1, r = l | 1;
    return merge(query(i, j, l, b, m), query(i, j, r, m, e));
}


int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    cin >> m;
    for (int j = 0; j < m; ++j) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        if (u > v) swap(u, v);
        have[u][v - u - 1] = 1;
    }
    build();
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        --l;
        data res = query(l, r);
        cout << res.comp << '\n';
    }
}