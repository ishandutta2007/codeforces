#include <bits/stdc++.h>
using namespace std;
#define int long long

mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 5e5 + 7, M = 1e10;
int n, a[N], val[N];
queue<int> q[N];
int lst[N];
struct Node{
    int mn, cnt, toadd;
    Node() {}
    Node(int mn, int cnt, int toadd) : mn(mn), cnt(cnt), toadd(toadd) {}
};

Node t[4 * N];
Node merge(Node lft, Node rght) {
    Node res;
    res.mn = min(lft.mn, rght.mn);
    res.cnt = 0;
    if (lft.mn == res.mn) res.cnt += lft.cnt;
    if (rght.mn == res.mn) res.cnt += rght.cnt;
    res.toadd = 0;
    return res;
}

void apply(int v, int delta) {
    t[v].toadd += delta;
    t[v].mn += delta;
}

void push(int v) {
    apply(2 * v, t[v].toadd);
    apply(2 * v + 1, t[v].toadd);
    t[v].toadd = 0;
}

void pull(int v) {
    t[v] = merge(t[2 * v], t[2 * v + 1]);
}

void upd(int v, int tl, int tr, int l, int r, int delta) {
    if (tl >= r || tr <= l) return;
    if (tl >= l && tr <= r) apply(v, delta); else {
        push(v);
        int tm = (tl + tr) / 2;
        upd(2 * v, tl, tm, l, r, delta);
        upd(2 * v + 1, tm, tr, l, r, delta);
        pull(v);
    }
}

int query(int v, int tl, int tr, int l, int r) {
    if (tl >= r || tr <= l) return 0;
    if (tl >= l && tr <= r) return (t[v].mn == 0 ? t[v].cnt : 0);
    push(v);
    int tm = (tl + tr) / 2;
    return query(2 * v, tl, tm, l, r) + query(2 * v + 1, tm, tr, l, r);
}

void build(int v, int l, int r) {
    if (r - l == 1) t[v] = {0, 1, 0}; else {
        int m = (l + r) / 2;
        build(2 * v, l, m);
        build(2 * v + 1, m, r);
        pull(v);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) val[i] = rnd() % M + 1;
    memset(lst, 255, sizeof(lst));
    build(1, 0, n);
    int mn = n, res = 0;
    for (int i = n - 1; i >= 0; --i) {
        upd(1, 0, n, i, n, -val[a[i]]);
        q[a[i]].push(i);
        if (q[a[i]].size() == 4) {
            mn = min(mn, q[a[i]].front());
            q[a[i]].pop();
        }
        if (lst[a[i]] != -1) upd(1, 0, n, lst[a[i]], n, -3 * val[a[i]]);
        lst[a[i]] = i;
        upd(1, 0, n, i, n, 3 * val[a[i]]);
        res += query(1, 0, n, i, mn);
    }
    cout << res;
    return 0;
}