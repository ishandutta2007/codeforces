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
#define lson(x) 2*x+1
#define rson(x) 2*x+2
const int N = (int)1e5 + 50, K = 21, INF = (int)1e9;

#define ls(x) x * 2 + 1
#define rs(x) x * 2 + 2

struct node {
    pii mxsuf, mxpre;
    pii mnsuf, mnpre;
    int sum;
    pair<int, pii> mxres, mnres;
    int mul;

    void set(int val, int id) {
        mxsuf = mxpre = mnsuf = mnpre = {val, id};
        sum = val;
        mxres = mnres = {val, {id, id}};
    }

    void flip() {
        swap(mxsuf, mnsuf);
        mxsuf.first = -mxsuf.first;
        mnsuf.first = -mnsuf.first;
        swap(mxpre, mnpre);
        mxpre.first = -mxpre.first;
        mnpre.first = -mnpre.first;

        sum = -sum;
        swap(mxres, mnres);
        mxres.first = -mxres.first;
        mnres.first = -mnres.first;

        mul *= -1;
    }

    void merge(node &ls, node &rs) {
        mxsuf = max(pii{rs.sum + ls.mxsuf.first, ls.mxsuf.second}, rs.mxsuf);
        mnsuf = min(pii{rs.sum + ls.mnsuf.first, ls.mnsuf.second}, rs.mnsuf);
        mxpre = max(pii{ls.sum + rs.mxpre.first, rs.mxpre.second}, ls.mxpre);
        mnpre = min(pii{ls.sum + rs.mnpre.first, rs.mnpre.second}, ls.mnpre);

        sum = ls.sum + rs.sum;
        mxres = max(max(ls.mxres, rs.mxres), {ls.mxsuf.first + rs.mxpre.first, pii{ls.mxsuf.second, rs.mxpre.second}});
        mnres = min(min(ls.mnres, rs.mnres), {ls.mnsuf.first + rs.mnpre.first, pii{ls.mnsuf.second, rs.mnpre.second}});
    }
};

int a[N];

struct Tree {
    node dat[4 * N];

    void push_down(int x, int l, int r) {
        if(dat[x].mul == -1) {
            if(l < r) {
                dat[ls(x)].flip();
                dat[rs(x)].flip();
            }
            dat[x].mul = 1;
        }
    }

    void init(int x, int l, int r) {
        if(l == r) {
            dat[x].set(a[l], l);
            dat[x].mul = 1;
            return ;
        }
        int mid = (l + r) / 2;
        init(ls(x), l, mid);
        init(rs(x), mid + 1, r);
        dat[x].mul = 1;
        dat[x].merge(dat[ls(x)], dat[rs(x)]);
    }

    node query(int a, int b, int x, int l, int r) {
        int mid = (l + r) / 2;
        push_down(x, l, r);

        if(l >= a && r <= b) return dat[x];

        if(b <= mid) return query(a, b, ls(x), l, mid);
        if(a >= mid + 1) return query(a, b, rs(x), mid+1, r);

        node LHS = query(a, b, ls(x), l, mid);
        node RHS = query(a, b, rs(x), mid+1, r);
        node res;
        res.merge(LHS, RHS);
        return res;
    }


    void update(int pos, int x, int l, int r, int v) {
        int mid = (l + r) / 2;

        push_down(x, l, r);

        if(l == r) {
            dat[x].set(v, l);
            return ;
        }

        if(pos <= mid) update(pos, ls(x), l, mid, v);
        else update(pos, rs(x), mid + 1, r, v);

        dat[x].merge(dat[ls(x)], dat[rs(x)]);
    }

    void flip_range(int a, int b, int x, int l, int r) {
        int mid = (l + r) / 2;
        if (r < a || l > b) return;

        push_down(x, l, r);

        if (l >= a && r <= b) {
            dat[x].flip();
            return;
        }

        flip_range(a, b, ls(x), l, mid);
        flip_range(a, b, rs(x), mid + 1, r);

        dat[x].merge(dat[ls(x)], dat[rs(x)]);
    }
} tree;

int n;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 0, n) cin >> a[i];
    tree.init(0, 0, n - 1);
    int q;
    cin >> q;
    while(q--) {
        int tp; cin >> tp;
        if(tp == 0) {
            int i, val; cin >> i >> val; i--;
            tree.update(i, 0, 0, n - 1, val);
        } else {
            int l, r, k; cin >> l >> r >> k; l--, r--;
            int res = 0, sum = 0;
            vector<pii> ud;
            rep(j, 0, k) {
                auto qr = tree.query(l, r, 0, 0, n - 1);
                sum += qr.mxres.first;
                res = max(res, sum);
                auto p = qr.mxres.second;
//                cout << p.first << " " << p.second << endl;
                if(j == k - 1) break;
                ud.push_back(p);
                tree.flip_range(p.first, p.second, 0, 0, n - 1);
            }
            cout << res << '\n';
            for (auto &p : ud) tree.flip_range(p.first, p.second, 0, 0, n - 1);
        }
    }
}