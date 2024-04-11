#include <bits/stdc++.h>
using namespace std;

#define lson(x) 2*x+1
#define rson(x) 2*x+2

typedef long long ll;
typedef pair<int, int> P;
const int N = (int)6e5 + 50;
const ll mod = (ll)1e9 + 7;

struct Qry {
    int i, x;
    void read() {
        cin >> i >> x; i--;
    }
};

ll fp(ll x, ll k) {
    if(k == 0) return 1;
    ll hf = fp(x, k / 2);
    return k % 2 == 0 ? hf * hf % mod : hf * hf % mod * x % mod;
}

int n, q, num[N];
int s[N];
P p[N];
ll pw2[N], inv2[N];
Qry qry[N];
int at[N];
int idx[N];

struct node {
    ll L, R;
    int cnt;

    void set_val(int val, int c) {
        L = R = val;
        cnt = c;
    }

    void merge(node &LHS, node &RHS) {
        cnt = LHS.cnt + RHS.cnt;
        L = (LHS.L + RHS.L * pw2[LHS.cnt]) % mod;
        R = (RHS.R + LHS.R * pw2[RHS.cnt]) % mod;
    }
};

struct Tree {
    node dat[N * 4];

    void init_dat(int l, int r, int x) {
        if(l == r) {
            dat[x].set_val(s[l], (s[l] != 0));
            return ;
        }
        int mid = (l + r) / 2;
        init_dat(l, mid, lson(x));
        init_dat(mid + 1, r, rson(x));
        dat[x].merge(dat[lson(x)], dat[rson(x)]);
    }

    void update(int pos, int x, int l, int r, int val, int c) {
        int mid = (l + r) / 2;
        if(l == r) {
            dat[x].set_val(val, c);
            return ;
        }
        if(pos <= mid) update(pos, lson(x), l, mid, val, c);
        else update(pos, rson(x), mid + 1, r, val, c);
        dat[x].merge(dat[lson(x)], dat[rson(x)]);
    }

    node query(int a, int b, int x, int l, int r) {
        if(r < a || b < l) return {0, 0, 0};
        int mid = (l + r) / 2;
        if(a <= l && r <= b) return dat[x];

        node res;
        node LHS = query(a, b, lson(x), l, mid);
        node RHS = query(a, b, rson(x), mid + 1, r);
        res.merge(LHS, RHS);
        return res;
    }

} tree;

void add(ll &to, ll val) {
    to += val;
    if(to >= mod) to -= mod;
}

ll get(int loc, int val) {
    node L = tree.query(0, loc - 1, 0, 0, n + q - 1);
    node R = tree.query(loc + 1, n + q - 1, 0, 0, n + q - 1);
//    assert(L.L * pw2[R.cnt] % mod == R.R * pw2[L.cnt] % mod);
    return  (L.L * pw2[R.cnt] + R.R * pw2[L.cnt]) % mod * val % mod;
}

ll get_cross(int loc) {
    node L = tree.query(0, loc - 1, 0, 0, n + q - 1);
    node R = tree.query(loc + 1, n + q - 1, 0, 0, n + q - 1);
//    assert(L.L * pw2[R.cnt] % mod == R.R * pw2[L.cnt] % mod);
    return  (L.L * R.R ) % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    pw2[0] = 1;
    for(int i = 1; i < N; i++) pw2[i] = pw2[i-1] * 2 % mod;
    inv2[0] = 1;
    inv2[1] = fp(2, mod - 2);
    for(int i = 2; i < N; i++) inv2[i] = inv2[i - 1] * inv2[1] % mod;

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> num[i];
        p[i] = {num[i], i};
    }
    cin >> q;
    for(int i = 0; i < q; i++) {
        qry[i].read();
        p[i + n] = {qry[i].x, i + n};
    }
    sort(p, p + n + q);
    for(int i = 0; i < n + q; i++) idx[p[i].second] = i;
    for(int i = 0; i < n; i++) {
        s[idx[i]] = num[i];
    }
    for(int i = 0; i < n + q; i++) {
        if(p[i].second < n) at[p[i].second] = i;
    }
    tree.init_dat(0, n + q - 1, 0);
    ll res = 0;
    for(int i = 0; i < n; i++) {
        add(res, get(idx[i], num[i]));
    }
    res = (res * inv2[1]) % mod;
    cout << res * inv2[n] % mod << '\n';
    for(int u = 0; u < q; u++) {
        int i = qry[u].i, val = qry[u].x;
        add(res, mod - get(at[i], p[at[i]].first));
        add(res, get_cross(at[i]));

        tree.update(at[i], 0, 0, n + q - 1, 0, 0);
        at[i] = idx[u + n];
        tree.update(at[i], 0, 0, n + q - 1, val, 1);

//        assert(p[at[i]].first == val);
        add(res, get(at[i], p[at[i]].first));
        add(res, mod - get_cross(at[i]));

        cout << res * inv2[n] % mod << '\n';
    }
}