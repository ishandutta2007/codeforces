#include <iostream>
#include "vector"
#include "algorithm"
#include "numeric"
#include "climits"
#include "iomanip"
#include "bitset"
#include "cmath"
#include "map"
#include "deque"
#include "array"
#include "set"
#define all(x) x.begin(), x.end()
using namespace std;
struct node {
    int left = 0, cent = 0, right = 0;
    int prc = 0;
    void make(int l, int c, int r, int d = 0) {
        left = l;right = r;cent = c;prc = d;
    }
    int onexone(int x) {
        return (abs(left) and abs(right) and cent == x);
    }
    int getpr() {
        return abs(cent) + prc;
    }
};
bool ab(int x) {
    return x > 0;
}
void mn1(int & x) {
    if (x > 0)
        x--;
    else
        x++;
}
void mny(int & x, int y) {
    if (x > 0)
        x -= y;
    else
        x += y;
}
void pl1(int & x) {
    if (x < 0)
        x--;
    else
        x++;
}
void mk(node &a) {
    if (abs(a.cent) == 1 and abs(a.left + a.right) == 2) {
        a.left = 0;
        a.right = 0;
        a.cent = -a.cent;
    }
}
node merge(node a, node b) {
    if (a.cent == 0)
        return b;
    if (b.cent == 0)
        return a;
    if (ab(a.cent) == ab(b.cent)) {
        if (abs(a.right + b.left) == 2) {
            if (abs(a.cent) + abs(b.cent) == 2) {
                node c;
                c.make(a.cent, a.right + b.left, b.cent, a.prc + b.prc);
                return c;
            }
            if (abs(a.cent) > abs(b.cent)) {
                mn1(a.cent);
                mn1(a.right);
                a.prc++;
            } else {
                mn1(b.cent);
                mn1(b.left);
                b.prc++;
            }
        }
        if (abs(a.right + b.left) == 1) {
            a.right = 0;
            b.left = 0;
            if (abs(a.cent) > abs(b.cent)) {
                mn1(a.cent);
            } else {
                mn1(b.cent);
            }
        }
        node c;
        c.make(a.left, b.cent + a.cent, b.right, a.prc + b.prc);
        mk(c);
        return c;
    } else {
        if (a.right != 0 and 0 != b.left) {
            a.right = 0;
            b.left = 0;
        }
        if (a.right) {
            a.right = 0;
            pl1(b.cent);
        }
        if (b.left) {
            b.left = 0;
            pl1(a.cent);
        }
        int vl = min(abs(a.cent), abs(b.cent)) - 1;
        mny(a.cent, vl);
        mny(b.cent, vl);
        a.prc += vl;
        if (abs(a.cent) > abs(b.cent)) {
            a.prc += b.prc;
            if (b.right != 0) {
                return a;
            } else {
                a.right = b.cent;
                mk(a);
                return a;
            }
        } else {
            b.prc += a.prc;
            if (a.left != 0) {
                return b;
            } else {
                b.left = a.cent;
                mk(b);
                return b;
            }
        }
    }
}
struct segtree{
    int sz;
    vector<node> tree;
    void make(int n, string s) {
        sz = 1;
        while (sz < n) {
            sz *= 2;
        }
        tree.assign(sz * 2, {});
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1')
                tree[i + sz].make(0, 1, 0);
            else
                tree[i + sz].make(0, -1, 0);
        }
        for (int i = sz - 1; i > 0; --i) {
            tree[i] = merge(tree[i * 2], tree[i * 2 + 1]);
        }
    }
    node zpr(int ll, int rr, int v, int l, int r) {
        if (ll >= r or rr <= l) {
            return {};
        }
        if (l <= ll and rr <= r) {
            //cout << tree[v].left << ' ' << tree[v].cent << ' ' << tree[v].right << endl;
            return tree[v];
        }
        int m = ll + rr >> 1;
        auto res = merge(zpr(ll, m, v*2, l, r), zpr(m, rr, v*2+1, l, r));
        //cout << res.cent << endl;
        return res;
    }
    int zpr(int l, int r) {
        return zpr(0, sz, 1, l, r).getpr();
    }
};
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    /*vector<node> ss(n);
    for (int i = 2; i < n; ++i) {
        node a;
        if (s[i] == '1')
            a.make(0, 1, 0);
        else
            a.make(0, -1, 0);
        if (i != 0)
            ss[i] = merge(ss[i-1], a);
        else
            ss[i] = a;
        cout << ss[i].getpr() << ' ' << ss[i].cent << endl;
    }*/
    segtree sg;
    sg.make(n, s);
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        l--;
        cout << sg.zpr(l, r) << '\n';
    }
}