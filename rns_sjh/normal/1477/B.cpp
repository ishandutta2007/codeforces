#include<bits/stdc++.h>
using namespace std;

#define N 200010

int T, n, q, l[N], r[N];
char s[N], t[N];

struct segtree {
    int vol;
    vector<int> sum, add;
    vector<int> member;
    segtree (int vol) : vol(vol) {
        sum.resize(vol << 2);
        member.resize(vol + 1);
        for(int i = 1; i <= n; i ++) member[i] = t[i] - '0';
        add.resize(vol << 2, -1);
        build(1, vol, 1);
    }
    void build(int l, int r, int k) {
        if(l == r) {
            sum[k] = member[l];
            return;
        }
        int m = l + r >> 1;
        build(l, m, k << 1);
        build(m + 1, r, k << 1 ^ 1);
        push_up(k);
        return;
    }
    void push_up(int k) {
        sum[k] = sum[k << 1] + sum[k << 1 ^ 1];
    }
    void push_down(int l, int r, int k) {
        int m = l + r >> 1;
        if(~add[k]) {
            sum[k << 1] = add[k] ? m - l + 1 : 0;
            sum[k << 1 ^ 1] = add[k] ? r - m : 0;
            add[k << 1] = add[k];
            add[k << 1 ^ 1] = add[k];
            add[k] = -1;
        }
    }
    void update(int l, int r, int k, int L, int R, int d) {
        if(L <= l && r <= R) {
            add[k] = d;
            sum[k] = d ? (r - l + 1) : 0;
            return;
        }
        int m = l + r >> 1;
        push_down(l, r, k);
        if(L <= m) update(l, m, k << 1, L, R, d);
        if(m < R) update(m + 1, r, k << 1 ^ 1, L, R, d);
        push_up(k);
    }
    int query(int l, int r, int k, int L, int R) {
        if(L <= l && r <= R) return sum[k];
        int m = l + r >> 1;
        int rlt = 0;
        push_down(l, r, k);
        if(L <= m) rlt += query(l, m, k << 1, L, R);
        if(m < R) rlt += query(m + 1, r, k << 1 ^ 1, L, R);
        return rlt;
    }
    bool ok(int L, int R) {
        int one = query(1, vol, 1, L, R);
        if(one * 2 == R - L + 1) return 0;
        if(one * 2 < R - L + 1) update(1, vol, 1, L, R, 0);
        else update(1, vol, 1, L, R, 1);
        return 1;
    }
    void clean(int l, int r, int k) {
        if(~add[k]) {
            for(int i = l; i <= r; i ++) member[i] = add[k];
            return;
        }
        if(l == r) return;
        int m = l + r >> 1;
        clean(l, m, k << 1);
        clean(m + 1, r, k << 1 ^ 1);
        return;
    }
    bool solve() {
        for(int i = q; i > 0; i --) if(!ok(l[i], r[i])) return 0;
        clean(1, vol, 1);
        bool yes = 1;
        for(int i = 1; i <= n && yes; i ++) if(s[i] - '0' != member[i]) yes = 0;
        return yes;
    }
};

int main() {
    for(scanf("%d", &T); T --; ) {
        scanf("%d%d", &n, &q);
        scanf("%s%s", s + 1, t + 1);
        for(int i = 1; i <= q; i ++) scanf("%d%d", l + i, r + i);
        segtree x(n);
        puts(x.solve() ? "YES" : "NO");
    }
}