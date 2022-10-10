#include <bits/stdc++.h>
using namespace std;

struct Node {
    int ans, gcd;

    void leaf(int val) {
        ans = 1;
        gcd = val;
    }

    void Merge(Node l, Node r) {
        gcd = __gcd(l.gcd, r.gcd);
        ans = (gcd % l.gcd == 0 ? l.ans : 0) + (gcd % r.gcd == 0 ? r.ans : 0);
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
        if (l == r)
            st[p].leaf(a[l]);
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
        return query(1, 0, n-1, i, j).ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> s(n);
    for (int i=0; i<n; i++)
        cin >> s[i];

    SegmentTree st(s);
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        cout << r - l + 1 - st.query(l-1, r-1) << "\n";
    }

    return 0;
}