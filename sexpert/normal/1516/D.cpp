#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 1e5 + 10;
const int INF = 1e9 + 7;
int prime[MAXN], a[MAXN], go[18][MAXN], to[MAXN], div_by[MAXN];

struct node {
    int l, r, v;
    node *left, *right;

    node(int _l, int _r) : l(_l), r(_r), v(INF) {
        if(l < r) {
            int m = (l + r)/2;
            left = new node(l, m);
            right = new node(m + 1, r);
        }
    }

    void upd(int p, int u) {
        if(r < p || p < l)
            return;
        if(l == r) {
            v = u;
            return;
        }
        left->upd(p, u);
        right->upd(p, u);
        v = min(left->v, right->v);
    }

    int qry(int rl, int rr) {
        if(rr < l || r < rl || rr < rl) return INF;
        if(rl <= l && r <= rr) return v;
        return min(left->qry(rl, rr), right->qry(rl, rr));
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for(int p = 2; p < MAXN; p++) {
        if(prime[p])
            continue;
        for(int q = p; q < MAXN; q += p)
            prime[q] = p;
    }
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    for(int i = n; i >= 1; i--) {
        int x = a[i], nxt = n + 1;
        while(x > 1) {
            int p = prime[x];
            while(x % p == 0)
                x /= p;
            if(div_by[p])
                nxt = min(nxt, div_by[p]);
            div_by[p] = i;
        }
        to[i] = nxt;
    }
    node tree(1, n);
    for(int i = n; i >= 1; i--) {
        int nxt = to[i];
        nxt = min(nxt, tree.qry(i + 1, nxt - 1));
        go[0][i] = nxt;
        tree.upd(i, nxt);
    }

    go[0][n + 1] = n + 1;
    for(int l = 0; l < 17; l++) {
        for(int i = 1; i <= n + 1; i++) {
            go[l + 1][i] = go[l][go[l][i]];
            //cout << go[l][i] << " ";
        }
        //cout << '\n';
    }

    while(q--) {
        int l, r, ans = 0;
        cin >> l >> r;
        for(int lv = 17; lv >= 0; lv--) {
            if(go[lv][l] <= r) {
                ans += (1 << lv);
                l = go[lv][l];
            }
        }
        cout << ans + 1 << '\n';
    }
}