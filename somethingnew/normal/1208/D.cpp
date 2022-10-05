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
    vector<int> tree;
    int sz;
    void make(int n, vector<int> a) {
        sz = 1;
        while (sz < n)
            sz *= 2;
        tree.assign(sz * 2, 0);
        for (int i = 0; i < n; ++i) {
            tree[sz + i] = a[i];
        }
        for (int i = sz - 1; i > 0; --i) {
            tree[i] = tree[i * 2] + tree[i * 2 + 1];
        }
    }
    void upd(int v) {
        v += sz;
        tree[v] = 0;
        while (v != 1) {
            v /= 2;
            tree[v] = tree[v * 2] + tree[v * 2 + 1];
        }
    }
    int getlr(int l, int r) {
        l += sz;r += sz;
        int res = 0;
        while (l < r) {
            if (l % 2 == 1){
                res += tree[l];
                l++;
            }
            if (r % 2 == 0) {
                res += tree[r];
                r--;
            }
            l /= 2;
            r /= 2;
        }
        if (l == r)
            res += tree[l];
        return res;
    }
};
signed main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> nums(n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        nums[i] = i + 1;
    }
    segtree sg;
    sg.make(n, nums);
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; --i) {
        int l = -1, r = n;
        while (r - l > 1) {
            int m = l + r >> 1;
            if (sg.getlr(0, m) <= a[i]) {
                l = m;
            } else {
                r = m;
            }
        }
        ans[i] = r + 1;
        sg.upd(r);
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
}