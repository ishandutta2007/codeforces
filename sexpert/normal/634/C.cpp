#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long ll;

int n, k, a, b, q;

struct info {
    int rem, tot;
};

info merge(info A, info B) {
    return {A.rem + B.rem, A.tot + B.tot};
}

struct node {
    int l, r;
    info cont;
    node *left, *right;

    node(int l, int r, int s) : l(l), r(r) {
        if(l == r)
            cont = {s, 0};
        else {
            int m = (l + r)/2;
            left = new node(l, m, s);
            right = new node(m + 1, r, s);
            cont = merge(left->cont, right->cont);
        }
    }

    void upd(int p, int v) {
        if(r < p || p < l)
            return;
        if(l == r) {
            int m = min(cont.rem, v);
            cont.rem -= m;
            cont.tot += m;
            return;
        }
        left->upd(p, v);
        right->upd(p, v);
        cont = merge(left->cont, right->cont);
    }

    info qry(int rl, int rr) {
        if(rr < l || r < rl || l > r)
            return {0, 0};
        if(rl <= l && r <= rr)
            return cont;
        return merge(left->qry(rl, rr), right->qry(rl, rr));
    }

    void print() {
        cout << "[" << l << ", " << r << "] : (" << cont.rem << " " << cont.tot << ")\n";
        if(l < r) {
            left->print();
            right->print();
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k >> a >> b >> q;
    node slow(1, n, b), fast(1, n, a);
    while(q--) {
        int t;
        cin >> t;
        if(t == 1) {
            int d, del;
            cin >> d >> del;
            slow.upd(d, del);
            fast.upd(d, del);
        }
        if(t == 2) {
            int p;
            cin >> p;
            //cout << "[" << 1 << ", " << p - 1 << "], [" << p + k << ", " << n << "]\n";
            info A = slow.qry(1, p - 1), B = fast.qry(p + k, n);
            //cout << A.rem << " " << A.tot << "   " << B.rem << " " << B.tot << '\n';
            cout << A.tot + B.tot << '\n';
        }
        //slow.print();
        //fast.print();
    }
}