#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)1e5 + 2;
#define ls(x) x * 2 + 1
#define rs(x) x * 2 + 2

struct BIT2D {
    vector<ll> vals[N], f[N];
    set<pii> umap, amap;

    void addupd(int x, int y) {
        if(x < 0 || y < 0) return ;
        for (int i = x; i < N; i |= i + 1) vals[i].push_back(y);
    }

    void addget(int x, int y) {
        if (x < 0 || y < 0) return;
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1) vals[i].push_back(y);
    }

    void build() {
        for (int i = 0; i < N; i++) {
            sort(vals[i].begin(), vals[i].end());
            vals[i].resize(unique(vals[i].begin(), vals[i].end()) - vals[i].begin());
            f[i].resize(vals[i].size(), 0);
        }
    }

    void upd(int x, int y, int v) {
        if(x < 0 || y < 0) return ;
        for (int i = x; i < N; i |= i + 1) {
            for (int j = lower_bound(vals[i].begin(), vals[i].end(), y) - vals[i].begin();
                 j < (int) f[i].size(); j |= j + 1) {
                f[i][j] += v;
            }
        }
    }

    ll get(int x, int y) {
        if (x < 0 || y < 0) return 0;
        ll res = 0;
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
            for (int j = lower_bound(vals[i].begin(), vals[i].end(), y) - vals[i].begin(); j >= 0;
                 j = (j & (j + 1)) - 1)
                res += f[i][j];
        return res;
    }

    void updrect(int lx, int rx, int ly, int ry, int val, int r) {
//        cout << "adding "<< lx << " " << rx << " " << ly << " " << ry << " "<< val << " " << r<< endl;
        if(lx > rx || ly > ry) return ;
        if(r == 1) {
            upd(rx + 1, ry + 1, val);
            upd(lx, ry + 1, -val);
            upd(rx + 1, ly, -val);
            upd(lx, ly, val);
        } else {
            addupd(rx + 1, ry + 1);
            addupd(lx, ry + 1);
            addupd(rx + 1, ly);
            addupd(lx, ly);
        }
    }

    void updatept(int x, int y, int val, int r) {
        if(r == 1) {
            upd(x, y, val);
        } else {
            addupd(x, y);
        }
    }

    ll querypt(int x, int y, int r) {
//        cout << "getting " << x << " " << y << " " << r << endl;
        if(r) {
            return get(x, y);
        } else {
            addget(x, y);
            return -1;
        }
    }
} Rt;

int n, m;
int a[N], p[N];
set<int> S[N];
struct Qr {
    int tp, a, b;
    void read() {
        cin >> tp >> a >> b;
        a--, b--;
    }
} qr[N];
ll res[N];

int prev(set<int>::iterator it, set<int> &St) {
    return it == St.begin() ? -1 : *(--it);
}

int next(set<int>::iterator it, set<int> &St) {
    it++;
    return it == St.end() ? n :  *it;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i], a[i]--;
    rep(i, 0, m) qr[i].read();

    for(int rd = 0; rd < 2; rd++) {
        if(rd) Rt.build();
        rep(i, 0, n) S[i].clear(), p[i] = a[i];
        rep(i, 0, n) S[p[i]].insert(i);
        rep(i, 0, n) {
            for(auto it = S[i].begin(); it != S[i].end(); it++) {
                int nxt = next(it, S[i]), prv = prev(it, S[i]);
                Rt.updatept(prv, *it, *it - prv, rd);
            }
        }
        rep(i, 0, m) {
//            cout << i << endl;
            int tp, a, b;
            tie(tp, a, b) = {qr[i].tp, qr[i].a, qr[i].b};
            if(tp == 1) {
                int &col = p[a];
                auto it = S[col].find(a);

                int nxt = next(it, S[col]), prv = prev(it, S[col]);
                Rt.updatept(prv, *it, -(*it - prv), rd);
                Rt.updatept(*it, nxt, -(nxt - *it), rd);
                Rt.updatept(prv, nxt, (nxt - prv), rd);

                S[col].erase(it);
                col = b;
                it = S[col].insert(a).first;

                nxt = next(it, S[col]), prv = prev(it, S[col]);

                Rt.updatept(prv, *it, (*it - prv), rd);
                Rt.updatept(*it, nxt, (nxt - *it), rd);
                Rt.updatept(prv, nxt, -(nxt - prv), rd);
            } else {
                res[i] = Rt.querypt(b, b, rd) - Rt.querypt(b, a - 1, rd) - Rt.querypt(a - 1, b, rd) +
                         Rt.querypt(a - 1, a - 1, rd);
            }
        }

    }
    rep(i, 0, m) {
        if(qr[i].tp == 2) cout << res[i] << '\n';
    }

}