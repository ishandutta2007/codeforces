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
#define int long long
struct segtree {
    int sz = 1;
    vector<int> tree;
    segtree(int n, vector<int> a) {
        sz = 1;
        while (sz < n)
            sz *= 2;
        tree.assign(sz * 2, 0);
        for (int i = 0; i < n; ++i) {
            tree[i + sz] = a[i];
        }
        for (int i = sz - 1; i >= 0; --i) {
            tree[i] = max(tree[i * 2], tree[i * 2 + 1]);
        }
    }
    int get(int l, int r) {
        int res = -1e18;
        l += sz;
        r += sz;
        while (l <= r) {
            if (l % 2 == 1) {
                res = max(res, tree[l]);
                l++;
            }
            if (r % 2 == 0) {
                res = max(res, tree[r]);
                r--;
            }
            l /= 2;r /= 2;
        }
        return res;
    }
};
void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> zpr(n);
    map<int, int> nms;
    for (int i = 0; i < n; ++i) {
        cin >> zpr[i].first >> zpr[i].second;
        nms[zpr[i].first] = 1;
        nms[zpr[i].first - zpr[i].second] = 1;
        nms[zpr[i].first + zpr[i].second] = 1;
    }
    vector<int> realnm;
    int c = 0;
    for (auto &i : nms) {
        i.second = c++;
        realnm.push_back(i.first);
    }
    vector<int> prefmni(c), sufmni(c), pref(c), suf(c), val(c);
    for (int i = 0; i < n; ++i) {
        int v = nms[zpr[i].first];
        int pv = nms[zpr[i].first - zpr[i].second];
        pref[v] += zpr[i].second - zpr[i].first;
        val[v] -= zpr[i].second;
        suf[v] += zpr[i].second + zpr[i].first;
        prefmni[v] -= 1;
        prefmni[pv] += 1;
        pref[pv] -= zpr[i].second - zpr[i].first;
        int nv = nms[zpr[i].first + zpr[i].second];
        sufmni[v] += 1;
        sufmni[nv] -= 1;
        suf[nv] -= zpr[i].second + zpr[i].first;
    }
    for (int i = 0; i + 1 < c; ++i) {
        sufmni[i + 1] += sufmni[i];
        suf[i + 1] += suf[i];
    }
    for (int i = c - 1; i > 0; --i) {
        prefmni[i - 1] += prefmni[i];
        pref[i - 1] += pref[i];
    }
    for (int i = 0; i < c; ++i) {
        val[i] += pref[i] + suf[i] - (sufmni[i] + prefmni[i]) * realnm[i];
        //cerr << realnm[i] << ' ' << val[i] << endl;
    }
    vector<int> valmn = val, valpl = val;
    for (int i = 0; i < c; ++i) {
        valmn[i] -= realnm[i];
        valpl[i] += realnm[i];
    }
    segtree norm(c, val), pls(c, valpl), mns(c, valmn);
    for (int i = 0; i < n; ++i) {
        int v = nms[zpr[i].first];
        int pv = nms[zpr[i].first - zpr[i].second];
        int nv = nms[zpr[i].first + zpr[i].second];
        //cerr << v << ' ' << pv << ' ' << nv << ' ' << pls.get(v, nv) << endl;
        if (max(norm.get(0, pv), norm.get(nv, c - 1)) > m) {
            cout << "0";
        } else if (mns.get(pv, v) - (zpr[i].second - zpr[i].first) > m) {
            cout << "0";
        } else if (pls.get(v, nv) - (zpr[i].second + zpr[i].first) > m) {
            cout << "0";
        } else {
            cout << "1";
        }
    }
    cout << '\n';
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