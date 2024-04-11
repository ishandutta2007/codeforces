#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)35005;
const ll INF = (ll)1e18;


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

    void init(int x, int l, int r, ll num[]) {
        if(l == r) {
            dat[x].mn = num[l];
            dat[x].add = 0;
            return ;
        }
        int mid = (l + r) / 2;
        init(ls(x), l, mid, num);
        init(rs(x), mid + 1, r, num);
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

int n, k;
int a[N];
int last[N];
ll dp[2][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    rep(i, 1, n + 1) cin >> a[i];
    int nw = 0, la = 1;
    dp[nw][0] = 0;
    fill(dp[nw] + 1, dp[nw] + n + 1, INF);
    rep(i, 1, k + 1) {
        swap(nw, la);

        tree.init(0, 0, n, dp[la]);
        rep(j, 0, n + 1) last[j] = -1;
        rep(j, 0, n + 1) {
            if(j) {
                if(last[a[j]] != -1) {
//                    cout << "Adding " << 0 << " " << last[a[j]] - 1 << " " << j - last[a[j]] << endl;
                    tree.update(0, last[a[j]] - 1, 0, 0, n, j - last[a[j]]);
                }
                last[a[j]] = j;
            }
            dp[nw][j] = tree.query(0, j, 0, 0, n);
//            cout << i << " " << j << " " << dp[nw][j] << endl;
        }
    }
    cout << dp[nw][n] << endl;

}