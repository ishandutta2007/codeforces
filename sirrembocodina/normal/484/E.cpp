#include <bits/stdc++.h>

using namespace std;

#define int int64_t

struct info {
    int st, fin, mx;
    bool all;
};

info operator+(const info& a, const info& b) {
    info res;
    res.st = a.st + b.st * a.all;
    res.fin = b.fin + a.fin * b.all;
    res.mx = max(max(a.mx, b.mx), a.fin + b.st);
    res.all = a.all && b.all;
    return res;
}

struct tree {
    info x;
    tree* l;
    tree* r;
    tree() {
        l = r = nullptr;
    }
};

tree* rt = new tree;

tree*& get_l(tree* v) {
    if (!v->l) {
        v->l = new tree;
    }
    return v->l;
}

tree*& get_r(tree* v) {
    if (!v->r) {
        v->r = new tree;
    }
    return v->r;
}

/*void add_elem(tree*& v, int l, int r, int x) {
    v = new tree(*v);
    v->sum++;
    if (l == r - 1) {
        return;
    }
    int mid = (l + r) / 2;
    if (x < mid) {
        add_elem(get_l(v), l, mid, x);
    } else {
        add_elem(get_r(v), mid, r, x);
    }
}*/

void build_tree(tree*& v, int l, int r) {
    if (l == r - 1) {
        v->x.all = true;
        v->x.st = v->x.fin = v->x.mx = 1;
        return;
    }
    int mid = (l + r) / 2;
    build_tree(get_l(v), l, mid);
    build_tree(get_r(v), mid, r);
    v->x = v->l->x + v->r->x;
}

void put_zero(tree*& v, int l, int r, int i) {
    v = new tree(*v);
    if (l == r - 1) {
        v->x.all = false;
        v->x.st = v->x.fin = v->x.mx = 0;
        return;
    }
    int mid = (l + r) / 2;
    if (i < mid) {
        put_zero(get_l(v), l, mid, i);
    } else {
        put_zero(get_r(v), mid, r, i);
    }
    v->x = v->l->x + v->r->x;
}

info get_mx(tree* v, int l, int r, int L, int R) {
    if (r <= L || R <= l) {
        return info();
    }
    if (L <= l && r <= R) {
        return v->x;
    }
    int mid = (l + r) / 2;
    return get_mx(v->l, l, mid, L, R) +
           get_mx(v->r, mid, r, L, R);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<pair<int, int>> h(n);
    for (int i = 0; i < n; i++) {
        h[i].second = i;
        cin >> h[i].first;
    }
    sort(h.begin(), h.end());
    vector<tree*> roots(n);
    build_tree(rt, 0, n);
    for (int i = 0; i < n; i++) {
        roots[i] = rt;
        put_zero(rt, 0, n, h[i].second);
    }
    int m;
    cin >> m;
    while (m--) {
        int l, r, w;
        cin >> l >> r >> w;
        l--;
        int l_bin = 0, r_bin = n;
        while (r_bin - l_bin > 1) {
            int m_bin = (l_bin + r_bin) / 2;
            info res = get_mx(roots[m_bin], 0, n, l, r);
            if (res.mx >= w) {
                l_bin = m_bin;
            } else {
                r_bin = m_bin;
            }
        }
        cout << h[l_bin].first << '\n';
    }
    return 0;
}