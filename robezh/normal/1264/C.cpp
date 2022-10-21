#include <bits/stdc++.h>
using namespace std;

#define lson(x) 2*x+1
#define rson(x) 2*x+2

typedef long long ll;
typedef pair<int, int> P;
const int N = (int)2e5 + 500, mod = (int)998244353;

ll fac[N], facinv[N];
ll inv[N];
ll pp[N], pinv[N];

ll val[N];

ll fp(ll x, ll k){
    if(k == 0) return 1;
    ll hf = fp(x, k/2);
    return k % 2 ? hf * hf % mod * x % mod: hf * hf % mod;
}

void init_fac() {
    inv[1] = 1;
    for(int i = 2; i < N; i++) inv[i] = (mod - (mod / i) * inv[mod % i] % mod) % mod;
    fac[0] = 1;
    for(int i = 1; i <= N-1; i++) fac[i] = fac[i-1] * i % mod;
    facinv[N-1] = fp(fac[N-1], mod - 2);
    for(int i = N-1 - 1; i >= 0; i--) facinv[i] = facinv[i+1] * (i+1) % mod;
}

ll get_prod(int l, int r) {
    return (pp[r] * (l == 0 ? 1 : pinv[l-1])) % mod;
}

struct node {
    ll psum;
    int l, r;
    bool bad;

    void merge(node &LHS, node &RHS) {
        if(LHS.bad) {
            *this = RHS;
            return ;
        }
        else if(RHS.bad) {
            *this = LHS;
            return ;
        }

        int mid = (l + r) / 2;
        psum = (RHS.psum + get_prod(RHS.l, RHS.r) * LHS.psum) % mod;
        l = LHS.l;
        r = RHS.r;
        bad = false;
    }
};

int n, q;

struct Tree {
    node dat[N * 4];

    void init_dat(int l, int r, int x){
        if(l == r){
            dat[x].psum = val[l] ;
            dat[x].l = dat[x].r = l;
            dat[x].bad = false;
            return ;
        }

        int mid = (l + r) / 2;
        init_dat(l, mid, lson(x));
        init_dat(mid+1, r, rson(x));
        dat[x].merge(dat[lson(x)], dat[rson(x)]);
    }

    node query(int a, int b, int x, int l, int r){
        if(r < a || b < l) return {0, 1, 0, true};

        int mid = (l + r) / 2;
        if(a <= l && r <= b) return dat[x];

        node res;
//        if(mid < a) return query(a, b, rson(x), mid+1, r);
//        else if(mid + 1 > b) return query(a, b, lson(x), l, mid);
//        else {
            node LHS = query(a, b, lson(x), l, mid);
            node RHS = query(a, b, rson(x), mid+1, r);
            res.merge(LHS, RHS);
            return res;
//        }

    }
} tree;

set<int> S;
int on[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    init_fac();

    cin >> n >> q;
    for(int i = 0; i < n; i++) {
        ll p; cin >> p;
        val[i] = 100 * inv[p] % mod;
        pp[i] = (i == 0 ? 1 : pp[i-1]) * val[i] % mod;
        pinv[i] = (i == 0 ? 1 : pinv[i-1]) * p % mod * inv[100] % mod;
    }
    tree.init_dat(0, n - 1, 0);
    S.insert(0);
    S.insert(n);
    ll res = tree.query(0, n - 1, 0, 0, n - 1).psum;
//    for(int i = 0; i < 2; i++) cout << i << ": " << tree.query(i, i, 0, 0, n - 1).psum << endl;
//    cout << res << endl;
    while(q--) {
        int x;
        cin >> x;
        x--;
        if(on[x]) {
            S.erase(x);
            auto it = S.lower_bound(x);
            int rb = *it;
            int lb = *(--it);
//            cout << lb << " " << rb << endl;
            res -= tree.query(x, rb - 1, 0, 0, n - 1).psum;
            res -= tree.query(lb, x - 1, 0, 0, n - 1).psum;
            res += tree.query(lb, rb - 1, 0, 0, n - 1).psum;
        }
        else {
            auto it = S.lower_bound(x);
            int rb = *it;
            int lb = *(--it);
//            cout << lb << " " << rb << endl;
            res += tree.query(x, rb - 1, 0, 0, n - 1).psum;
            res += tree.query(lb, x - 1, 0, 0, n - 1).psum;
            res -= tree.query(lb, rb - 1, 0, 0, n - 1).psum;

            S.insert(x);
        }
        on[x] = !on[x];
        res = (res % mod + mod) % mod;
        cout << res << '\n';
    }


}