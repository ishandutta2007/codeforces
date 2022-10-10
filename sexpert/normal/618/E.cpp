#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef complex<double> cpx;
const double PI = acos(-1);

cpx mul (cpx x, cpx y) {
    double rx = x.real(), ry = y.real(), ix = x.imag(), iy = y.imag();
    return cpx(rx*ry - ix*iy, rx*iy + ry*ix);
}

struct node {
    int l, r;
    cpx A, B, x;
    node *left, *right;
    void compose(cpx C, cpx D) {
        // C*(Ax + B) + D
        A = mul(A, C);
        B = mul(B, C) + D;
    }
    void push() {
        left->compose(A, B);
        right->compose(A, B);
        A = cpx(1.0, 0);
        B = cpx(0, 0);
    }
    node(int l, int r, vector<cpx> &v) : l(l), r(r), A(cpx(1.0, 0)), B(cpx(0, 0)) {
        if(l == r)
            x = v[l];
        else {
            int m = (l + r)/2;
            left = new node(l, m, v);
            right = new node(m + 1, r, v);
        }
    }
    void upd(int rl, int rr, cpx a, cpx b) {
        if(r < rl || rr < l)
            return;
        if(rl <= l && r <= rr)
            { compose(a, b); return; }
        push();
        left->upd(rl, rr, a, b);
        right->upd(rl, rr, a, b);
    }
    cpx get(int p) {
        if(l == r)
            return mul(A, x) + B;
        int m = (l + r)/2;
        push();
        if(p <= m)
            return left->get(p);
        else
            return right->get(p);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<cpx> v(n + 1);
    for(int i = 0; i <= n; i++)
        v[i] = cpx(i, 0);
    node tree(0, n, v);
    while(m--) {
        int a, b, c;
        cin >> a >> b >> c;
        b--;
        if(a == 1) {
            cpx z1 = tree.get(b), z2 = tree.get(b + 1), dir = z2 - z1;
            //cout << z1 << " " << z2 << endl;
            dir = dir * ((double)c / abs(dir));
            //cout << dir << endl;
            tree.upd(b + 1, n, 1, dir);
        }
        else {
            // z -> k + (z - k)*rot
            cpx k = tree.get(b), rot = polar(1.0, -((double)c/180.0) * PI );
            //cout << k << " " << rot << endl;
            tree.upd(b + 1, n, rot, k - mul(k, rot));
        }
        cpx e = tree.get(n);
        cout << fixed << setprecision(20) << e.real() << " " << e.imag() << '\n';
    }
}