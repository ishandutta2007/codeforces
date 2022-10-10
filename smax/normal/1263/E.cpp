#include <bits/stdc++.h>
using namespace std;

struct Node {
    int minVal = 0, maxVal = 0, lazy = 0, l, r;

    void leaf(int val) {
        minVal += val;
        maxVal += val;
    }

    void Merge(Node l, Node r) {
        this->l = l.l;
        this->r = r.r;
        if (l.lazy)
            l.apply();
        if (r.lazy)
            r.apply();
        minVal = min(l.minVal, r.minVal);
        maxVal = max(l.maxVal, r.maxVal);
    }

    void push(int val) {
        lazy += val;
    }

    void apply() {
        minVal += lazy;
        maxVal += lazy;
        lazy = 0;
    }
};

struct SegmentTree {
    int n;
    vector<Node> st;

    SegmentTree(int _n) {
        n = _n;
        st.resize(4*n);
        build(1, 0, n-1);
    }

    void build(int p, int l, int r) {
        st[p].l = l;
        st[p].r = r;
        if (l == r)
            return;

        int m = (l + r) / 2;
        build(2*p, l, m);
        build(2*p+1, m+1, r);
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
            ret.push(st[p].lazy);
            ret.apply();
        }

        return ret;
    }

    int minQuery(int i, int j) {
        return query(1, i, j).minVal;
    }

    int maxQuery(int i, int j) {
        return query(1, i, j).maxVal;
    }

    void update(int p, int i, int j, int value) {
        if (st[p].l == i && st[p].r == j) {
            st[p].push(value);
            return;
        }

        int m = (st[p].l + st[p].r) / 2;
        if (j <= m)
            update(2*p, i, j, value);
        else if (i > m)
            update(2*p+1, i, j, value);
        else {
            update(2*p, i, m, value);
            update(2*p+1, m+1, j, value);
        }
        st[p].Merge(st[2*p], st[2*p+1]);
    }

    void update(int i, int j, int value) {
        if (value != 0)
            update(1, i, j, value);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    string s;
    cin >> n >> s;

    string text(n, ' ');
    int cursor = 0;
    SegmentTree st(n);
    for (int i=0; i<n; i++) {
        if (s[i] == 'L')
            cursor = max(0, cursor - 1);
        else if (s[i] == 'R')
            cursor++;
        else {
            int change = (text[cursor] == '(' ? -1 : text[cursor] == ')' ? 1 : 0);
            if (s[i] == '(')
                st.update(cursor, n - 1, 1 + change);
            else if (s[i] == ')')
                st.update(cursor, n - 1, -1 + change);
            else
                st.update(cursor, n - 1, change);
            text[cursor] = s[i];
        }
        if (st.minQuery(0, n - 1) < 0 || st.minQuery(n - 1, n - 1) != 0)
            cout << "-1 ";
        else
            cout << st.maxQuery(0, n - 1) << " ";
    }
    cout << "\n";

    return 0;
}