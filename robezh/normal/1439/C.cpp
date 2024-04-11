#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)2e5 + 50;
typedef pair<ll, ll> pll;
#define ls(x) x * 2 + 1
#define rs(x) x * 2 + 2


int n, q;
int a[N];

struct node {
    ll sum;
    int mn, st;

    void set_val(int val, int l, int r) {
        st = val;
        sum = 1LL * (r - l + 1) * val;
        mn = val;
    }

    void merge(node &ls, node &rs) {
        mn = min(ls.mn, rs.mn);
        sum = ls.sum + rs.sum;
    }
};

struct Tree {
    node dat[4 * N];

    void push_down(int x, int l, int r) {
        if(dat[x].st) {
            if(l < r) {
                int mid = (l + r) / 2;
                dat[ls(x)].set_val(dat[x].st, l, mid);
                dat[rs(x)].set_val(dat[x].st, mid + 1, r);
            }
            dat[x].st = 0;
        }
    }

    void init(int x, int l, int r) {
        if(l == r) {
            dat[x].mn = dat[x].sum = a[l];
            dat[x].st = 0;
            return ;
        }
        int mid = (l + r) / 2;
        init(ls(x), l, mid);
        init(rs(x), mid + 1, r);
        dat[x].st = 0;
        dat[x].merge(dat[ls(x)], dat[rs(x)]);
    }

    ll getsum(int a, int b, int x, int l, int r) {
        int mid = (l + r) / 2;
        if(r < a || l > b) return 0;
        push_down(x, l, r);
        if(l >= a && r <= b) return dat[x].sum;
        return getsum(a, b, ls(x), l, mid) + getsum(a, b, rs(x), mid+1, r);
    }

    void update(int a, int b, int x, int l, int r, int st) {
        int mid = (l + r) / 2;
        if(r < a || l > b) return ;
        push_down(x, l, r);
        if(l >= a && r <= b) {
            dat[x].set_val(st, l, r);
            return ;
        }
        update(a, b, ls(x), l, mid, st);
        update(a, b, rs(x), mid+1, r, st);
        dat[x].merge(dat[ls(x)], dat[rs(x)]);
    }


    pll find_first_over_sum(int x, int l, int r, ll sum) {
        int mid = (l + r) / 2;
        if(l == r) return {l, sum};
        push_down(x, l, r);
        if(dat[ls(x)].sum <= sum) {
            return find_first_over_sum(rs(x), mid + 1, r, sum - dat[ls(x)].sum);
        } else {
            return find_first_over_sum(ls(x), l, mid, sum);
        }
    }


    int find_first_mn_under(int x, int l, int r, int mn) {
        int mid = (l + r) / 2;
        if(l == r) return l;
        push_down(x, l, r);
        if(dat[ls(x)].mn <= mn) return find_first_mn_under(ls(x), l, mid, mn);
        else return find_first_mn_under(rs(x), mid + 1, r, mn);
    }
} tree;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    rep(i, 0, n) cin >> a[i];
    tree.init(0, 0, n - 1);
    while(q--) {
        int tp, x;
        ll y;
        cin >> tp >> x >> y;
        if(tp == 1) {
            x--;
            int fir = tree.find_first_mn_under(0, 0, n - 1, y);
            if(fir <= x) tree.update(fir, x, 0, 0, n - 1, y);
        } else {
            x--;
            int st = x;
            ll res = 0;
            while(st < n) {
                ll ssum = tree.getsum(0, st - 1, 0, 0, n - 1);
                if(y + ssum >= tree.dat[0].sum) {
                    res += n - st;
//                    cout << st << " to " << n -  1;
                    break;
                }

//                cout << y + ssum << endl;
                pll nxt = tree.find_first_over_sum(0, 0, n - 1, y + ssum);
                res += nxt.first - st;
                y = nxt.second;
//                cout << st << " to " << nxt.first - 1<< " rem: " << y << endl;

                if(y < tree.dat[0].mn) break;
                st = tree.find_first_mn_under(0, 0, n - 1, y);
            }
            cout << res << '\n';
        }
    }
}