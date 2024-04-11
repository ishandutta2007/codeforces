//        
//   @roadfromroi 
//        
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
struct dsu{
    vector<int> p;
    vector<int> l, r;
    void init(vector<pair<int, int>> segs) {
        int n = segs.size();
        p.assign(n, {});
        l.assign(n, {});
        r.assign(n, {});
        for (int i = 0; i < n; ++i) {
            l[i] = segs[i].first;
            r[i] = segs[i].second;
            p[i] = i;
        }
    }
    int getv(int v) {
        if (p[v] == v)
            return v;
        return p[v] = getv(p[v]);
    }
    void mrg(int a, int b) {
        a = getv(a);
        b = getv(b);
        if (a != b) {
            p[a] = b;
            l[b] = min(l[a], l[b]);
            r[b] = max(r[a], r[b]);
        }
    }
    vector<pair<int, int>> getallex() {
        vector<pair<int, int>> a;
        for (int i = 0; i < p.size(); ++i) {
            if (p[i] == i)
                a.push_back({l[i], r[i]});
        }
        return a;
    }
};
struct dsu2{
    vector<int> p;
    void init(int n) {
        p.assign(n, {});
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
    }
    int getv(int v) {
        if (p[v] == v)
            return v;
        return p[v] = getv(p[v]);
    }
    void mrg(int a, int b) {
        a = getv(a);
        b = getv(b);
        if (a != b) {
            p[a] = b;
        }
    }
    int getallex() {
        int cnt = 0;
        for (int i = 0; i < p.size(); ++i) {
            if (p[i] == i)
                cnt++;
        }
        return cnt;
    }
};
struct segtree{
    int sz;
    vector<vector<int>> tree;
    vector<int> seen;
    dsu ds;
    void init(int n, vector<pair<int, int>> a) {
        sz = 1;
        ds.init(a);
        while (sz < n)
            sz *= 2;
        tree.assign(sz * 2, {});
        seen.assign(sz * 2, {});
    }
    void addseg(int l, int r, int x) {
        l += sz;
        r += sz;
        while (l <= r) {
            if (l % 2) {
                tree[l].push_back(x);
                l++;
            }
            if (r % 2 == 0) {
                tree[r].push_back(x);
                r--;
            }
            l /= 2;
            r /= 2;
        }
    }
    int getind(int v) {
        v += sz;
        while (v != 0) {
            if (!tree[v].empty())
                return tree[v][0];
            v /= 2;
        }
        return -1;
    }
    void upd(int v) {
        int tg = getind(v);
        if (tg == -1)
            return;
        v += sz;
        while (v != 0) {
            if (seen[v] == 0) {
                seen[v] = 1;
                for (int i = 0; i < tree[v].size(); ++i) {
                    //cout << tree[v][0] << ' ' << tree[v][i] << endl;
                    ds.mrg(tg, tree[v][i]);
                }
            } else {
                if (!tree[v].empty()) {
                    ds.mrg(tg, tree[v].back());
                }
            }
            v /= 2;
        }
    }
    vector<pair<int, int>> getall(){
        return ds.getallex();
    }
};

void solve() {
    int n;
    cin >> n;
    map<int, int> crd;
    vector<array<int, 3>> segs(n);
    for (int i = 0; i < n; ++i) {
        cin >> segs[i][2] >> segs[i][0] >> segs[i][1];
        crd[segs[i][0]] = 1;
        crd[segs[i][1]] = 1;
    }
    int vl = 0;
    for (auto &[i, x] : crd) {
        x = vl++;
    }
    vector<array<int, 2>> clr(vl, {-1,-1});
    vector<pair<int, int>> clr0, clr1;
    for (int i = 0; i < n; ++i) {
        segs[i][0] = crd[segs[i][0]];
        segs[i][1] = crd[segs[i][1]];
        if (segs[i][2] == 1)
            clr1.emplace_back(segs[i][0], segs[i][1]);
        else
            clr0.emplace_back(segs[i][0], segs[i][1]);
        clr[segs[i][0]][segs[i][2]] = max(clr[segs[i][0]][segs[i][2]], segs[i][1]);
    }
    for (int i = 0; i < vl; ++i) {
        if (i + 1 != vl) {
            clr[i + 1][0] = max(clr[i + 1][0], clr[i][0]);
            clr[i + 1][1] = max(clr[i + 1][1], clr[i][1]);
        }
        clr[i][0] = (clr[i][0] >= i);
        clr[i][1] = (clr[i][1] >= i);
    }
    segtree sg1, sg0;
    sg1.init(vl, clr1);
    sg0.init(vl, clr0);
    int ind = 0;
    for (auto [l, r] : clr0) {
        sg0.addseg(l, r, ind);
        ind++;
    }
    ind = 0;
    for (auto [l, r] : clr1) {
        sg1.addseg(l, r, ind);
        //cerr << l << ' ' << r << endl;
        ind++;
    }
    for (int i = 0; i < vl; ++i) {
        if (clr[i][0]) {
            //cerr << i << endl;
            sg1.upd(i);
        }
        if (clr[i][1])
            sg0.upd(i);
    }
    vector<pair<int, int>> a = sg0.getall(), b = sg1.getall();
    dsu2 ds;
    ds.init(a.size() + b.size());
    vector<array<pair<int, int>, 2>> clrs(vl, {make_pair(-1, -1), make_pair(-1, -1)});
    ind = 0;
    for (auto i : a) {
        clrs[i.first][0] = max(make_pair(i.second, ind), clrs[i.first][0]);
        ind++;
    }
    for (auto i : b) {
        clrs[i.first][1] = max(make_pair(i.second, ind), clrs[i.first][1]);
        ind++;
    }

    for (int i = 0; i < vl; ++i) {
        if (i + 1 != vl) {
            clrs[i + 1][0] = max(clrs[i + 1][0], clrs[i][0]);
            clrs[i + 1][1] = max(clrs[i + 1][1], clrs[i][1]);
        }
        if (clrs[i][0].first >= i and clrs[i][1].first >= i) {
            ds.mrg(clrs[i][0].second, clrs[i][1].second);
        }
    }
    cout << ds.getallex() << '\n';
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}