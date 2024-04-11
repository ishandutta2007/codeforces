#include <bits/stdc++.h>
using namespace std;

#define lson(x) 2*x+1
#define rson(x) 2*x+2

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int N = (int)6e5 + 50;

struct node {
    int sum, smx;
};

node merge(node L, node R) {
    return {L.sum + R.sum, max(L.smx + R.sum, R.smx)};
}

struct Tree {
    node dat[N * 4];

    void init_dat(int x, int l, int r){
        if(l == r){
            dat[x] = {-1, 0};
            return ;
        }

        int mid = (l + r) / 2;
        init_dat(lson(x), l, mid);
        init_dat(rson(x), mid+1, r);
        dat[x] = merge(dat[lson(x)], dat[rson(x)]);
    }

    void update(int pos, int x, int l, int r, int val){
        int mid = (l + r) / 2;
        if(l == r) {
            dat[x].sum += val;
            dat[x].smx = max(dat[x].smx, 0);
            return ;
        }
        if(pos <= mid) update(pos, lson(x), l, mid, val);
        else update(pos, rson(x), mid+1, r, val);
        dat[x] = merge(dat[lson(x)], dat[rson(x)]);
    }

    node query(int a, int b, int x, int l, int r){
        if(r < a || b < l) return {0, 0};

        int mid = (l + r) / 2;
        if(a <= l && r <= b) return dat[x];

        return merge(query(a, b, lson(x), l, mid), query(a, b, rson(x), mid+1, r));
    }
} tree;

int n, m, k;
map<pii, int> mp;
multiset<int> S;

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);

    cin >> n >> k >> m;
    k--;
    tree.init_dat(0, 0, 3 * n - 1);
//    cout << "new" << endl;
    rep(i, 0, m) {
        int x, y; cin >> x >> y; x--, y--;
        if(mp[{x, y}]) {
            tree.update(y + abs(x - k), 0, 0, 3 * n - 1, -1);
            S.erase(S.find(y + abs(x - k)));
        }
        mp[{x, y}] = 1 - mp[{x, y}];
        if(mp[{x, y}]) {
            tree.update(y + abs(x - k), 0, 0, 3 * n - 1, 1);
            S.insert(y + abs(x - k));
        }
        if(S.empty()) {
            cout << 0 << '\n';
            continue;
        }
//        cout << *S.rend() << endl;
        cout << max(0, tree.query(0, *S.rbegin(), 0, 0, 3 * n - 1).smx
                                             + (*S.rbegin() - (n - 1))) << '\n';
    }
}