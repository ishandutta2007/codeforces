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

pii operator + (const pii &p1, const pii &p2) {
    int mn = min(p1.first, p2.first);
    return {mn, (p1.first == mn ? p1.second : 0) + (p2.first == mn ? p2.second : 0)};
}

struct node {
    pii p;
    int add, addtime;
    ll ans;

    void add_val(int x) {
        p.first += x;
        add += x;
    }

    void add_time(int t) {
        addtime += t;
        ans += 1LL * p.second * t;
    }

    void merge(node &ls, node &rs) {
        p = ls.p + rs.p;
        ans = ls.ans + rs.ans;
    }
};

struct Tree {
    node dat[4 * N];

    void push_down(int x, int l, int r) {
        if(l == r) return ;
        if(dat[x].add) {
            dat[ls(x)].add_val(dat[x].add);
            dat[rs(x)].add_val(dat[x].add);
            dat[x].add = 0;
        }
        if(dat[x].addtime) {
            if(dat[ls(x)].p.first== dat[x].p.first) dat[ls(x)].add_time(dat[x].addtime);
            if(dat[rs(x)].p.first == dat[x].p.first) dat[rs(x)].add_time(dat[x].addtime);
            dat[x].addtime = 0;
        }
    }

    void init(int x, int l, int r) {
        if(l == r) {
            dat[x] = node{{l, 1}, 0, 0, 0};
            return ;
        }
        int mid = (l + r) / 2;
        init(ls(x), l, mid);
        init(rs(x), mid + 1, r);
        dat[x].add = 0;
        dat[x].merge(dat[ls(x)], dat[rs(x)]);
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

    ll query(int a, int b, int x = 0, int l = 0, int r = N-1) {
        int mid = (l + r) / 2;
        if(r < a || l > b) return 0;
        push_down(x, l, r);
        if(l >= a && r <= b) return dat[x].ans;

        return query(a, b, ls(x), l, mid) + query(a, b, rs(x), mid+1, r);
    }

} tree;


int n, q;
int p[N];
vector<pii> qrs[N];

ll res[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 0, n) cin >> p[i], p[i]--;
    cin >> q;
    rep(i, 0, q) {
        int l, r; cin >> l >> r; l--, r--;
        qrs[r].push_back({l, i});
    }

    tree.init(0, 0, n - 1);
    vector<pii> Su, Sd;
    Su.push_back({INF, -1});
    Sd.push_back({-INF, -1});
    rep(i, 0, n) {
//        tree.dat[0].add_val(-1);
        tree.update(Su.back().second + 1, i, 0, 0, n - 1, p[i]);
        while(Su.back().first < p[i]) {
            int r = Su.back().second;
            int v = Su.back().first;
            Su.pop_back();
            int l = Su.back().second + 1;
            tree.update(l, r, 0, 0, n - 1, p[i] - v);
        }
        Su.push_back({p[i], i});
        tree.update(Sd.back().second + 1, i, 0, 0, n - 1, -p[i]);
        while(Sd.back().first > p[i]) {
            int r = Sd.back().second;
            int v = Sd.back().first;
            Sd.pop_back();
            int l = Sd.back().second + 1;
            tree.update(l, r, 0, 0, n - 1, v - p[i]);
        }
        Sd.push_back({p[i], i});
        tree.dat[0].add_time(1);
        for (auto pr : qrs[i]) {
            res[pr.second] = tree.query(pr.first, i, 0, 0, n - 1);
        }
    }
    rep(i, 0, q) cout << res[i] << '\n';


}