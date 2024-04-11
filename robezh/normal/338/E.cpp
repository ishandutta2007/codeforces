#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)3e5 + 50;

#define lson(x) 2*x+1
#define rson(x) 2*x+2

struct node {
    int lmax, sum;

    void set_node(int val) {
        sum = val;
        lmax = max(0, val);
    }


    void merge(node &LHS, node &RHS) {
        sum = LHS.sum + RHS.sum;
        lmax = max(LHS.lmax, LHS.sum + RHS.lmax);
    }
};

int val[N];

struct Tree {
    node dat[N * 4];

    void init_dat(int x, int l, int r){
        if(l == r){
            dat[x].set_node(val[l]);
            return ;
        }

        int mid = (l + r) / 2;
        init_dat(lson(x), l, mid);
        init_dat(rson(x), mid+1, r);
        dat[x].merge(dat[lson(x)], dat[rson(x)]);
    }

    void update(int pos, int x, int l, int r, int d){
        int mid = (l + r) / 2;
        if(l == r) {
            dat[x].set_node(dat[x].sum + d);
            return ;
        }
        if(pos <= mid) update(pos, lson(x), l, mid, d);
        else update(pos, rson(x), mid+1, r, d);
        dat[x].merge(dat[lson(x)], dat[rson(x)]);
    }
} tree;

int n, m, len, h;
int a[N], b[N];
vi vals;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> h;
    rep(i, 0, m) cin >> b[i], vals.push_back(b[i]);
    rep(i, 0, n) cin >> a[i], a[i] = h - a[i], vals.push_back(a[i]);
    sort(all(vals));
    vals.resize(unique(all(vals)) - vals.begin());
    rep(i, 0, m) b[i] = (lower_bound(all(vals), b[i]) - vals.begin()), val[b[i]]++;
    rep(i, 0, n) a[i] = (lower_bound(all(vals), a[i]) - vals.begin());
    len = sz(vals);
    rep(i, 0, m) val[a[i]]--;
    tree.init_dat(0, 0, len - 1);
    int ans = (tree.dat[0].lmax == 0);
    rep(i, m, n) {
        tree.update(a[i - m], 0, 0, len - 1, 1);
        tree.update(a[i], 0, 0, len - 1, -1);
        ans += (tree.dat[0].lmax == 0);
    }
    cout << ans << '\n';

}