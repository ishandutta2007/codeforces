#include<bits/stdc++.h>
#define ls(x) x * 2 + 1
#define rs(x) x * 2 + 2

using namespace std;

typedef long long ll;
const int N = 400500, M = 305, B = 62, mod = (int)1e9 + 7;
ll INF = (ll)1e18 + 50;

int n,q;
ll mask[M];
ll invp[B];
vector<int> pms;
ll num[N];

ll fp(ll x, ll k){
    if(k == 0) return 1;
    ll hf = fp(x, k/2);
    return k % 2 ? hf * hf % mod * x % mod: hf * hf % mod;
}

ll inv(ll x) {
    return fp(x, mod - 2);
}

bool is_prime(int x) {
    for(int i = 2; i * i <= x; i++) if(x % i == 0) return false;
    return true;
}

struct node {
    ll dat, add, prod, bas;

    void merge(node &l, node &r) {
        prod = l.prod * r.prod % mod;
        dat = l.dat | r.dat;
    }
};

struct Tree {
    node nds[4*N];

    void push_down(int x, int l, int r) {
        node &cur = nds[x];
        if(cur.add != 0) {
            if(l < r) {
                int mid = (l + r) / 2;
                node &lson = nds[ls(x)], &rson = nds[rs(x)];
                lson.dat |= cur.add;
                lson.add |= cur.add;
                rson.dat |= cur.add;
                rson.add |= cur.add;

                lson.prod *= fp(cur.bas, mid - l + 1); lson.prod %= mod;
                lson.bas *= cur.bas; lson.bas %= mod;
                rson.prod *= fp(cur.bas, r - mid); rson.prod %= mod;
                rson.bas *= cur.bas; rson.bas %= mod;

            }
            cur.add = 0;
            cur.bas = 1;
        }
    }

    void init(int x = 0, int l = 0, int r = n-1) {
        nds[x].add = 0;
        nds[x].bas = 1;
        if(l == r) {
            nds[x].dat = mask[num[l]];
            nds[x].prod = num[l];
            return ;
        }
        int mid = (l + r) / 2;
        init(ls(x), l, mid);
        init(rs(x), mid + 1, r);
        nds[x].merge(nds[ls(x)], nds[rs(x)]);
    }

    node query(int a, int b, int x = 0, int l = 0, int r = n-1) {
        int mid = (l + r) / 2;
        if(r < a || l > b) return {0, 0, 1, 0};

        push_down(x, l, r);

        if(l >= a && r <= b) return nds[x];

        node LHS = query(a, b, ls(x), l, mid);
        node RHS = query(a, b, rs(x), mid+1, r);
        node res;
        res.merge(LHS, RHS);
        return res;
    }

    void update(int a, int b, int x, int l, int r, int val) {
        int mid = (l + r) / 2;
        if(r < a || l > b) return ;

        if(l < r) push_down(x, l, r);

        if(l >= a && r <= b) {
            nds[x].dat |= mask[val];
            nds[x].add |= mask[val];
            nds[x].bas *= val; nds[x].bas %= mod;
            nds[x].prod *= fp(val, r - l + 1); nds[x].prod %= mod;
            return ;
        }

        update(a, b, ls(x), l, mid, val);
        update(a, b, rs(x), mid+1, r, val);

        nds[x].merge(nds[ls(x)], nds[rs(x)]);
    }

    void update(int a, int b, int val) {
        update(a, b, 0, 0, n-1, val);
    }

} tree;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 2; i <= 300; i++) if(is_prime(i)) pms.push_back(i);
    assert(pms.size() == B);
    for(int i = 0; i <= 300; i++) {
        for(int j = 0; j < B; j++) if(i % pms[j] == 0) mask[i] |= (1LL << j);
    }
    for(int i = 0; i < B; i++) invp[i] = inv(pms[i]);

    cin >> n >> q;
    for(int i = 0; i < n; i++) cin >> num[i];

    tree.init(0, 0, n-1);


    while(q--) {
        string s; int l, r;
        cin >> s >> l >> r; l--, r--;
        if(s[0] == 'T') {
            node nd = tree.query(l, r);
            ll res = nd.prod;
            for(int j = 0; j < B; j++) {
                if(nd.dat & (1LL << j)) {
                    res *= (pms[j] - 1) * invp[j] % mod;
                    res %= mod;
                }
            }
            cout << res << "\n";
        }
        else {
            int val;
            cin >> val;
            tree.update(l, r, val);
        }
    }


}