#include <bits/stdc++.h>

using namespace std;

const int MAXT = 333333;

int get_rand_y() {
    return (rand() & (65535)) | ((rand() & 1023) << 10);
}

class Treap {
private:
    int x[MAXT];
    int add_x[MAXT];
    int y[MAXT];
    int l[MAXT], r[MAXT];

    int size, root;

    int init_node(int pos) {
        int id = ++size;
        x[id] = pos;
        add_x[id] = 0;
        y[id] = get_rand_y();
        l[id] = r[id] = 0;
        return id;
    }

    void touch(int v) {
        if (l[v]) {
            add_x[l[v]] += add_x[v];
        }
        if (r[v]) {
            add_x[r[v]] += add_x[v];
        }
        x[v] += add_x[v];
        add_x[v] = 0;
    }

    int merge(int t1, int t2) {
        if (!t1) return t2;
        if (!t2) return t1;
        int t;
        touch(t1);
        touch(t2);
        if (y[t1] > y[t2]) {
            r[t1] = merge(r[t1], t2);
            t = t1;
        } else {
            l[t2] = merge(t1, l[t2]);
            t = t2;
        }
        return t;
    }

    void split(int node, int pos, int &lv, int &rv) {
        lv = rv = 0;
        if (!node) {
            return;
        }
        touch(node);
        int tmp;
        if (x[node] > pos) {
            split(l[node], pos, lv, tmp);
            l[node] = tmp;
            rv = node;
        } else {
            split(r[node], pos, tmp, rv);
            r[node] = tmp;
            lv = node;
        }
    }

    int delete_left(int node) {
        if (!node) return node;
        touch(node);
        if (!l[node]) {
            return r[node];
        }
        l[node] = delete_left(l[node]);
        return node;
    }

    int count(int node) const {
        if (!node) return 0;
        return 1 + count(l[node]) + count(r[node]);
    }

public:
    Treap() {
        size = root = 0;
    }

    int get_size() const {
        return count(root);
    }

    void update_segment(int l, int r) {
        int a, t, b, c, d;
        split(root, l - 1, a, t);
        split(t, r - 1, c, d);
        if (c) {
            add_x[c] += 1;
        }
        b = init_node(l);
        d = delete_left(d);
        root = merge(merge(a, b), merge(c, d));
    }
};

Treap t;

int
main()
{
    ios_base::sync_with_stdio(false);
    int l, r;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &l, &r);
        t.update_segment(l, r);
    }
    printf("%d\n", t.get_size());
    return 0;
}