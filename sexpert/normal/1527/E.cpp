#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

struct node {
    int l, r, mx, lz;
    node *left, *right;

    int get() {
        return mx + lz;
    }
    void merge() {
        mx = min(left->get(), right->get());
    }
    void compose(int x) {
        lz += x;
    }
    void push() {
        left->lz += lz;
        right->lz += lz;
        lz = 0;
    }
    void reset() {
        mx = 0;
        lz = 0;
        if(l < r) {
            left->reset();
            right->reset();
        }
    }

    node(int _l, int _r) : l(_l), r(_r), mx(0), lz(0) {
        if(l < r) {
            int m = (l + r)/2;
            left = new node(l, m);
            right = new node(m + 1, r);
        }
    }

    void upd(int rl, int rr, int v) {
        if(rr < l || r < rl)
            return;
        if(rl <= l && r <= rr) {
            compose(v);
            return;
        }
        push();
        left->upd(rl, rr, v);
        right->upd(rl, rr, v);
        merge();
    }

    int qry(int rl, int rr) {
        if(rr < l || r < rl)
            return INF;
        if(rl <= l && r <= rr)
            return get();
        push();
        merge();
        return min(left->get(), right->get());
    }

    void dbg() {
        cout << "[" << l << ", " << r << "] " << mx << " " << lz << '\n';
        if(l < r) {
            left->dbg();
            right->dbg();
        }
    }
};

const int MAXN = 35353;
int a[MAXN], nxt[MAXN], occ[MAXN], n, k;

int dp[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    for(int i = n; i >= 0; i--) {
        if(occ[a[i]])
            nxt[i] = occ[a[i]];
        occ[a[i]] = i;
    }

    /*for(int i = 1; i <= n; i++)
        cout << nxt[i] << " ";
    cout << '\n';*/

    for(int i = 1; i <= n; i++)
        dp[i] = INF;

    dp[n + 1] = 0;

    node tree(1, n);

    while(k--) {
        tree.reset();
        for(int i = 1; i <= n; i++)
            tree.upd(i, i, dp[i + 1]);

        for(int i = n; i >= 1; i--) {
            int x = a[i];
            if(nxt[i]) {
                int df = nxt[i] - i;
                //cout << "difference " << i << " " << nxt[i] << '\n';
                tree.upd(nxt[i], n, df);
            }
            dp[i] = tree.qry(i, n);
            //cout << tree.qry(i, n) << '\n';
            //tree.dbg();
        }

        /*for(int i = 1; i <= n; i++)
            cout << dp[i] << " ";
        cout << '\n';*/
    }

    cout << dp[1] << '\n';
}