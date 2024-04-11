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
#define ls(x) x * 2 + 1
#define rs(x) x * 2 + 2

const int N = (int)4e5 + 50, LOGN = 19, INF = (int)1e9;

struct RMQ {
    int mm[N], st[LOGN][N];

    void build(int n, int a[]) {
        mm[0]=-1;
        for(int i = 1; i <= 2 * n; i++) mm[i]= (i & (i-1)) == 0 ? mm[i-1] + 1 : mm[i-1];
        for(int i = 0; i < 2 * n; i++){
            st[0][i] = a[i % n];
        }
        for(int lg = 1; lg < LOGN; lg++){
            for(int j = 0; j + (1 << lg) - 1 < 2 * n; j++){
                st[lg][j] = min(st[lg-1][j], st[lg-1][j+(1<<(lg-1))]);
            }
        }
    }

    int rmq(int l, int r){
        int k = mm[r - l + 1];
        return min(st[k][l], st[k][r-(1<<k)+1]);
    }
} rmq;


struct node {
    int mx, add;

    void add_val(int x) {
        mx += x;
        add += x;
    }

    void merge(node &ls, node &rs) {
        mx = max(ls.mx, rs.mx);
    }
};

int dep[N];

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

    void init(int x, int l, int r) {
        if(l == r) {
            dat[x].mx = dep[l];
            dat[x].add = 0;
            return ;
        }
        int mid = (l + r) / 2;
        init(ls(x), l, mid);
        init(rs(x), mid + 1, r);
        dat[x].add = 0;
        dat[x].merge(dat[ls(x)], dat[rs(x)]);
    }

    int query(int a, int b, int x, int l, int r) {
        int mid = (l + r) / 2;
        if(r < a || l > b) return -INF;

        push_down(x, l, r);

        if(l >= a && r <= b) return dat[x].mx;

        return max(query(a, b, ls(x), l, mid), query(a, b, rs(x), mid+1, r));
    }

    void update(int a, int b, int x, int l, int r, int delta) {
        if(l == 0 && r == 7) {
//            cout << "updating " << a << " " << b << " with " << delta << endl;
        }
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


int n, a[N], pos[N];
int res[N];

void dfs(int l, int r, int d) {
    if(l > r) return ;
    int rt = pos[rmq.rmq(l, r)];
//    cout << l << " " << r << " " << rt << endl;
    dep[rt] = d;
    dfs(l, rt - 1, d + 1);
    dfs(rt + 1, r, d + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 0, n) cin >> a[i], a[i]--, pos[a[i]] = i;
    rmq.build(n, a);
    dfs(0, n - 1, 0);

    tree.init(0, 0, 2 * n - 1);
    rep(i, 0, n) {
        res[i] = tree.query(i, i + n - 1, 0, 0, 2 * n - 1);
//        cout << i << ": " << res[i] << endl;
        int l = i, r = i + n, mid;
        while(l + 1 < r) {
            mid = (l + r) / 2;
            if(rmq.rmq(i, mid) >= a[i]) l = mid;
            else r = mid;
        }
//        cout << rmq.rmq(i + 1, l) << endl;
        tree.update(i + 1, l, 0, 0, 2 * n - 1, -1);
        l = i, r = i + n;
        while(l + 1 < r) {
            mid = (l + r) / 2;
            if(rmq.rmq(mid, i + n) >= a[i]) r = mid;
            else l = mid;
        }
        tree.update(r, i + n - 1, 0, 0, 2 * n - 1, 1);
        if(l > i) tree.update(i + n, i + n, 0, 0, 2 * n - 1,
                              tree.query(l, l, 0, 0, 2 * n - 1) + 1);
    }
    int mxi = 0;
    rep(i, 1, n) {
        if(res[i] <  res[mxi]) mxi = i;
    }
//    rep(i, 0, n) cout << res[i] << " ";
//    cout << endl;
    cout << res[mxi] + 1 << " " << mxi << '\n';

}