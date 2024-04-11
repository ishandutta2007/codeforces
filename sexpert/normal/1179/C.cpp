#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 1e9;
const int MAXN = 3e5 + 5;
int sd[1000005], s[1000005], d[1000005];
int a[MAXN], b[MAXN];

struct node {
    int l, r, mx, lazy;
    node *left, *right;

    inline int get() { return mx + lazy; }
    inline void merge() { mx = max(left->get(), right->get()); }
    inline void compose(int e) { lazy += e; }
    inline void push() {
        left->compose(lazy);
        right->compose(lazy);
        lazy = 0;
        merge();
    }

    node(int l, int r) : l(l), r(r), lazy(0) {
        if(l == r)
            mx = sd[l];
        else {
            int m = (l + r)/2;
            left = new node(l, m);
            right = new node(m + 1, r);
            merge();
        }
    }

    void upd(int rl, int rr, int v) {
        if(rr < l || r < rl) return;
        if(rl <= l && r <= rr) {compose(v); return; }
        push();
        left->upd(rl, rr, v);
        right->upd(rl, rr, v);
        merge();
    }

    int find() {
        if(get() <= 0) return -1;
        if(l == r) return l;
        push();
        merge();
        if(right->get() > 0) return right->find();
        return left->find();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        s[a[i]]++;
    }
    for(int i = 1; i <= m; i++) {
        cin >> b[i];
        d[b[i]]++;
    }
    for(int i = 1000004; i >= 0; i--) {
        s[i] += s[i + 1];
        d[i] += d[i + 1];
        sd[i] = s[i] - d[i];
    }
    node tree(1, 1000005);
    int q;
    cin >> q;
    while(q--) {
        int t, p, val;
        cin >> t >> p >> val;
        if(t == 1) {
            int old = a[p];
            if(val > old)
                tree.upd(old + 1, val, 1);
            if(val < old)
                tree.upd(val + 1, old, -1);
            a[p] = val;
        }
        if(t == 2) {
            int old = b[p];

            if(val > old)
                tree.upd(old + 1, val, -1);
            if(val < old)
                tree.upd(val + 1, old, 1);

            b[p] = val;
        }

        cout << tree.find() << '\n';
    }
}