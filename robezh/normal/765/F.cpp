#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int N = (int)3e5 + 50, INF = (int)1e9;

#define ls(x) x * 2 + 1
#define rs(x) x * 2 + 2

#define lson(x) 2*x+1
#define rson(x) 2*x+2


struct node {
    int mn, st;

    void set_val(int x) {
        mn = min(mn, x);
        st = min(st, x);
    }

    void merge(node &ls, node &rs) {
        mn = min(ls.mn, rs.mn);
    }
};

struct Tree {
    node dat[4 * N];

    void push_down(int x, int l, int r) {
        if(l < r) {
            dat[ls(x)].set_val(dat[x].st);
            dat[rs(x)].set_val(dat[x].st);
        }
    }

    void init(int _n) {
        fill(dat, dat + 4 * _n, node{INF, INF});
    }

    int query(int a, int b, int x = 0, int l = 0, int r = N-1) {
        int mid = (l + r) / 2;
        if(r < a || l > b) return INF;

        push_down(x, l, r);

        if(l >= a && r <= b) return dat[x].mn;

        return min(query(a, b, ls(x), l, mid), query(a, b, rs(x), mid+1, r));
    }

    void update(int a, int b, int x, int l, int r, int v) {
        int mid = (l + r) / 2;
        if(r < a || l > b) return ;

        push_down(x, l, r);

        if(l >= a && r <= b) {
            dat[x].set_val(v);
            return ;
        }

        update(a, b, ls(x), l, mid, v);
        update(a, b, rs(x), mid+1, r, v);

        dat[x].merge(dat[ls(x)], dat[rs(x)]);
    }
} mntree;

struct MxTree {
    int dat[N * 4];

    void init_dat(int _n){
        fill(dat, dat + 4 * _n, -INF);
    }

    void update(int pos, int x, int l, int r, int val){
        int mid = (l + r) / 2;
        if(l == r) {
            dat[x] = max(dat[x], val);
            return ;
        }
        if(pos <= mid) update(pos, lson(x), l, mid, val);
        else update(pos, rson(x), mid+1, r, val);
        dat[x] = max(dat[lson(x)], dat[rson(x)]);
    }

    int query(int a, int b, int x, int l, int r){
        if(r < a || b < l) return -INF;

        int mid = (l + r) / 2;
        if(a <= l && r <= b) return dat[x];

        return max(query(a, b, lson(x), l, mid), query(a, b, rson(x), mid+1, r));
    }
} mxtree;

int n, m, a[N];

vi b;

pii qrs[N];
vector<pii> qs[N];
int fres[N];

void solve() {
    b.clear();
    rep(i, 0, n) b.push_back(a[i]);
    sort(all(b));
    b.resize(unique(all(b)) - b.begin());

    rep(i, 0, n) qs[i].clear();
    mntree.init(n);
    mxtree.init_dat(n);
    rep(i, 0, m) qs[qrs[i].second].push_back({qrs[i].first, i});
    rep(i, 0, n) {
        int val_pos = lower_bound(all(b), a[i]) - b.begin();
        int pos = mxtree.query(val_pos, n - 1, 0, 0, n - 1);
        while(pos != -INF) {
            mntree.update(0, pos, 0, 0, n - 1, a[pos] - a[i]);
            int nxt_up = (a[pos] + a[i] - 1) / 2;
            int nxt_pos = lower_bound(all(b), nxt_up + 1) - b.begin();
            pos = mxtree.query(val_pos, nxt_pos - 1, 0, 0, n - 1);
        }

        for (auto q : qs[i]) {
            fres[q.second] = min(fres[q.second], mntree.query(q.first, i - 1, 0, 0, n - 1));
        }
        mxtree.update(val_pos, 0, 0, n - 1, i);
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 0, n) cin >> a[i], a[i]++;
    cin >> m;
    rep(i, 0, m) {
        int l, r; cin >> l >> r; l--, r--;
        qrs[i] = {l, r};
    }
    fill(fres, fres + m, INF);
    rep(swapped, 0, 2) {
        if(swapped) {
            reverse(a, a + n);
            rep(i, 0, m) {
                int l = n - 1 - qrs[i].second, r = n - 1 - qrs[i].first;
                qrs[i] = {l, r};
            }
        }
        solve();
    }
    rep(i, 0, m) cout << fres[i] << '\n';

}