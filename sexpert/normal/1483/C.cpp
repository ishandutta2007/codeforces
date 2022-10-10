#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 3e5 + 10;
ll dp[MAXN], b[MAXN];
int h[MAXN], prv[MAXN], n;

struct node {
    int l, r;
    node *left, *right;
    ll x;

    node(int _l, int _r) : l(_l), r(_r), x(0) {
        if(l < r) {
            int m = (l + r)/2;
            left = new node(l, m);
            right = new node(m + 1, r);
        }
    }

    void upd(int p, ll v) {
        if(p < l || r < p) return;
        if(l == r) { x = v; return; }
        left->upd(p, v); right->upd(p, v);
        x = max(left->x, right->x);
    }

    ll qry(int rl, int rr) {
        if(rr < l || r < rl) return -1e18;
        if(rl <= l && r <= rr) return x;
        return max(left->qry(rl, rr), right->qry(rl, rr));
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> h[i];
    for(int i = 1; i <= n; i++)
        cin >> b[i];
    vector<int> cur;

    cur.push_back(0);
    for(int i = 1; i <= n; i++) {
        while(h[i] < h[cur.back()])
            cur.pop_back();
        prv[i] = cur.back();
        cur.push_back(i);
    }
    node tree(0, n);
    tree.upd(0, -1e18);
    for(int i = 1; i <= n; i++) {
        int p = prv[i];
        ll ans = tree.qry(p, i - 1) + b[i];
        if(p > 0)
            ans = max(ans, dp[p]);
        else
            ans = max(ans, b[i]);
        dp[i] = ans;
        tree.upd(i, dp[i]);
    }
    cout << dp[n] << '\n';
}