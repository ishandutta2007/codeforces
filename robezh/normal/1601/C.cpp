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

const int N = (int)1e6 + 50, INF = (int)1e9;

int a[N], b[N];
int n, m;
int bit[N];
pii p[N];

void add(int x, int val) {
    for(int i = x; i < n; i |= i + 1) bit[i] += val;
}

ll get(int x) {
    ll res = 0;
    for(int i = x; i >= 0; i = (i & (i + 1)) - 1)  res += bit[i];
    return res;
}

ll get_inversion() {
    rep(i, 0, n) {
        p[i] = {a[i], i};
    }
    sort(p, p + n);
    fill(bit, bit + n, 0);
    ll res = 0;
    for (int i = n - 1; i >= 0; i--) {
        res += get(p[i].second);
        add(p[i].second, 1);
    }
    return res;
}

#define ls(x) x * 2 + 1
#define rs(x) x * 2 + 2

struct node {
    int mn, add;

    void add_val(int x) {
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

    void init(int _n) {
        fill(dat, dat + 4 * _n, node{0, 0});
    }

    void update(int a, int b, int x, int l, int r, int delta) {
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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> m;
        rep(i, 0, n) cin >> a[i];
        rep(i, 0, m) cin >> b[i];
        ll res = get_inversion();
//        cout << "inv: " << res << endl;
        sort(b, b + m);
        tree.init(n + 1);
        rep(i, 0, n) {
            tree.update(i + 1, n, 0, 0, n, 1);
        }
        int rb = 0, lb = 0;
        rep(i, 0, n) p[i] = {a[i], i};
        sort(p, p + n);
        rep(i, 0, m) {
            while(rb < n && p[rb].first <= b[i]) {
                tree.update(p[rb].second + 1, n, 0, 0, n, -1);
                rb++;
            }
            while(lb < n && p[lb].first < b[i]) {
                tree.update(0, p[lb].second, 0, 0, n, 1);
                lb++;
            }
            res += tree.dat[0].mn;
        }
        cout << res << '\n';
    }

}