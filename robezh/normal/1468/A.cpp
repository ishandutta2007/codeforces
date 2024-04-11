#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vi;
const int N = (int)5e5 + 50;

#define lson(x) 2*x+1
#define rson(x) 2*x+2

struct Tree {
    int dat[N * 4];

    void init_dat(int n){
        fill(dat, dat + 4 * n, 0);
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
        if(r < a || b < l) return 0;

        int mid = (l + r) / 2;
        if(a <= l && r <= b) return dat[x];
        return max(query(a, b, lson(x), l, mid), query(a, b, rson(x), mid+1, r));
    }
} tree[2];

int n, a[N];
vi to[N];
int dp[N];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        int res = 0;
        cin >> n;
        rep(i, 1, n + 1) {
            to[i].clear();
            cin >> a[i];
        }
        fill(dp, dp + n + 1, 0);
        tree[0].init_dat(n + 1);
        tree[1].init_dat(n + 1);
        rep(i, 1, n + 1) {
            int qr = tree[0].query(a[i] + 1, n, 0, 0, n);
            if(qr > 0) to[qr].push_back(i);
            tree[0].update(a[i], 0, 0, n, i);
        }
        rep(i, 1, n + 1) {
            for(int nxt : to[i]) {
                dp[nxt] = 2 + tree[1].query(0, a[nxt], 0, 0, n);
            }
            dp[i] = max(dp[i], 1 + tree[1].query(0, a[i], 0, 0, n));
            tree[1].update(a[i], 0, 0, n, dp[i]);
            res = max(res, dp[i]);
        }
        cout << res << '\n';
    }
}