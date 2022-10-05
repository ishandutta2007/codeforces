#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#define all(x) (x).begin(), (x).end()
#define int long long
using namespace std;
struct segtree{
    int sz;
    vector<int> tree;
    void upd(int v) {
        tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }
    segtree(int n, vector<int> tr) {
        sz = 1;
        while (sz < n)
            sz *= 2;
        tree.assign(sz * 2, 0);
        for (int i = 0; i < n; ++i) {
            tree[sz + i] = tr[i];
        }
        for (int i = sz - 1; i > 0; --i) {
            upd(i);
        }
    }
    int get(int l, int r) {
        l += sz;
        r += sz;
        int res = 0;
        while (l < r) {
            if (l & 1) {
                res += tree[l];
                l++;
            }
            if (r % 2 == 0) {
                res += tree[r];
                r--;
            }
            r /= 2;
            l /= 2;
        }
        if (l == r)
            res += tree[r];
        return res;
    }
};
struct segtreemax{
    int sz;
    vector<int> tree;
    void upd(int v) {
        tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
    }
    segtreemax(int n, vector<int> tr) {
        sz = 1;
        while (sz < n)
            sz *= 2;
        tree.assign(sz * 2, 0);
        for (int i = 0; i < n; ++i) {
            tree[sz + i] = tr[i];
        }
        for (int i = sz - 1; i > 0; --i) {
            upd(i);
        }
    }
    int get(int l, int r) {
        l += sz;
        r += sz;
        int res = -1e18;
        while (l <= r) {
            if (l & 1) {
                res = max(tree[l], res);
                l++;
            }
            if (r % 2 == 0) {
                res = max(res, tree[r]);
                r--;
            }
            r /= 2;
            l /= 2;
        }
        return res;
    }
};
struct segtreemin{
    int sz;
    vector<int> tree;
    void upd(int v) {
        tree[v] = min(tree[v * 2], tree[v * 2 + 1]);
    }
    segtreemin(int n, vector<int> tr) {
        sz = 1;
        while (sz < n)
            sz *= 2;
        tree.assign(sz * 2, 0);
        for (int i = 0; i < n; ++i) {
            tree[sz + i] = tr[i];
        }
        for (int i = sz - 1; i > 0; --i) {
            upd(i);
        }
    }
    int get(int l, int r) {
        l += sz;
        r += sz;
        int res = 1e18;
        while (l <= r) {
            if (l & 1) {
                res = min(tree[l], res);
                l++;
            }
            if (r % 2 == 0) {
                res = min(res, tree[r]);
                r--;
            }
            r /= 2;
            l /= 2;
        }
        return res;
    }
};
void solve(){
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        int b;
        cin >> b;
        a[i] = b - a[i];
    }
    vector<int> prefsum(n + 1);
    for (int i = 0; i < n; ++i) {
        prefsum[i + 1] = prefsum[i] + a[i];
    }
    segtreemin sgmin(n + 1, prefsum);
    segtreemax sgmax(n + 1, prefsum);
    while (q--) {
        int l, r;
        cin >> l >> r;
        //cout << prefsum[l - 1] << endl;
        if (sgmax.get(l, r) - prefsum[l-1] < 0 or prefsum[r] != prefsum[l - 1]) {
            cout << "-1\n";
        } else {
            cout << sgmax.get(l, r) - prefsum[l-1] << '\n';
        }
    }
}
signed main() {
    ios_base::sync_with_stdio(0);
    int n = 1;
    //cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}
/*
0 2 0 0 2
2 0 1 1 0
 */