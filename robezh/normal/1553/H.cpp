#include <bits/stdc++.h>
using namespace std;

#define lson(x) 2*x+1
#define rson(x) 2*x+2

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)(1 << 19) + 5, INF = (int)1e9;

int k, n;
int in[N];

struct node {
    int hs, lb, rb, mn;
};

node merge(node &L, node &R) {
    return {
        L.hs || R.hs,
        L.hs ? L.lb: L.lb + R.lb ,
        R.hs ? R.rb : R.rb + L.rb,
        min(min(L.mn, R.mn), (L.hs && R.hs ? L.rb + R.lb + 1 : INF))
    };
}

struct Tree {
    node v[4 * N];
    int bt[4 * N];
    void build(int x, int l, int r) {
        bt[x] = 0;
        if(l == r) {
            if(in[l]) v[x] = {1, 0, 0, INF};
            else v[x] = {0, 1, 1, INF};
            return ;
        }
        int mid = (l + r) / 2;
        build(lson(x), l, mid);
        build(rson(x), mid + 1, r);
        v[x] = merge(v[lson(x)], v[rson(x)]);
//        cout << x << " " << v[x].lb << " " << v[x].rb << " " << v[x].mn << endl;
    }

    void rebuild(int x, int l, int r, int d, int td) {
//        cout << x << " " << l << " " << r << endl;
        if(d == td) {
            bt[x] ^= 1;
        } else {
            int mid = (l + r) / 2;
            rebuild(lson(x), l, mid, d + 1, td);
            rebuild(rson(x), mid + 1, r, d + 1, td);
        }
        if(!bt[x]) v[x] = merge(v[lson(x)], v[rson(x)]);
        else v[x] = merge(v[rson(x)], v[lson(x)]);
    }


} tree;

int res[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    rep(i, 0, n) {
        int x; cin >> x;
        in[x] = 1;
    }
    tree.build(0, 0, (1 << k) - 1);
    int curmask = 0;
    res[curmask] = tree.v[0].mn;
    rep(i, 1, (1 << k)) {
        int bt = 0;
        while(bt < k - 1 && i % (1 << (bt + 1)) == 0) bt++;
        curmask ^= 1 << (k - 1 - bt);
//        cout << bitset<5>(curmask) << endl;
        tree.rebuild(0, 0, (1 << k) - 1, 0, bt);
        res[curmask] = tree.v[0].mn;
    }

    rep(i, 0, (1 << k)) cout << res[i] << " ";
    cout << endl;




}