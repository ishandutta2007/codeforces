#include <iostream>
#include "vector"
#include "algorithm"
#include "numeric"
#include "climits"
#include "iomanip"
#include "bitset"
#include "cmath"
#include "map"
#include "deque"
#include "array"
#include "set"
#define all(x) x.begin(), x.end()
using namespace std;
struct segtree{
    int sz;
    vector<int> tree;
    void make(int n) {
        sz = 1;
        while (sz < n)
            sz *= 2;
        tree.assign(sz * 2, {});
    }
    void ch(int v) {
        v += sz;
        while (v) {
            tree[v] += 1;
            v /= 2;
        }
    }
    int get(int l, int r) {
        l += sz;r += sz;
        int res = r - l + 1;
        while (l <= r) {
            if (l % 2 == 1) {
                res -= tree[l];
                l++;
            }
            if (r % 2 == 0) {
                res -= tree[r];
                r--;
            }
            l /= 2;r /= 2;
        }
        return res;
    }
};
vector<pair<int, int>> ans;
struct sgdsu{
    vector<int> ex;
    segtree sg;
    int n;
    void make(int N) {
        n = N;
        ex.assign(n+1, {});
        sg.make(n);
        for (int i = 0; i < n+1; ++i) {
            ex[i] = i;
        }
    }
    int getv(int v) {
        if (ex[v] == v)
            return v;
        return ex[v] = getv(ex[v]);
    }
    void add(int l, int r, int t = 0, int dop = 0) {
        l = getv(l);
        while (l <= r) {
            sg.ch(l);
            if (t) {
                ans[l] = {0, dop};
               // cerr << l << ' ' << ans[l].second << endl;

            }
            ex[l] = l + 1;
            l = getv(l);
        }
    }
    int get(int l, int r) {
        return sg.get(l, r);
    }
};
void slv(int n, vector<array<int, 3>> sob0, vector<array<int, 3>> sob1) {
    int q0 = sob0.size(), q1 = sob1.size();
    vector<pair<int, int>> binp(q1, {-1, q0+1});
    for (int i = 0; i < 18; ++i) {
        vector<vector<array<int, 3>>> M(q0 + 1);
        for (int j = 0; j < q1; ++j) {
            int m = binp[j].first + binp[j].second >> 1;
            if (m == -1)
                continue;
            M[m].push_back({j, sob1[j][0], sob1[j][1]});
        }
        sgdsu sg;
        sg.make(n);
        for (auto [ind, l, r] : M[0]) {
            if (sg.get(l, r) == 1) {
                binp[ind].second = 0;
            } else
                binp[ind].first = 0;
        }
        for (int j = 0; j < q0; ++j) {
            sg.add(sob0[j][0], sob0[j][1], i == 0, sob0[j][2]);
            for (auto [ind, l, r] : M[j+1]) {
                if (sg.get(l, r) == 1) {
                    binp[ind].second = j+1;
                } else
                    binp[ind].first = j+1;
            }
        }
    }
    vector<vector<array<int, 3>>> M(q0 + 1);
    for (int j = 0; j < q1; ++j) {
        if (binp[j].second < M.size())
            M[binp[j].second].push_back({sob1[j][2], sob1[j][0], sob1[j][1]});
    }
    sgdsu sg;
    sg.make(n);
    for (auto [tme, l, r] : M[0]) {
        int rr = r;
        int ll = l-1;
        while (ll + 1 < rr) {
            int mm = ll + rr >> 1;
            if (sg.get(l, mm) == 1) {
                rr = mm;
            } else
                ll = mm;
        }
        if (ans[rr].second < tme)
            continue;
        ans[rr] = {1, tme};
    }
    for (int j = 0; j < q0; ++j) {
        sg.add(sob0[j][0], sob0[j][1]);
        for (auto [tme, l, r] : M[j+1]) {
            int rr = r;
            int ll = l-1;
            while (ll + 1 < rr) {
                int mm = ll + rr >> 1;
                if (sg.get(l, mm) == 1) {
                    rr = mm;
                } else
                    ll = mm;
            }
            if (ans[rr].second < max(tme, sob0[j][2]))
                continue;
            ans[rr] = {1, max(tme, sob0[j][2])};
        }
    }
}
void solve() {
    int n, q;
    cin >> n >> q;
    ans.assign(n, {-1, q + 3});
    vector<array<int, 3>> sob0, sob1;
    vector<pair<int, int>> sob2;
    for (int i = 0; i < q; ++i) {
        int t;
        cin >> t;
        if (t == 0) {
            int l, r, x;
            cin >> l >> r >> x;
            l--;r--;
            if (x == 0)
                sob0.push_back({l, r, i});
            else
                sob1.push_back({l, r, i});
        } else {
            int x;
            cin >> x;
            x--;
            sob2.emplace_back(x, i);
        }
    }
    slv(n, sob0, sob1);
    //cout << "AAA" << 4 << ' ' << ans[4].first << ' ' << ans[4].second << endl;
    for (auto [x, i] : sob2) {
       // cout << x << ' ' << ans[x].second << endl;
        if (ans[x].second <= i) {
            if (ans[x].first == 0)
                cout << "NO\n";
            else
                cout << "YES\n";
        } else {
            cout << "N/A\n";
        }
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}