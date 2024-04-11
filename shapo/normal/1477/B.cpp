#include <bits/stdc++.h>

using namespace std;

#define ve vector

typedef ve<int> vi;

struct Interval { // info for [l; r) interval
    int l = 0;
    int r = 0;
    int sum = 0;
    int new_value = -1; // only 0 and 1 are valid

    int get_sum() const {
        if (new_value != -1) {
            return new_value * (r - l);
        } else {
            return sum;
        }
    }

    bool intersects(int ls, int rs) const {
        return (max(ls, l) < min(rs, r));
    }

    bool isin(int ls, int rs) const {
        return (ls <= l && rs >= r);
    }

    void update_children(Interval& l_child, Interval& r_child) {
        if (new_value != -1) {
            l_child.new_value = new_value;
            r_child.new_value = new_value;
            new_value = -1;
            // now sum is invalidated
            // we can avoid recomputation
            // if we carefully maintain at callers
            sum = l_child.get_sum() + r_child.get_sum();
        }
    }
};

void set_new_value(int l, int r, int v, int new_value, ve<Interval>& tree) {
    if (!tree[v].intersects(l, r)) {
        return;
    }
    if (tree[v].isin(l, r)) {
        tree[v].new_value = new_value;
        return;
    }
    tree[v].update_children(tree[v * 2], tree[v * 2 + 1]);
    set_new_value(l, r, v * 2, new_value, tree);
    set_new_value(l, r, v * 2 + 1, new_value, tree);
    tree[v].sum = tree[v * 2].get_sum()
                + tree[v * 2 + 1].get_sum();
}

int get_sum(int l, int r, int v, ve<Interval>& tree) {
    if (!tree[v].intersects(l, r)) {
        return 0;
    }
    if (tree[v].isin(l, r)) {
        return tree[v].get_sum();
    }
    tree[v].update_children(tree[v * 2], tree[v * 2 + 1]);
    auto res = get_sum(l, r, v * 2, tree)
             + get_sum(l, r, v * 2 + 1, tree);
    tree[v].sum = tree[v * 2].get_sum()
                + tree[v * 2 + 1].get_sum();
    return res;
}

void
solve()
{
    int n, q;
    cin >> n >> q;
    string s, t;
    cin >> s >> t;
    vi l(q), r(q);
    for (int i = 0; i < q; ++i) {
        cin >> l[i] >> r[i];
    }
    int k = 2;
    while (k < n) k *= 2;
    ve<Interval> tree(2 * k);
    for (int i = 0; i < k; ++i) {
        tree[i + k].l = i;
        tree[i + k].r = i + 1;
    }
    for (int i = 0; i < n; ++i) {
        tree[i + k].new_value = (t[i] == '0') ? 0 : 1;
    }
    for (int v = k - 1; v >= 1; --v) {
        tree[v].l = tree[v * 2].l;
        tree[v].r = tree[v * 2 + 1].r;
        tree[v].sum = tree[v * 2].get_sum()
                    + tree[v * 2 + 1].get_sum();
    }
    bool can = true;
    for (int i = q - 1; i >= 0; --i) {
        int lq = l[i] - 1, rq = r[i];
        int total_len = rq - lq;
        int sum_1 = get_sum(lq, rq, 1, tree);
        int sum_0 = total_len - sum_1;
        if (sum_1 == sum_0) {
            can = false;
            break;
        } else if (sum_0 < sum_1) {
            set_new_value(lq, rq, 1, 1, tree);
        } else {
            set_new_value(lq, rq, 1, 0, tree);
        }
    }
    if (can) {
        for (int v = 1; v < k; ++v) {
            tree[v].update_children(tree[v * 2], tree[v * 2 + 1]);
        }
        for (int i = 0; i < n; ++i) {
            int actual = tree[i + k].get_sum();
            int expected = (s[i] == '0') ? 0 : 1;
            if (actual != expected) {
                can = false;
            }
        }
    }
    if (can) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int
main()
{
    cin.sync_with_stdio(0);
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_) {
        solve();
    }
    return 0;
}