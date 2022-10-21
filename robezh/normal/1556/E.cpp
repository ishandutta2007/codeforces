#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;


#define lson(x) 2*x+1
#define rson(x) 2*x+2

const int N = (int)1e5 + 50;

struct node {
    ll sum = 0, mxsuf = 0, mnsuf = 0;

    void merge(node &LHS, node &RHS) {
        sum = LHS.sum + RHS.sum;
        mxsuf = max(RHS.sum + LHS.mxsuf, RHS.mxsuf);
        mnsuf = min(RHS.sum + LHS.mnsuf, RHS.mnsuf);
    }
};

int n, q;
int a[N], b[N];
int val[N];

struct Tree {
    node dat[N * 4];

    void init_dat(int x, int l, int r){
        if(l == r) {
            dat[x] = {val[l], max(0, val[l]), min(0, val[l])};
            return ;
        }

        int mid = (l + r) / 2;
        init_dat(lson(x), l, mid);
        init_dat(rson(x), mid+1, r);
        dat[x].merge(dat[lson(x)], dat[rson(x)]);
    }

    node query(int a, int b, int x, int l, int r){
        if(r < a || b < l) return {0, 0, 0};

        int mid = (l + r) / 2;
        if(a <= l && r <= b) return dat[x];

        node res;
        node LHS = query(a, b, lson(x), l, mid);
        node RHS = query(a, b, rson(x), mid+1, r);
        res.merge(LHS, RHS);
        return res;
    }
} tree;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i], val[i] = b[i] - a[i];
    tree.init_dat(0, 0, n - 1);
    while(q--) {
        int l, r; cin >> l >> r; l--, r--;
        node res = tree.query(l, r, 0, 0, n - 1);
        if(res.sum != 0 || res.mxsuf > 0) cout << -1 << '\n';
        else cout << -res.mnsuf << '\n';
    }



}