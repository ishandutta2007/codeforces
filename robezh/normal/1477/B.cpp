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
#define ls(x) x * 2 + 1
#define rs(x) x * 2 + 2
const int N = (int)2e5 + 50;

struct node {
    int sum, st;

    void add_val(int x, int len) {
        st = x;
        sum = x * len;
    }

    void merge(node &ls, node &rs) {
        sum = ls.sum + rs.sum;
    }
};

string s, f;

struct Tree {
    node dat[4 * N];

    void push_down(int x, int l, int r) {
        if(dat[x].st != -1) {
            if(l < r) {
                int mid = (l + r) / 2;
                dat[ls(x)].add_val(dat[x].st, mid - l + 1);
                dat[rs(x)].add_val(dat[x].st, r - mid);
            }
            dat[x].st = -1;
        }
    }

    void init(int x, int l, int r) {
        if(l == r) {
            dat[x].sum = f[l] - '0';
            dat[x].st = -1;
            return ;
        }
        int mid = (l + r) / 2;
        init(ls(x), l, mid);
        init(rs(x), mid + 1, r);
        dat[x].st = -1;
        dat[x].merge(dat[ls(x)], dat[rs(x)]);
    }

    bool check(int x, int l, int r) {
        if(l == r) return dat[x].sum == s[l] - '0';
        int mid = (l + r) / 2;
        push_down(x, l, r);
        return check(ls(x), l, mid) && check(rs(x), mid + 1, r);
    }

    int qsum(int a, int b, int x, int l, int r) {
        int mid = (l + r) / 2;
        if(r < a || l > b) return 0;
        push_down(x, l, r);
        if(l >= a && r <= b) return dat[x].sum;
        return qsum(a, b, ls(x), l, mid) + qsum(a, b, rs(x), mid+1, r);
    }

    void update(int a, int b, int x, int l, int r, int v) {
        int mid = (l + r) / 2;
        if(r < a || l > b) return ;

        push_down(x, l, r);

        if(l >= a && r <= b) {
            dat[x].add_val(v, r - l + 1);
            return ;
        }

        update(a, b, ls(x), l, mid, v);
        update(a, b, rs(x), mid+1, r, v);

        dat[x].merge(dat[ls(x)], dat[rs(x)]);
    }

} tree;

int n, q;
int l[N], r[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> q;
        cin >> s >> f;
        tree.init(0, 0, n - 1);
        rep(i, 0, q) {
            cin >> l[i] >> r[i]; l[i]--, r[i]--;
        }
        bool bad = false;
        for (int i = q - 1; i >= 0; i--) {
            int c1 = tree.qsum(l[i], r[i], 0, 0, n - 1), c0 = r[i] - l[i] + 1 - c1;
//            cout << i << " " << c0 << " " << c1 << endl;
            if(c1 == c0) {
                bad = true;
                break;
            } else if(c1 < c0) {
                tree.update(l[i], r[i], 0, 0, n - 1, 0);
            } else {
                tree.update(l[i], r[i], 0, 0, n - 1, 1);
            }
        }
        bad |= !tree.check(0, 0, n - 1);
        cout << (bad ? "NO\n" : "YES\n");

    }
}