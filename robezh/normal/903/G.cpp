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
const int N = (int)2e5 + 50, INF = (int)1e9;

#define ls(x) x * 2 + 1
#define rs(x) x * 2 + 2

struct node {
    ll mn, add;

    void add_val(ll x) {
        mn += x;
        add += x;
    }

    void merge(node &ls, node &rs) {
        mn = min(ls.mn, rs.mn);
    }
};

struct Tree {
    node dat[4 * N];

    void push_down(int x, int l, int r) {
        if(dat[x].add) {
            if(l < r) {
                dat[ls(x)].add_val(dat[x].add);
                dat[rs(x)].add_val(dat[x].add);
            }
            dat[x].add = 0;
        }
    }

    void init(int x, int l, int r, ll *a) {
        if(l == r) {
            dat[x] = {a[l], 0};
            return ;
        }
        int mid = (l + r) / 2;
        init(ls(x), l, mid, a);
        init(rs(x), mid + 1, r, a);
        dat[x].add = 0;
        dat[x].merge(dat[ls(x)], dat[rs(x)]);
    }

    ll query(int a, int b, int x, int l, int r) {
        int mid = (l + r) / 2;
        if(r < a || l > b) return INF;

        push_down(x, l, r);

        if(l >= a && r <= b) return dat[x].mn;

        return min(query(a, b, ls(x), l, mid), query(a, b, rs(x), mid+1, r));
    }

    void update(int a, int b, int x, int l, int r, ll delta) {
        int mid = (l + r) / 2;
        if(r < a || l > b) return ;

        push_down(x, l, r);

        if(l >= a && r <= b) {
            dat[x].add_val(delta);
            return ;
        }

        update(a, b, ls(x), l, mid, delta);
        update(a, b, rs(x), mid+1, r, delta);

        dat[x].merge(dat[ls(x)], dat[rs(x)]);
    }

} tree;

int n, m, q;
ll a[N], b[N];
ll amax[N];

struct edge {
    int to, cost;
};

vector<edge> to[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> q;
    rep(i, 0, n - 1) {
        cin >> a[i] >> b[i + 1];
    }
    tree.init(0, 0, n - 1, b);
    rep(i, 0, m) {
        int x, y, z; cin >> x >> y >> z; x--, y--;
        to[x].push_back({y, z});
    }
    rep(i, 0, n) {
        for (auto &e : to[i]) {
            tree.update(0, e.to, 0, 0, n - 1, e.cost);
        }
        amax[i] = a[i] + tree.dat[0].mn;
    }
    tree.init(0, 0, n - 1, amax);
    cout << tree.dat[0].mn << "\n";
    rep(i, 0, q) {
        int pos, v; cin >> pos >> v; pos--;
        tree.update(pos, pos, 0, 0, n - 1, v - a[pos]);
        a[pos] = v;
        cout << tree.dat[0].mn << '\n';
    }

}