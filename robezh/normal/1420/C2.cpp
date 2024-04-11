#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const ll INF = (ll)1e18;
const int N = (int)3e5 + 50;

int n, q;
int a[N];

#define lson(x) 2*x+1
#define rson(x) 2*x+2

struct node {
    ll s[2][2];

    node(int val = 0) {
        s[0][0] = val;
        s[1][1] = -val;
        s[0][1] = s[1][0] = 0;
    }
};

node empty_node() {
    node res;
    res.s[0][0] = res.s[1][1] = -INF;
    res.s[0][1] = res.s[1][0] = 0;
    return res;
}

node merge(node L, node R) {
    node res;
    res.s[0][0] = max(L.s[0][0] + R.s[1][0], L.s[0][1] + R.s[0][0]);
    res.s[0][1] = max(L.s[0][0] + R.s[1][1], L.s[0][1] + R.s[0][1]);
    res.s[1][0] = max(L.s[1][0] + R.s[1][0], L.s[1][1] + R.s[0][0]);
    res.s[1][1] = max(L.s[1][0] + R.s[1][1], L.s[1][1] + R.s[0][1]);
    return res;
}

struct Tree {
    node dat[4 * N];
    void init(int x, int l, int r) {
        if(l == r) {dat[x] = node(a[l]); return ;}
        int mid = (l + r) / 2;
        init(lson(x), l, mid);
        init(rson(x), mid + 1, r);
        dat[x] = merge(dat[lson(x)], dat[rson(x)]);
    }

    void update(int pos, int x, int l, int r, int val) {
        if(l == r) {
            dat[x] = node(val);
            return ;
        }
        int mid = (l + r) / 2;
        if(pos <= mid) update(pos, lson(x), l, mid, val);
        else update(pos, rson(x), mid + 1, r, val);
        dat[x] = merge(dat[lson(x)], dat[rson(x)]);
    }

    node query(int a, int b, int x, int l, int r) {
        if(r < a || b < l) return empty_node();
        int mid = (l + r) / 2;
        if(a <= l && r <= b) return dat[x];
        else return merge(query(a, b, lson(x), l, mid),
                          query(a, b, rson(x), mid + 1, r));
    }
} tree;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> q;
        rep(i, 0, n) cin >> a[i];
        tree.init(0, 0, n - 1);
        cout << tree.dat[0].s[0][0] << '\n';
        rep(i, 0, q) {
            int l, r; cin >> l >> r; l--, r--;
            tree.update(l, 0, 0, n - 1, a[r]);
            tree.update(r, 0, 0, n - 1, a[l]);
            swap(a[l], a[r]);
            cout << tree.dat[0].s[0][0] << '\n';;
        }
    }

}