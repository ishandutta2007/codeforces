#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct node {
    int l, r, su, lz;
    node *left, *right;

    int get() {
        if(lz != -1)
            return lz * (r - l + 1);
        return su;
    }
    void merge() {
        su = left->get() + right->get();
    }
    void push() {
        if(lz != -1) {
            left->lz = lz;
            right->lz = lz;
        }
        lz = -1;
    }

    node(int _l, int _r, int* v) : l(_l), r(_r), su(0), lz(-1) {
        if(l == r) {
            su = v[l];
        }
        else {
            int m = (l + r)/2;
            left = new node(l, m, v);
            right = new node(m + 1, r, v);
            merge();
        }
    }

    void upd(int rl, int rr, int v) {
        if(rr < l || r < rl)
            return;
        if(rl <= l && r <= rr) {
            lz = v;
            return;
        }
        push();
        left->upd(rl, rr, v);
        right->upd(rl, rr, v);
        merge();
    }

    int qry(int rl, int rr) {
        if(rr < l || r < rl)
            return 0;
        if(rl <= l && r <= rr)
            return get();
        push();
        merge();
        return left->qry(rl, rr) + right->qry(rl, rr);
    }

    void dbg() {
        cout << "[" << l << ", " << r << "] " << su << " " << lz << " " << get() << '\n';
        if(l < r) {
            left->dbg();
            right->dbg();
        }
    }
};

const int MAXN = 2e5 + 10;
int guys[MAXN];

void solve() {
    int n, q;
    cin >> n >> q;
    string s, t;
    cin >> s >> t;
    for(int i = 1; i <= n; i++)
        guys[i] = (t[i - 1] - '0');
    node tree(1, n, guys);
    //tree.dbg();
    vector<array<int, 2>> qs(q);
    for(auto &[l, r] : qs)
        cin >> l >> r;
    reverse(qs.begin(), qs.end());
    for(auto &[l, r] : qs) {
        int sz = r - l + 1;
        int su = tree.qry(l, r);
        if(2 * su == sz) {
            cout << "NO\n";
            return;
        }
        if(2 * su < sz) {
            tree.upd(l, r, 0);
            //cout << "Replace " << l << " " << r << " with 0\n";
        }
        else {
            tree.upd(l, r, 1);
            //cout << "Replace " << l << " " << r << " with 1\n";
        }
    }
    //tree.dbg();
    for(int i = 0; i < n; i++) {
        if(s[i] - '0' != tree.qry(i + 1, i + 1)) {
            //cout << i << " " << s[i] << " " << tree.qry(i + 1, i + 1) << '\n';
            //tree.dbg();
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}

/*
0000000
0101010
5 7
4 5
3 4
2 3
1 2
2 6
*/