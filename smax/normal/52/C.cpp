#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
    int n;
    vector<long long> st, a, lazy;

    SegmentTree(const vector<long long> &_a) {
        a = _a;
        n = a.size();
        st.assign(4*n, 0);
        lazy.assign(4*n, 0);
        build(1, 0, n-1);
    }

    void build(int p, int l, int r) {
        if (l == r)
            st[p] = a[l];
        else {
            int m = (l + r) / 2;
            build(2*p, l, m);
            build(2*p+1, m+1, r);
            st[p] = min(st[2*p], st[2*p+1]);
        }
    }

    long long query(int p, int l, int r, int i, int j) {  // query for [i, j], inclusive
        if (i > r || j < l) // current segment outside query range
            return LLONG_MAX;

        if (lazy[p] != 0) {
            // node needs to be updated
            st[p] += lazy[p]; // update the node
            if (l != r) {
                lazy[2*p] += lazy[p];   // mark children as lazy
                lazy[2*p+1] += lazy[p];
            }
            lazy[p] = 0;    // reset the lazy value of the node
        }

        if (l >= i && r <= j)   // current segment inside query range
            return st[p];

        // compute the left and right parts of the interval
        int m = (l + r) / 2;
        return min(query(2*p, l, m, i, j), query(2*p+1, m+1, r, i, j));
    }

    long long query(int i, int j) {
        return query(1, 0, n-1, i, j);
    }

    void update(int p, int l, int r, int i, int j, long long value) {
        if (lazy[p] != 0) { // node needs to be updated
            st[p] += lazy[p]; // update the node
            if (l != r) {
                lazy[2*p] += lazy[p];   // mark children as lazy
                lazy[2*p+1] += lazy[p];
            }
            lazy[p] = 0;    // reset the lazy value of the node
        }

        if (i > r || j < l) // current segment outside modified range
            return;
        if (l >= i && r <= j) { // current segment inside query range
            st[p] += value;
            if (l != r) {
                // not leaf node
                lazy[2*p] += value;
                lazy[2*p+1] += value;
            }
            return;
        }

        int m = (l + r) / 2;
        update(2*p, l, m, i, j, value);
        update(2*p+1, m+1, r, i, j, value);
        st[p] = min(st[2*p], st[2*p+1]);
    }

    void update(int i, int j, long long value) {
        update(1, 0, n-1, i, j, value);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i=0; i<n; i++)
        cin >> a[i];

    SegmentTree st(a);
    int m;
    cin >> m;
    cin.ignore();
    while (m--) {
        string line;
        getline(cin, line);

        int lf, rg, v;
        stringstream ss(line);
        ss >> lf >> rg;
        if (ss >> v) {
            if (lf > rg) {
                st.update(lf, n - 1, v);
                st.update(0, rg, v);
            } else
                st.update(lf, rg, v);
        } else {
            if (lf > rg)
                cout << min(st.query(lf, n - 1), st.query(0, rg)) << "\n";
            else
                cout << st.query(lf, rg) << "\n";
        }
    }

    return 0;
}