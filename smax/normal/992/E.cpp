#include <bits/stdc++.h>
using namespace std;

struct Node {
    int mx;
    long long sum;

    void leaf(int val) {
        sum = mx = val;
    }

    void Merge(Node a, Node b) {
        sum = a.sum + b.sum;
        mx = max(a.mx, b.mx);
    }
};

struct SegmentTree {
    int n;
    vector<int> a;
    vector<Node> st;

    SegmentTree(const vector<int> &_a) {
        a = _a;
        n = a.size();
        st.resize(4*n);
        build(1, 0, n-1);
    }

    void build(int p, int l, int r) {
        if (l == r) {
            st[p].leaf(a[l]);
            return;
        }

        int m = (l + r) / 2;
        build(2*p, l, m);
        build(2*p+1, m+1, r);
        st[p].Merge(st[2*p], st[2*p+1]);
    }

    long long querySum(int p, int l, int r, int i, int j) {
        if (i > j)
            return 0;
        if (l == i && r == j)
            return st[p].sum;

        int m = (l + r) / 2;
        if (j <= m)
            return querySum(2*p, l, m, i, j);
        else if (i > m)
            return querySum(2*p+1, m+1, r, i, j);
        return querySum(2*p, l, m, i, m) + querySum(2*p+1, m+1, r, m+1, j);
    }

    int leftMost(int p, int l, int r, long long s) {
        if (l == r)
            return l;

        int m = (l + r) / 2;
        if (st[2*p].mx >= s)
            return leftMost(2*p, l, m, s);
        return leftMost(2*p+1, m+1, r, s);
    }

    int queryMax(int p, int l, int r, int i, int j, long long s) {
        if (i > r || j < l)
            return -1;
        if (i <= l && r <= j) {
            if (st[p].mx < s)
                return -1;
            return leftMost(p, l, r, s);
        }

        int m = (l + r) / 2, ret = queryMax(2*p, l, m, i, j, s);
        if (ret == -1)
            ret = queryMax(2*p+1, m+1, r, i, j, s);
        return ret;
    }

    void update(int p, int l, int r, int idx, int val) {
        if (l == r) {
            st[p].leaf(val);
            return;
        }

        int m = (l + r) / 2;
        if (idx <= m)
            update(2*p, l, m, idx, val);
        else
            update(2*p+1, m+1, r, idx, val);
        st[p].Merge(st[2*p], st[2*p+1]);
    }

    void update(int idx, int val) {
        update(1, 0, n-1, idx, val);
    }

    int query() {
        int i = 0;
        long long sum = 0;
        while (i < n) {
            int ii = queryMax(1, 0, n-1, i, n-1, sum);
            if (ii == -1)
                return -1;
            long long pref = querySum(1, 0, n-1, 0, ii-1), val = querySum(1, 0, n-1, ii, ii);
            if (pref == val)
                return ii + 1;
            i = ii + 1;
            sum = pref + val;
        }
        return -1;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i=0; i<n; i++)
        cin >> a[i];

    SegmentTree st(a);

    while (q--) {
        int p, x;
        cin >> p >> x;
        st.update(p-1, x);
        cout << st.query() << "\n";
    }

    return 0;
}