#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int mod = (int)1e9 + 7, N = (int)1e5 + 50;


int n, m;
ll seed, vmax;
ll a[N];

#define ls(x) x * 2 + 1
#define rs(x) x * 2 + 2

struct node {
    ll add, st;
    vector<pll> vs;

    void add_val(ll x) {
        for(pll &p : vs) p.first += x;
        if(st) st += x;
        else add += x;
    }

    void set_val(ll x, int len) {
        vs = {pll{x, len}};
        add = 0;
        st = x;
    }

    void merge(node &L, node &R) {
        vs.clear();
        int r = 0;
        for(int i = 0; i < sz(L.vs); i++) {
            while(r < sz(R.vs) && R.vs[r].first <= L.vs[i].first) vs.push_back(R.vs[r++]);
            if(!vs.empty() && vs.back().first == L.vs[i].first) vs.back().second += L.vs[i].second;
            else vs.push_back(L.vs[i]);
        }
        while(r < sz(R.vs)) vs.push_back(R.vs[r++]);

    }
};

struct Tree {
    node dat[4 * N];

    void push_down(int x, int l, int r) {
//        assert(dat[x].add == 0 || dat[x].st == 0);
        if(dat[x].add) {
            if(l < r) {
                dat[ls(x)].add_val(dat[x].add);
                dat[rs(x)].add_val(dat[x].add);
            }
            dat[x].add = 0;
        }
        if(dat[x].st) {
            if(l < r) {
                int mid = (l + r) / 2;
                dat[ls(x)].set_val(dat[x].st, mid - l + 1);
                dat[rs(x)].set_val(dat[x].st, r - mid);
            }
            dat[x].st = 0;
        }
    }

    void init(int x, int l, int r) {
        if(l == r) {
            dat[x].vs = {{a[l], 1}};
            dat[x].st = 0;
            dat[x].add = 0;
            return ;
        }
        int mid = (l + r) / 2;
        init(ls(x), l, mid);
        init(rs(x), mid + 1, r);
        dat[x].add = dat[x].st = 0;
        dat[x].merge(dat[ls(x)], dat[rs(x)]);
    }

    node query(int a, int b, int x, int l, int r) {
        int mid = (l + r) / 2;
        push_down(x, l, r);

        if(l >= a && r <= b) return dat[x];

        if(a > mid) return query(a, b, rs(x), mid+1, r);
        if(b < mid + 1) return query(a, b, ls(x), l, mid);
        node LHS = query(a, b, ls(x), l, mid);
        node RHS = query(a, b, rs(x), mid+1, r);
        node res;
        res.merge(LHS, RHS);
        return res;
    }

    void update(int a, int b, int x, int l, int r, int dx) {
        int mid = (l + r) / 2;
        if(r < a || l > b) return ;

        push_down(x, l, r);

        if(l >= a && r <= b) {
            if(dx > 0) dat[x].add_val(dx);
            else dat[x].set_val(-dx, r - l + 1);
            return ;
        }

        update(a, b, ls(x), l, mid, dx);
        update(a, b, rs(x), mid+1, r, dx);
        dat[x].merge(dat[ls(x)], dat[rs(x)]);
    }

} tree;


ll rnd() {
    ll ret = seed;
    seed = (seed * 7 + 13) % mod;
    return ret;
}

ll fp(ll x, ll k, ll m) {
    ll res = 1;
    for( ; k; k >>= 1) {
        if(k & 1) res = (res * x) % m;
        x = (x * x) % m;
    }
    return res;
}

int main() {
    cin >> n >> m >> seed >> vmax;

    rep(i, 0, n) a[i] = (rnd() % vmax) + 1;

    tree.init(0, 0, n - 1);
    rep(i, 0, m) {
        int op = (rnd() % 4) + 1;
        int l = (rnd() % n) + 1;
        int r = (rnd() % n) + 1;
        int x, y;

        if (l > r) swap(l, r);

        if (op == 3) x = (rnd() % (r - l + 1)) + 1;
        else x = (rnd() % vmax) + 1;

        if (op == 4) y = (rnd() % vmax) + 1;
        l--, r--;

        if (op == 1) {
            tree.update(l, r, 0, 0, n - 1, x);
        } else if (op == 2) {
            tree.update(l, r, 0, 0, n - 1, -x);
        } else {
            node qr = tree.query(l, r, 0, 0, n - 1);
            if (op == 3) {

                int c = 0;
                ll res = -1;
                for (auto &p : qr.vs) {
                    c += p.second;
                    if (c >= x) {
                        res = p.first;
                        break;
                    }
                }
                cout << res << "\n";
            } else {
                ll s = 0;
                for (auto &p : qr.vs) {
                    s += fp(p.first % y, x, y) * p.second % y;
                    if (s >= y) s -= y;
                }
                cout << s << '\n';
            }
        }
    }
}