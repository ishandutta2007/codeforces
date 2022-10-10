#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

struct node {
    int l, r;
    node *left, *right;
    ll lz[2], val;

    ll getv() { return (lz[0] * val + lz[1]) % MOD; }
    void merge() { val = (left->getv() + right->getv()) % MOD; }
    void compose(ll a, ll b) {
        lz[0] = (lz[0] * a) % MOD;
        lz[1] = (lz[1] * a) % MOD;
        lz[1] = (lz[1] + b) % MOD;
    }
    void push() {
        left->compose(lz[0], lz[1]);
        right->compose(lz[0], lz[1]);
        lz[0] = 1;
        lz[1] = 0;
    }

    node(int l, int r, int *v) : l(l), r(r) {
        lz[0] = 1;
        lz[1] = 0;
        if(l < r) {
            int m = (l + r)/2;
            left = new node(l, m, v);
            right = new node(m + 1, r, v);
            merge();
        }
        else
            val = v[l];
    }

    void upd(int rl, int rr, ll a, ll b) {
        if(r < rl || rr < l)
            return;
        if(rl <= l && r <= rr) {
            compose(a, b);
            return;
        }
        push();
        left->upd(rl, rr, a, b);
        right->upd(rl, rr, a, b);
        merge();
    }

    ll qry(int rl, int rr) {
        if(r < rl || rr < l)
            return 0;
        if(rl <= l && r <= rr)
            return getv();
        push();
        merge();
        return (left->qry(rl, rr) + right->qry(rl, rr)) % MOD;
    }
};

ll _inv(ll b) {
    ll e = MOD - 2, res = 1;
    for(ll k = 1; k <= e; k *= 2) {
        if(k & e) res = (res * b) % MOD;
        b = (b * b) % MOD;
    }
    return res;
}

const int MAXQ = 2e5 + 10;
ll inv[MAXQ];
int q, curv, d[MAXQ], tin[MAXQ], tout[MAXQ], curt, v[MAXQ];
vector<int> adj[MAXQ];

void dfs(int s = 1) {
    tin[s] = ++curt;
    for(auto v : adj[s])
        dfs(v);
    tout[s] = curt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for(int i = 1; i < MAXQ; i++)
        inv[i] = _inv(i);

    vector<vector<int>> qs;
    cin >> v[1] >> q;
    curv = 1;
    for(int i = 0; i < q; i++) {
        int t, x, y;
        cin >> t;
        if(t == 1) {
            cin >> x >> y;
            adj[x].push_back(++curv);
            qs.push_back({t, x, y});
        }
        else {
            cin >> x;
            qs.push_back({t, x});
        }
    }
    dfs();
    node res(1, curv, v);
    for(int i = 1; i <= curv; i++)
        v[i] = 1;
    node coef(1, curv, v);
    curv = 1;
    for(auto q : qs) {
        if(q[0] == 1) {
            int v = q[1];
            ll up = ((d[v] + 2) * inv[d[v] + 1]) % MOD;
            d[v]++;
            coef.upd(tin[v], tout[v], up, 0);
            res.upd(tin[v], tout[v], up, 0);
            curv++;
            ll co = coef.qry(tin[curv], tin[curv]);
            res.upd(tin[curv], tin[curv], 0, (co * q[2]) % MOD);
        }
        else {
            ll x = res.qry(tin[q[1]], tout[q[1]]);
            x = (x * _inv(coef.qry(tin[q[1]], tin[q[1]]))) % MOD;
            x = (x * (d[q[1]] + 1)) % MOD;
            cout << x << '\n';
        }
    }
}