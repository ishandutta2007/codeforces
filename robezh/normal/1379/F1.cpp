#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
#define Lnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int N = (int)2e5 + 50;
const int INF = (int)1e9;
#define lson(x) 2*x+1
#define rson(x) 2*x+2

int n, m, q;
set<int> c1[N], c0[N];

struct node {
    int mn1, mx0;
    bool good;

    void set(int x, int y) {
        mn1 = x, mx0 = y;
        good = mn1 > mx0;
    }

    void merge(node &LHS, node &RHS) {
        mn1 = min(LHS.mn1, RHS.mn1);
        mx0 = max(LHS.mx0, RHS.mx0);
        good = LHS.good && RHS.good && LHS.mn1 > RHS.mx0;
    }
};

struct Tree {
    node dat[N * 4];

    void init_dat(int n){
        fill(dat, dat + 4 * n, node{INF, -INF, true});
    }

    void update(int pos, int x, int l, int r, int mn, int mx){
        int mid = (l + r) / 2;
        if(l == r) {
            dat[x].set(mn, mx);
            return ;
        }
        if(pos <= mid) update(pos, lson(x), l, mid, mn, mx);
        else update(pos, rson(x), mid+1, r, mn, mx);
        dat[x].merge(dat[lson(x)], dat[rson(x)]);
    }
} tree;

map<pii, int> in;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> q;
    tree.init_dat(n);
    while(q--) {
        int x, y; cin >> x >> y; x--, y--;
        if(!in[{x, y}]) {
            if(y % 2 == 0) c1[x / 2].insert(y / 2);
            else c0[x / 2].insert(y / 2);
        } else {
            if(y % 2 == 0) c1[x / 2].erase(y / 2);
            else c0[x / 2].erase(y / 2);
        }
        int mn1 = c1[x / 2].empty() ? INF : *c1[x / 2].begin();
        int mx0 = c0[x / 2].empty() ? -INF : *c0[x / 2].rbegin();
        tree.update(x / 2, 0, 0, n - 1, mn1, mx0);
        in[{x, y}] = !in[{x, y}];
//        cout << mn1 << " " << mx0 << endl;
//        cout << tree.dat[0].mx1 << " " << tree.dat[0].mn0 << endl;
        cout << (tree.dat[0].good ? "YES" : "NO") << '\n';
    }
}