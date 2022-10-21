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
const int N = (int)2e5 + 50;

struct node {
    ll L, R, full, sum;

    void merge(node &LHS, node &RHS, int x) {
        if(LHS.sum == 0) *this = RHS;
        if(RHS.sum == 0) *this = LHS;
        L = LHS.full && x ? LHS.L + RHS.L : LHS.L;
        R = RHS.full && x ? LHS.R + RHS.R : RHS.R;
        full = LHS.full && RHS.full && x;
        sum = LHS.sum + RHS.sum + (x ? LHS.R * RHS.L : 0);
    }
};

int n, q, a[N];
int good[N];

struct Tree {
    node dat[N * 4];

    void init_dat(int x, int l, int r){
        if(l == r){
            dat[x] = {1, 1, 1, 1};
            return ;
        }

        int mid = (l + r) / 2;
        init_dat(lson(x), l, mid);
        init_dat(rson(x), mid+1, r);
        dat[x].merge(dat[lson(x)], dat[rson(x)], good[mid]);
    }

    void update(int pos, int x, int l, int r) {
        int mid = (l + r) / 2;
        if(l == r) {
            return ;
        }
        if(pos <= mid) update(pos, lson(x), l, mid);
        else update(pos, rson(x), mid+1, r);
        dat[x].merge(dat[lson(x)], dat[rson(x)], good[mid]);
    }

    node query(int a, int b, int x, int l, int r){
        if(r < a || b < l) return {0, 0, 0, 0};

        int mid = (l + r) / 2;
        if(a <= l && r <= b) return dat[x];

        node res;
        node LHS = query(a, b, lson(x), l, mid);
        node RHS = query(a, b, rson(x), mid+1, r);
        res.merge(LHS, RHS, good[mid]);
        return res;
    }
} tree;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n - 1) {
        good[i] = (a[i] <= a[i + 1]);
    }
    tree.init_dat(0, 0, n - 1);
    while(q--) {
        int tp; cin >> tp;
        if(tp == 1) {
            int i, val; cin >> i >> val; i--;
            a[i] = val;
            if(i) {
                good[i - 1] = (a[i - 1] <= a[i]);
//                tree.update(i - 1, 0, 0, n - 1);
            }
            if(i + 1 < n) {
                good[i] = (a[i] <= a[i + 1]);
            }
            tree.update(i, 0, 0, n - 1);
        } else {
            int l, r; cin >> l >> r; l--, r--;
            node res = tree.query(l, r, 0, 0, n - 1);
            cout << res.sum << '\n';
        }
    }



}