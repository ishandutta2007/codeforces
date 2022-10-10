#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val, open, close;

    void leaf(char c) {
        val = 0;
        if (c == '(')
            open = 1, close = 0;
        else
            open = 0, close = 1;
    }

    void Merge(Node l, Node r) {
        int combine = min(l.open, r.close);
        val = l.val + r.val + 2 * combine;
        open = l.open + r.open - combine;
        close = l.close + r.close - combine;
    }
};

struct SegmentTree {
    int n;
    string s;
    vector<Node> st;

    SegmentTree(const string &_s) {
        s = _s;
        n = s.length();
        st.resize(4*n);
        build(1, 0, n-1);
    }

    void build(int p, int l, int r) {
        if (l == r)
            st[p].leaf(s[l]);
        else {
            int m = (l + r) / 2;
            build(2*p, l, m);
            build(2*p+1, m+1, r);
            st[p].Merge(st[2*p], st[2*p+1]);
        }
    }

    Node query(int p, int l, int r, int i, int j) {
        if (l == i && r == j)
            return st[p];

        int m = (l + r) / 2;
        if (j <= m)
            return query(2*p, l, m, i, j);
        else if (i > m)
            return query(2*p+1, m+1, r, i, j);
        Node ret;
        ret.Merge(query(2*p, l, m, i, m), query(2*p+1, m+1, r, m+1, j));
        return ret;
    }

    int query(int i, int j) {
        return query(1, 0, n-1, i, j).val;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    string s;
    int m;
    cin >> s >> m;
    SegmentTree st(s);
    while (m--) {
        int l, r;
        cin >> l >> r;
        cout << st.query(l-1, r-1) << "\n";
    }

    return 0;
}