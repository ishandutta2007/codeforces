#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
#define ls(x) x * 2 + 1
#define rs(x) x * 2 + 2
const int N = (int)6e5 + 50, INF = (int)1e9;

struct node {
    pii mx, st;

    void setval(pii p) {
        mx = st = p;
    }

    void merge(node &ls, node &rs) {
        mx = max(ls.mx, rs.mx);
    }
};

node dat[4 * N];

struct Tree {

    void push_down(int x, int l, int r) {
        if(dat[x].st.first != -1) {
            if(l < r) {
                dat[ls(x)].setval(dat[x].st);
                dat[rs(x)].setval(dat[x].st);
            }
            dat[x].st = {-1, -1};
        }
    }

    void init(int x, int l, int r) {
        if(l == r) {
            dat[x] = {{-1, -1}, {-1, -1}};
            return ;
        }
        int mid = (l + r) / 2;
        init(ls(x), l, mid);
        init(rs(x), mid + 1, r);
        dat[x].st = {-1, -1};
        dat[x].merge(dat[ls(x)], dat[rs(x)]);
    }

    pii query(int a, int b, int x, int l, int r) {
        int mid = (l + r) / 2;
        if(r < a || l > b) return {-1, -1};

        push_down(x, l, r);

        if(l >= a && r <= b) return dat[x].mx;

        return max(query(a, b, ls(x), l, mid), query(a, b, rs(x), mid+1, r));
    }

    void update(int a, int b, int x, int l, int r, pii p) {
        int mid = (l + r) / 2;
        if(r < a || l > b) return ;

        push_down(x, l, r);

        if(l >= a && r <= b) {
            dat[x].setval(p);
            return ;
        }

        update(a, b, ls(x), l, mid, p);
        update(a, b, rs(x), mid+1, r, p);
        dat[x].merge(dat[ls(x)], dat[rs(x)]);
    }
} tree;

struct Seg {
    int l, r;
};

int n, m;
vi vs;
vector<Seg> sgs[N / 2];
pii dp[N / 2];
bool vis[N / 2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    rep(j, 0, m) {
        int i, l, r; cin >> i >> l >> r; i--;
        sgs[i].push_back({l, r});
        vs.push_back(l);
        vs.push_back(r + 1);
    }
    sort(all(vs));
    vs.resize(unique(all(vs)) - vs.begin());

    tree.init(0, 0, sz(vs));
    pii mxdp = {-1, -1};
    rep(i, 0, n) {
        dp[i] = {0, -1};
        for(auto &p : sgs[i]) {
            p.l = lower_bound(all(vs), p.l) - vs.begin();
            p.r = (lower_bound(all(vs), p.r + 1) - vs.begin()) - 1;
            dp[i] = max(dp[i], tree.query(p.l, p.r, 0, 0, sz(vs)));
        }
        dp[i].first ++;
        mxdp = max(mxdp, {dp[i].first, i});
        for(auto &p : sgs[i]) {
            tree.update(p.l, p.r, 0, 0, sz(vs), {dp[i].first, i});
        }
    }
//    cout << "has " << mxdp.first << "\n";
    cout << n - mxdp.first << "\n";
    int cur = mxdp.second;
    while(cur != -1) {
//        cout << cur << endl;
        vis[cur] = true;
        cur = dp[cur].second;
    }
    rep(i, 0, n) {
        if(!vis[i]) cout << i + 1 << " ";
    }
    cout << endl;



}