#include <bits/stdc++.h>
using namespace std;

#define lson(x) 2*x+1
#define rson(x) 2*x+2

typedef long long ll;
const int MOD = 998244353, N = (int)2e5 + 50;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Tree {
    pii dat[N * 4];

    void init_dat(){
        fill(dat, dat + N * 4, pii{-1, -1});
    }

    void update(int pos, int x, int l, int r, pii p){
        int mid = (l + r) / 2;
        if(l == r) {
            dat[x] = p;
            return ;
        }
        if(pos <= mid) update(pos, lson(x), l, mid, p);
        else update(pos, rson(x), mid+1, r, p);
        dat[x] = max(dat[lson(x)], dat[rson(x)]);
    }

    pii query(int a, int b, int x, int l, int r){
        if(r < a || b < l) return {-1, -1};

        int mid = (l + r) / 2;
        if(a <= l && r <= b) return dat[x];

        return max(query(a, b, lson(x), l, mid), query(a, b, rson(x), mid+1, r));
    }
} tree;

struct rg {
    int l, r, idx, loc;
};

int n;
rg rgs[N];
int res[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 0, n) {
        cin >> rgs[i].l >> rgs[i].r;
        rgs[i].l--, rgs[i].r--;
        rgs[i].idx = i;
    }
    set<int> S;
    rep(i, 0, n) S.insert(i);
    sort(rgs, rgs + n, [](const rg &a, const rg &b) {
        return a.r < b.r;
    });
    rep(i, 0, n) {
        auto it = S.lower_bound(rgs[i].l);
        assert(it != S.end());
        rgs[i].loc = *it;
        S.erase(it);
    }
    rep(i, 0, n) res[rgs[i].idx] = rgs[i].loc;
    tree.init_dat();
    sort(rgs, rgs + n, [](const rg &a, const rg &b) {
        return a.loc < b.loc;
    });
    rep(i, 0, n) {
        pii p = tree.query(rgs[i].l, rgs[i].r, 0, 0, n - 1);
        if(p.first >= rgs[i].loc) {
            cout << "NO\n";
            rep(j, 0, n) cout << res[j] + 1 << " ";
            cout << '\n';
            swap(res[rgs[i].idx], res[p.second]);
            rep(j, 0, n) cout << res[j] + 1 << " ";
            cout << '\n';
            return 0;
        }
        tree.update(rgs[i].loc, 0, 0, n - 1, {rgs[i].r, rgs[i].idx});
    }
    cout << "YES\n";
    rep(j, 0, n) cout << res[j] + 1 << " ";
    cout << '\n';
}