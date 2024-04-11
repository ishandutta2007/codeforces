#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 18;

int n, q;
int a[1 << N];
int mask = 0;
int t[1 << (N + 1)];

void upd(int v, int tl, int tr, int pos, int val, int dep) {
    if (tr - tl == 1) t[v] = val; else {
        int tm = (tl + tr) / 2;
        int u1 = v << 1, u2 = (v << 1) | 1;
        int bit = (mask >> dep) & 1;
        u1 ^= bit;
        u2 ^= bit;
        if (pos < tm) upd(u1, tl, tm, pos, val, dep + 1); else upd(u2, tm, tr, pos, val, dep + 1);
        t[v] = t[u1] + t[u2];
    }
}

int query(int v, int tl, int tr, int l, int r, int dep) {
    if (tl >= r || tr <= l) return 0;
    if (tl >= l && tr <= r) return t[v];
    int tm = (tl + tr) / 2;
    int u1 = v << 1, u2 = (v << 1) | 1;
    int bit = (mask >> dep) & 1;
    u1 ^= bit;
    u2 ^= bit;
    return query(u1, tl, tm, l, r, dep + 1) + query(u2, tm, tr, l, r, dep + 1);
}

void build(int v, int tl, int tr) {
    if (tr - tl == 1) t[v] = a[tl]; else {
        int tm = (tl + tr) / 2;
        build(2 * v, tl, tm);
        build(2 * v + 1, tm, tr);
        t[v] = t[2 * v] + t[2 * v + 1];
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 0; i < (1 << n); ++i) cin >> a[i];
    build(1, 0, 1 << n);
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x, k;
            cin >> x >> k;
            --x;
            upd(1, 0, 1 << n, x, k, 0);
        }
        if (type == 2) {
            int k;
            cin >> k;
            k = n - k;
            for (int i = k; i < n; ++i) mask ^= 1 << i;
        }
        if (type == 3) {
            int k;
            cin >> k;
            k = n - k - 1;
            mask ^= 1 << k;
        }
        if (type == 4) {
            int l, r;
            cin >> l >> r;
            --l;
            cout << query(1, 0, 1 << n, l, r, 0) << '\n';
        }
    }
    return 0;
}