#include <bits/stdc++.h>
using namespace std;
 
struct SegmentTree {
    int n, h;
    vector<int> st, a;
 
    void build(int p, int l, int r, bool op) {
        if (l == r)
            st[p] = a[l];
        else {
            int m = (l + r) / 2;
            build(2*p, l, m, !op);
            build(2*p+1, m+1, r, !op);
            if (op)
                st[p] = st[2*p] | st[2*p+1];
            else
                st[p] = st[2*p] ^ st[2*p+1];
        }
    }
 
    int query(int p, int l, int r, int i, int j, bool op) {  // query for [i, j], inclusive
        if (i > r || j < l) // current segment outside query range
            return INT_MAX;
        if (l >= i && r <= j)   // current segment inside query range
            return st[p];
 
        // compute the left and right parts of the interval
        int m = (l + r) / 2;
        if (op)
            return query(2*p, l, m, i, j, !op) | query(2*p+1, m+1, r, i, j, !op);
        else
            return query(2*p, l, m, i, j, !op) ^ query(2*p+1, m+1, r, i, j, !op);
    }
 
    int query(int i, int j) {
        return query(1, 0, n-1, i, j, h % 2 == 1);
    }
 
    void update(int p, int l, int r, int index, int value, bool op) {
        if (l == r) {
            a[index] = value;
            st[p] = value;
        } else {
            int m = (l + r) / 2;
            if (l <= index && index <= m)
                update(2*p, l, m, index, value, !op);
            else
                update(2*p+1, m+1, r, index, value, !op);
            if (op)
                st[p] = st[2*p] | st[2*p+1];
            else
                st[p] = st[2*p] ^ st[2*p+1];
        }
    }
 
    void update(int index, int value) {
        update(1, 0, n-1, index, value, h % 2 == 1);
    }
 
    SegmentTree(const vector<int> &_a) {
        a = _a;
        n = a.size();
        h = ceil(log2(n));
        st.assign(4*n, 0);
        build(1, 0, n-1, h % 2 == 1);
    }
};
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, a[131072];
    cin >> n >> m;
    n = pow(2, n);
    for (int i=0; i<n; i++)
        cin >> a[i];
    
    vector<int> va(a, a + n);
    SegmentTree st(va);
    for (int i=0; i<m; i++) {
        int p, b;
        cin >> p >> b;
        st.update(p-1, b);
        cout << st.query(0, n-1) << "\n";
    }
 
    return 0;
}