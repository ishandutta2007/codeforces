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
const int N = (int)1e5 + 5, mod = (int)1e9 + 7;

#define lson(x) 2*x+1
#define rson(x) 2*x+2

struct node {
    int sufmn, sum;

    void merge(node &LHS, node &RHS) {
        sufmn = min(LHS.sufmn + RHS.sum, RHS.sufmn);
        sum = LHS.sum + RHS.sum;
    }
};

struct Tree {
    node dat[N * 4];

    void init_dat(int n){
        fill(dat, dat + 4 * n, node{0, 0});
    }

    void update(int pos, int x, int l, int r, int d){
        int mid = (l + r) / 2;
        if(l == r) {
            dat[x].sum += d;
            dat[x].sufmn = min(0, dat[x].sum);
            return ;
        }
        if(pos <= mid) update(pos, lson(x), l, mid, d);
        else update(pos, rson(x), mid+1, r, d);
        dat[x].merge(dat[lson(x)], dat[rson(x)]);
    }
} tree;

int n, m, pm;
int a[N];
ll gsum[N];
vi bs[N];

ll cdiv(ll x, ll k) {
    return (x + k - 1) / k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    int tm = N;
    tree.init_dat(tm);
    while(T--) {
        cin >> n >> m;
        pm = 0;
        rep(i, 0, n) {
            cin >> a[i];
            tree.update(a[i], 0, 0, tm - 1, 1);
        }
//        int cid = 0;
        rep(i, 0, m) {
            bs[i].clear();
            int k; cin >> k;
            pm += k;
            gsum[i] = 0;
            while(k--) {
                int ag; cin >> ag; bs[i].push_back(ag);
                gsum[i] += ag;
            }
            tree.update(cdiv(gsum[i], sz(bs[i])), 0, 0, tm - 1, -1);
        }

        vi res(pm, 0);
        int cid = 0;
        rep(i, 0, m) {
            tree.update(cdiv(gsum[i], sz(bs[i])), 0, 0, tm - 1, 1);
            for (int x : bs[i]) {
                int c0 = cdiv(gsum[i] - x, sz(bs[i]) - 1);
                tree.update(c0, 0, 0, tm - 1, -1);
                res[cid++] = tree.dat[0].sufmn >= 0;
                tree.update(c0, 0, 0, tm - 1, 1);
            }
            tree.update(cdiv(gsum[i], sz(bs[i])), 0, 0, tm - 1, -1);
        }
        for (int x : res) cout << x;
        cout << '\n';

        rep(i, 0, m) tree.update(cdiv(gsum[i], sz(bs[i])), 0, 0, tm - 1, 1);
        rep(i, 0, n) tree.update(a[i], 0, 0, tm - 1, -1);
    }
}