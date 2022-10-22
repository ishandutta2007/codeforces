#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pli = pair<li, li>;
//using matr

const li INF = 2e18 + 13;
const int N = 2e5 + 13;
const int M = 998244353;
const int B = 300;
const int A = 26;
const ld e = 1e-8;
const int LOGN = 20;
const int K = 170;

mt19937 rnd(0);

/*
*/

struct Node {
    int sz, lf, rg, fir, lst;
    li res;

    Node() {};

    Node(int sz, int lf, int rg, int fir, int lst, li res) :
        sz(sz), lf(lf), rg(rg), fir(fir), lst(lst), res(res) {};
};


int a[N];
Node t[N * 4];

Node merge(Node a, Node b) {
    Node c;
    c.sz = a.sz + b.sz;
    c.res = a.res + b.res;
    c.fir = a.fir;
    c.lst = b.lst;

    bool fl = (a.lst <= b.fir);

    if(a.lf == a.sz && fl)
        c.lf = a.lf + b.lf;
    else
        c.lf = a.lf;

    if(b.rg == b.sz && fl)
        c.rg = a.rg + b.rg;
    else
        c.rg = b.rg;

    if(fl)
        c.res += a.rg * 1ll * b.lf;

    return c;
}

void build(int v, int l, int r) {
    if(r - l == 1) {
        t[v] = Node(1, 1, 1, a[l], a[l], 1);
        return;
    }

    int m = (l + r) / 2;

    build(v * 2 + 1, l, m);
    build(v * 2 + 2, m, r);

    t[v] = merge(t[v * 2 + 1], t[v * 2 + 2]);
}

void update(int v, int l, int r, int qi, int x) {
    if(l > qi || r <= qi)
        return;

    if(r - l == 1) {
        a[qi] = x;
        t[v] = Node(1, 1, 1, a[l], a[l], 1);
        return;
    }

    int m = (l + r) / 2;

    update(v * 2 + 1, l, m, qi, x);
    update(v * 2 + 2, m, r, qi, x);

    t[v] = merge(t[v * 2 + 1], t[v * 2 + 2]);
}

Node get(int v, int l, int r, int ql, int qr) {
    if(l >= qr || r <= ql)
        return Node(0, 0, 0, 0, INF, 0);

    if(ql <= l && r <= qr)
        return t[v];

    int m = (l + r) / 2;

    return merge(get(v * 2 + 1, l, m, ql, qr), get(v * 2 + 2, m, r, ql, qr));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    build(0, 0, n);

    for(int i = 0; i < q; i++) {
        int t;
        cin >> t;

        if(t == 1) {
            int ind, x;
            cin >> ind >> x;

            update(0, 0, n, ind - 1, x);
        } else {
            int l, r;
            cin >> l >> r;

            cout << get(0, 0, n, l - 1, r).res << '\n';
        }
    }
}