#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
    int n;
    vector<int> st, lazy;

    SegmentTree(int _n) {
        n = _n;
        st.assign(4*n, 0);
        lazy.assign(4*n, 0);
    }

    int query(int p, int l, int r, int i, int j) {  // query for [i, j], inclusive
        if (i > r || j < l) // current segment outside query range
            return 0;

        if (lazy[p] != 0) {
            // node needs to be updated
            st[p] = (r - l + 1) * lazy[p]; // update the node
            if (l != r) {
                lazy[2*p] = lazy[p];   // mark children as lazy
                lazy[2*p+1] = lazy[p];
            }
            lazy[p] = 0;    // reset the lazy value of the node
        }

        if (l >= i && r <= j)   // current segment inside query range
            return st[p];

        // compute the left and right parts of the interval
        int m = (l + r) / 2;
        return query(2*p, l, m, i, j) + query(2*p+1, m+1, r, i, j);
    }

    int query(int i, int j) {
        return query(1, 0, n-1, i, j);
    }

    void update(int p, int l, int r, int i, int j, int value) {
        if (lazy[p] != 0) { // node needs to be updated
            st[p] = (r - l + 1) * lazy[p]; // update the node
            if (l != r) {
                lazy[2*p] = lazy[p];   // mark children as lazy
                lazy[2*p+1] = lazy[p];
            }
            lazy[p] = 0;    // reset the lazy value of the node
        }

        if (i > r || j < l) // current segment outside modified range
            return;
        if (l >= i && r <= j) { // current segment inside query range
            st[p] = (r - l + 1) * value;
            if (l != r) {
                // not leaf node
                lazy[2*p] = value;
                lazy[2*p+1] = value;
            }
            return;
        }

        int m = (l + r) / 2;
        update(2*p, l, m, i, j, value);
        update(2*p+1, m+1, r, i, j, value);
        st[p] = st[2*p] + st[2*p+1];
    }

    void update(int i, int j, int value) {
        update(1, 0, n-1, i, j, value);
    }
};

int a[100000], b[100000];
pair<int, int> queries[100000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++)
        cin >> a[i];
    for (int i=0; i<n; i++)
        cin >> b[i];

    int color = 1;
    SegmentTree st(n);
    while (m--) {
        int t, x;
        cin >> t >> x;
        x--;
        if (t == 1) {
            int y, k;
            cin >> y >> k;
            y--;
            queries[color] = make_pair(x, y);
            st.update(y, y+k-1, color);
            color++;
        } else {
            int c = st.query(x, x);
            if (c == 0)
                cout << b[x] << "\n";
            else
                cout << a[queries[c].first + x - queries[c].second] << "\n";
        }
    }

    return 0;
}