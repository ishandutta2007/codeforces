#include <iostream>
#include "cmath"
#include "string"
#include "vector"
#include "set"
#include "algorithm"
#include "map"
#include "queue"
#include "numeric"
#include "deque"
#define int long long
using namespace std;
struct segtree{
    int sz;
    vector<int> tree;
    void make(int n) {
        sz = 1;
        while (sz < n) {
            sz *= 2;
        }
        tree.assign(sz * 2, 0);
    }
    void add(int l, int r) {
        l += sz;
        r += sz;
        while (l < r) {
            if (l % 2 == 1) {
                tree[l] += 1;
                l++;
            }
            if (r % 2 == 0) {
                tree[r] += 1;
                r--;
            }
            l /= 2;
            r /= 2;
        }
        if (l == r)
            tree[l]++;
    }
    int get(int v) {
        v += sz;
        int res = 0;
        while (v) {
            res += tree[v];
            v /= 2;
        }
        return res;
    }
};
void solve() {
    int n;
    string s, t;
    cin >> n >> s >> t;
    segtree sg;
    sg.make(n);
    vector<vector<int>> pos(26);
    for (int i = 0; i < n; ++i) {
        pos[s[i] - 'a'].push_back(i);
    }
    for (int i = 0; i < 26; ++i) {
        reverse(pos[i].begin(), pos[i].end());
    }
    int res = 1e14;
    int rnow = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < t[i] - 'a'; ++j) {
            if (!pos[j].empty()) {
                res = min(res, rnow + (pos[j].back() + sg.get(pos[j].back()) - i));
            }
        }
        if (pos[t[i] - 'a'].empty())
            break;
        rnow = rnow + (pos[t[i] - 'a'].back() + sg.get(pos[t[i] - 'a'].back()) - i);
        sg.add(0, pos[t[i] - 'a'].back());
        pos[t[i] - 'a'].pop_back();
    }
    if (res < 1e13) {
        cout << res << '\n';
    } else {
        cout << "-1\n";
    }
}
signed main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}