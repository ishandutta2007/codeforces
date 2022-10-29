#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 111111 * 3;
const long long INF = (1LL << 59);

long long sd[N << 2];

struct Node {
    long long ls, rs, maxV;
    Node() {
        ls = -INF, rs = -INF, maxV = -INF;
    }
    void set(int pos, int h) {
        ls = 2LL * h - sd[pos - 1];
        rs = 2LL * h + sd[pos - 1];
        maxV = -INF;
    }
    Node friend operator +(const Node &a, const Node &b) {
        Node ret;
        ret.maxV = max(max(a.maxV, b.maxV), a.ls + b.rs);
        ret.ls = max(a.ls, b.ls);
        ret.rs = max(a.rs, b.rs);
        return ret;
    }
}tree[N << 2];

int n, m, d[N << 1], h[N << 1], nn;

void build(int x, int l, int r) {
    if (l == r) {
        tree[x].set(l, h[l]);
    } else {
        int mid = (l + r) / 2;
        build(x << 1, l, mid);
        build(x << 1 | 1, mid + 1, r);
        tree[x] = tree[x << 1] + tree[x << 1 | 1];
    }
}

Node ask(int x, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) {
        return Node();
    } else if (ql <= l && r <= qr) {
        return tree[x];
    } else {
        int mid = (l + r) / 2;
        return ask(x << 1, l, mid, ql, qr) + ask(x << 1 | 1, mid + 1, r, ql, qr);
    }
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> d[i];
        d[i + n] = d[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> h[i];
        h[i + n] = h[i];
    }
    nn = n * 2;
    for(int i = 1; i <= nn; i++) {
        sd[i] = sd[i - 1] + d[i];
    }
    build(1, 1, nn);
    for(int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        int len;
        if (a <= b) {
            len = n - (b - a + 1);
            cout << ask(1, 1, nn, b + 1, b + len).maxV << endl;
        } else {
            len = a - b - 1;
            cout << ask(1, 1, nn, b + 1, b + len).maxV << endl;
        }
    }
    return 0;
}