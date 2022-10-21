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
const int N = (int)2e5 + 50, mod = (int)1e9 + 7;

#define lson(x) 2*x+1
#define rson(x) 2*x+2

int n, a[N];

struct Tree {
    int dat[N * 4];

    void init_dat(int n){
        fill(dat, dat + 4 * n, 0);
    }

    void update(int pos, int x, int l, int r, int val){
        int mid = (l + r) / 2;
        if(l == r) {
            dat[x] = (dat[x] + val) % mod;
            return ;
        }
        if(pos <= mid) update(pos, lson(x), l, mid, val);
        else update(pos, rson(x), mid+1, r, val);
        dat[x] = (dat[lson(x)] + dat[rson(x)]) % mod;
    }

    int query(int a, int b, int x, int l, int r){
        if(r < a || b < l) return 0;

        int mid = (l + r) / 2;
        if(a <= l && r <= b) return dat[x];

        return (query(a, b, lson(x), l, mid) + query(a, b, rson(x), mid+1, r)) % mod;
    }
} tree;

ll dpl[N], dpr[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    int tc = 0;
    while(T--) {
        cin >> n;
        vi vs;
        rep(i, 0, n) cin >> a[i], vs.push_back(a[i]);
        
        sort(all(vs));
        rep(i, 0, n) {
            a[i] = lower_bound(all(vs), a[i]) - vs.begin();
        }
        ll res = 0;

        tree.init_dat(n);
        rep(i, 0, n) {
            int cur = tree.query(0, a[i] - 1, 0, 0, n - 1) + 1;
            dpl[i] = cur;
            tree.update(a[i], 0, 0, n - 1, cur);

        }
        tree.init_dat(n);
        for (int i = n - 1; i >= 0; i--) {
            int cur = tree.query(a[i] + 1, n - 1, 0, 0, n - 1) + 1;
            dpr[i] = cur;
            tree.update(a[i], 0, 0, n - 1, cur);
        }

        tree.init_dat(n);
        set<int> mx;
        set<int> has;
        for (int i = n - 1; i >= 0; i--) {
            ll cur;
            auto it = mx.upper_bound(a[i]);

            if(it != mx.end()) {
                cur = tree.query(a[i] + 1, *it, 0, 0, n - 1);
            } else {
                cur = 1;
                mx.insert(a[i]);
            }
            if(has.find(a[i]) == has.end()) tree.update(a[i], 0, 0, n - 1, cur);
            if(mx.find(a[i]) != mx.end()) has.insert(a[i]);
            res += (dpr[i] - cur) * dpl[i];
            res %= mod;
        }

        cout << (res % mod + mod) % mod << '\n';
    }

}