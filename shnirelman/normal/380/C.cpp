#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int N = 1e6 + 13;
const int B = 500;

struct Node {
    int res, lf, rg;

    Node() : res(0), lf(0), rg(0) {};
};

Node unit(Node a, Node b) {
    Node res;

    int x = min(a.lf, b.rg);

    res.res = a.res + b.res + x;
    res.lf = a.lf + b.lf - x;
    res.rg = a.rg + b.rg - x;

    return res;
}

string s;
Node t[N * 4];

void build(int v, int l, int r) {
    if(r - l == 1) {
        if(s[l] == '(')
            t[v].lf = 1;
        else
            t[v].rg = 1;
        return;
    }

    int m = (l + r) / 2;

    build(v * 2 + 1, l, m);
    build(v * 2 + 2, m, r);

    t[v] = unit(t[v * 2 + 1], t[v * 2 + 2]);
}

Node get(int v, int l, int r, int ql, int qr) {
    if(ql >= r || qr <= l)
        return Node();

    if(ql <= l && r <= qr) {
        return t[v];
    }

    int m = (l + r) / 2;

    return unit(get(v * 2 + 1, l, m, ql, qr),
                get(v * 2 + 2, m, r, ql, qr));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;

    int n = s.length();

    build(0, 0, n);

    int q;
    cin >> q;

    for(int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;

        cout << get(0, 0, n, l - 1, r).res * 2 << '\n';
    }

}