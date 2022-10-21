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
const int N = (int)3e5 + 50, INF = (int)1e9;


#define ls(x) x * 2 + 1
#define rs(x) x * 2 + 2

struct node {
    int mn, cnt, add;

    void add_val(int x) {
        mn += x;
        add += x;
    }

    void merge(node &ls, node &rs) {
        mn = min(ls.mn, rs.mn);
        cnt = (ls.mn == mn ? ls.cnt : 0) + (rs.mn == mn ? rs.cnt : 0);
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

    void init(int x, int l, int r) {
        if(l == r) {
            dat[x] = node{l, 1, 0};
            return ;
        }
        int mid = (l + r) / 2;
        init(ls(x), l, mid);
        init(rs(x), mid + 1, r);
        dat[x].add = 0;
        dat[x].merge(dat[ls(x)], dat[rs(x)]);
    }

    node query(int a, int b, int x = 0, int l = 0, int r = N-1) {
        int mid = (l + r) / 2;
        if(r < a || l > b) return {INF, 1, 0};

        push_down(x, l, r);

        if(l >= a && r <= b) return dat[x];

        node LHS = query(a, b, ls(x), l, mid);
        node RHS = query(a, b, rs(x), mid+1, r);
        node res;
        res.merge(LHS, RHS);
        return res;
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


int n;
int p[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 0, n) {
        int a, b; cin >> a >> b; a--, b--;
        p[a] = b;
    }
    tree.init(0, 0, n - 1);
    vector<pii> Su, Sd;
    Su.push_back({INF, -1});
    Sd.push_back({-INF, -1});
    ll res = 0;
    rep(i, 0, n) {
//        cout << i << endl;
//        cout << Su.back().second + 1 << " " << i << " " << p[i] << endl;
        tree.update(Su.back().second + 1, i, 0, 0, n - 1, p[i]);
        while(Su.back().first < p[i]) {
            int r = Su.back().second;
            int v = Su.back().first;
            Su.pop_back();
            int l = Su.back().second + 1;
//            cout << l << " " << r << " " << p[i] - v << endl;
            tree.update(l, r, 0, 0, n - 1, p[i] - v);
        }
        Su.push_back({p[i], i});
//        cout << Sd.back().second + 1 << " " << i << " " << -p[i] << endl;
        tree.update(Sd.back().second + 1, i, 0, 0, n - 1, -p[i]);
        while(Sd.back().first > p[i]) {
            int r = Sd.back().second;
            int v = Sd.back().first;
            Sd.pop_back();
            int l = Sd.back().second + 1;
//            cout << l << " " << r << " " << p[i] - v << endl;
            tree.update(l, r, 0, 0, n - 1, v - p[i]);
        }
        Sd.push_back({p[i], i});

        auto qr = tree.query(0, i, 0, 0, n - 1);
//        cout <<  qr.mn << " " << qr.cnt << endl;
        if(qr.mn == i) {
            res += qr.cnt;
        }
    }
    cout << res << endl;


}