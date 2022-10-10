#include <bits/stdc++.h>
using namespace std;

struct Node {
    int n4, n7, n47, n74, l, r;
    bool lazy = false;

    void leaf(char c) {
        if (c == '4')
            n4 = 1, n7 = 0, n47 = 1, n74 = 1;
        else
            n4 = 0, n7 = 1, n47 = 1, n74 = 1;
    }

    void Merge(Node l, Node r) {
        this->l = l.l;
        this->r = r.r;
        if (l.lazy)
            l.apply();
        if (r.lazy)
            r.apply();
        n4 = l.n4 + r.n4;
        n7 = l.n7 + r.n7;
        n47 = max(l.n47 + r.n7, l.n4 + r.n47);
        n74 = max(l.n74 + r.n4, l.n7 + r.n74);
    }

    void push() {
        lazy = !lazy;
    }

    void apply() {
        swap(n4, n7);
        swap(n47, n74);
        lazy = false;
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
        st[p].l = l;
        st[p].r = r;
        if (l == r)
            st[p].leaf(s[l]);
        else {
            int m = (l + r) / 2;
            build(2*p, l, m);
            build(2*p+1, m+1, r);
            st[p].Merge(st[2*p], st[2*p+1]);
        }
    }

    Node query(int p, int i, int j) {
        if (st[p].l == i && st[p].r == j) {
            Node ret = st[p];
            if (ret.lazy)
                ret.apply();
            return ret;
        }

        Node ret;
        int m = (st[p].l + st[p].r) / 2;
        if (j <= m)
            ret = query(2*p, i, j);
        else if (i > m)
            ret = query(2*p+1, i, j);
        else
            ret.Merge(query(2*p, i, m), query(2*p+1, m+1, j));

        if (st[p].lazy) {
            ret.push();
            ret.apply();
        }

        return ret;
    }

    int query(int i, int j) {
        return query(1, i, j).n47;
    }

    void update(int p, int i, int j) {
        if (st[p].l == i && st[p].r == j) {
            st[p].push();
            return;
        }

        int m = (st[p].l + st[p].r) / 2;
        if (j <= m)
            update(2*p, i, j);
        else if (i > m)
            update(2*p+1, i, j);
        else {
            update(2*p, i, m);
            update(2*p+1, m+1, j);
        }
        st[p].Merge(st[2*p], st[2*p+1]);
    }

    void update(int i, int j) {
        update(1, i, j);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    string s;
    cin >> n >> m >> s;

    SegmentTree st(s);
    while (m--) {
        string command;
        cin >> command;
        if (command == "switch") {
            int l, r;
            cin >> l >> r;
            st.update(l-1, r-1);
        } else
            cout << st.query(0, n-1) << "\n";
    }

    return 0;
}