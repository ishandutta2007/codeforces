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
struct segtree{
    int sz;
    vector<int> tree;
    void init(int n, vector<int> a) {
        sz = 1;
        while (sz < n)
            sz *= 2;
        tree.assign(sz * 2, {});
        for (int i = 0; i < n; ++i) {
            tree[i + sz] = a[i];
        }
        for (int i = sz - 1; i > 0; --i) {
            tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
        }
    }
    int getmin(int l, int r) {
        int res = 1e17;
        l += sz;
        r += sz;
        while (l <= r) {
            if (l % 2) {
                res = min(res, tree[l]);
                l++;
            }
            if (r % 2 == 0) {
                res = min(res, tree[r]);
                r--;
            }
            l /= 2;
            r /= 2;
        }
        return res;
    }
};
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> prefsum(n + 1), suffsum(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        prefsum[i + 1] = prefsum[i] + a[i];
    }
    for (int i = n - 1; i >= 0; --i) {
        suffsum[i] = a[i] + suffsum[i + 1];
    }
    int sm = prefsum[n];
    vector<int> nextmore(n), prevmore(n);
    for (int i = n-1; i >= 0; --i) {
        nextmore[i] = i + 1;
        while (nextmore[i] != n and a[i] >= a[nextmore[i]]) {
            nextmore[i] = nextmore[nextmore[i]];
        }
    }
    for (int i = 0; i < n; ++i) {
        prevmore[i] = i - 1;
        while (prevmore[i] != -1 and a[i] >= a[prevmore[i]]) {
            prevmore[i] = prevmore[prevmore[i]];
        }
    }
    segtree prsg, sfsg;
    prsg.init(n+1, prefsum);
    sfsg.init(n+1, suffsum);
    for (int i = 0; i < n; ++i) {
        int l = prevmore[i] + 1, r = nextmore[i] - 1;
        int res = sm - prsg.getmin(l, i) - sfsg.getmin(i+1, r+1) - a[i];
        //cout << i << ' ' << res << endl;
        if (res > 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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