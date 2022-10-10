#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 5e5 + 10;
vector<int> v[MAXN];

struct node {
    int mn, lz, cnt, l, r;
    node *left, *right;

    int get_mn() { return mn + lz; }
    void merge() {
        int ml = left->get_mn(), mr = right->get_mn();
        if(mr < ml) {
            mn = mr;
            cnt = right->cnt;
        }
        else {
            mn = ml;
            cnt = left->cnt + ((ml == mr) ? right->cnt : 0);
        }
    }
    void push() {
        left->lz += lz;
        right->lz += lz;
        lz = 0;
    }

    node(int l, int r) : l(l), r(r), mn(0), lz(0), cnt(1) {
        if(l < r) {
            int m = (l + r)/2;
            left = new node(l, m);
            right = new node(m + 1, r);
        }
    }

    void upd(int rl, int rr, int v) {
        if(r < rl || rr < l)
            return;
        if(rl <= l && r <= rr) {
            lz += v;
            return;
        }
        push();
        left->upd(rl, rr, v);
        right->upd(rl, rr, v);
        merge();
    }

    int minv(int rl, int rr) {
        if(r < rl || rr < l)
            return int(1e9);
        if(rl <= l && r <= rr)
            return get_mn();
        push();
        merge();
        return min(left->minv(rl, rr), right->minv(rl, rr));
    }

    int qry(int rl, int rr) {
        if(r < rl || rr < l || get_mn() > 0)
            return 0;
        if(rl <= l && r <= rr)
            return cnt;
        push();
        merge();
        return left->qry(rl, rr) + right->qry(rl, rr);
    }

    void dbg() {
        if(l == r) {
            cout << get_mn() << " ";
            return;
        }
        push();
        merge();
        left->dbg();
        right->dbg();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll ans = 0;
    int n;
    cin >> n;
    node tree(1, n);
    int cL = 1;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        int s = v[x].size();
        v[x].push_back(i);
        if(s >= 3)
            cL = max(cL, v[x][s - 3] + 1);
        tree.upd((s ? v[x][s - 1] : 0) + 1, v[x][s], 2);
        if(s >= 1)
            tree.upd(1, v[x][s - 1], -1);
        if(tree.minv(cL, i) == 0)
            ans += tree.qry(cL, i);
    }
    cout << ans << '\n';
}