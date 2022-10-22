//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using vint = vector<int>;
using matr = vector<vint>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 3e5 + 13;
const int M = 1e9 + 9;
const ld eps = 1e-6;
const int K = 103;
const int LOGN = 20;

/*
3 1
1 0 0
*/


struct Node {
    int res;
    int sz;
    int lf_inc, rg_inc;
    int lf_dec, rg_dec;

    int lf, rg;
//    li lf_mx, rg_mx;

    li fir, lst;
    li add;

//    Node() : res(0), sz(0), lf_inc(0), rg_inc(0), lf_dec(0), rg_dec(0), lf(0), rg(0), lf_mx(0), rg_mx(0), fir(0), lst(0), add(0) {};
    Node() : res(0), sz(0), lf_inc(0), rg_inc(0), lf_dec(0), rg_dec(0), lf(0), rg(0), fir(0), lst(0), add(0) {};

//    Node(li x) : res(1), sz(1), lf_inc(1), rg_inc(1), lf_dec(1), rg_dec(1), lf(1), rg(1), lf_mx(x), rg_mx(x), fir(x), lst(x), add(0) {};
    Node(li x) : res(1), sz(1), lf_inc(1), rg_inc(1), lf_dec(1), rg_dec(1), lf(1), rg(1), fir(x), lst(x), add(0) {};
};

inline Node merge(const Node& a, const Node& b) {
    Node res;

    res.res = max(a.res, b.res);
    res.sz = a.sz + b.sz;

    res.lf_inc = a.lf_inc;
    if(a.lf_inc == a.sz && a.lst < b.fir)
        res.lf_inc = a.sz + b.lf_inc;

    res.lf_dec = a.lf_dec;
    if(a.lf_dec == a.sz && a.lst > b.fir)
        res.lf_dec = a.sz + b.lf_dec;

    res.rg_inc = b.rg_inc;
    if(b.rg_inc == b.sz && a.lst < b.fir)
        res.rg_inc = b.sz + a.rg_inc;

    res.rg_dec = b.rg_dec;
    if(b.rg_dec == b.sz && a.lst > b.fir)
        res.rg_dec = b.sz + a.rg_dec;

    res.fir = a.fir;
    res.lst = b.lst;
    res.add = 0;

    if(a.lst > b.fir)
        res.res = max(res.res, a.rg + b.lf_dec);

    if(a.lst < b.fir)
        res.res = max(res.res, a.rg_inc + b.lf);

    res.lf = a.lf;
//    res.lf_mx = a.lf_mx;
    res.rg = b.rg;
//    res.rg_mx = b.rg_mx;

    if(a.lf == a.sz && a.lst > b.fir) {
        res.lf = a.sz + b.lf_dec;

    }

    if(a.lf_inc == a.sz && a.lst < b.fir) {
        res.lf = a.sz + b.lf;
//        res.lf_mx = b.lf_mx;
    }

    if(b.rg == b.sz && a.lst < b.fir) {
        res.rg = b.sz + a.rg_inc;
    }

    if(b.rg_dec == b.sz && a.lst > b.fir) {
        res.rg = b.sz + a.rg;
//        res.rg_mx = a.rg_mx;
    }

    res.res = max(res.res, max(res.lf, res.rg));

    return res;
}

int a[N];
Node t[4 * N];

void build(int v, int l, int r) {
    if(r - l == 1) {
        t[v] = Node(a[l]);
        return;
    }

    int m = (l + r) / 2;

    build(v * 2 + 1, l, m);
    build(v * 2 + 2, m, r);

    t[v] = merge(t[v * 2 + 1], t[v * 2 + 2]);
}

inline void push(int v) {
    int v1 = v * 2 + 1, v2 = v * 2 + 2;
    li x = t[v].add;

    t[v1].add += x;
    t[v1].fir += x;
    t[v1].lst += x;
//    t[v1].lf_mx += x;
//    t[v1].rg_mx += x;

    t[v2].add += x;
    t[v2].fir += x;
    t[v2].lst += x;
//    t[v2].lf_mx += x;
//    t[v2].rg_mx += x;

    t[v].add = 0;
}

void update(int v, int l, int r, int ql, int qr, int x) {
    if(ql >= r || qr <= l)
        return;

    if(ql <= l && r <= qr) {
        t[v].add += x;
        t[v].fir += x;
        t[v].lst += x;
//        t[v].lf_mx += x;
//        t[v].rg_mx += x;
        return;
    }

    push(v);

    int m = (l + r) / 2;

    update(v * 2 + 1, l, m, ql, qr, x);
    update(v * 2 + 2, m, r, ql, qr, x);

    t[v] = merge(t[v * 2 + 1], t[v * 2 + 2]);
}

void out(int v, int l, int r, li add) {
    if(r - l == 1) {
        cout << "lief " << v << ' ' << l << ' ' << r << ' ' << t[v].fir + add << endl;
        return;
    }

    int m = (l + r) / 2;

    out(v * 2 + 1, l, m, add + t[v].add);
    out(v * 2 + 2, m, r, add + t[v].add);


}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    build(0, 0, n);

    int q;
    cin >> q;

    for(int i = 0; i < q; i++) {
        int l, r, x;
        cin >> l >> r >> x;

        l--;

        update(0, 0, n, l, r, x);

//        out(0, 0, n, 0);

        cout << t[0].res << endl;
    }
}