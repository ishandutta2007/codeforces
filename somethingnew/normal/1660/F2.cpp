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
#include "queue"
#define all(x) x.begin(), x.end()
using namespace std;
struct segtree{
    int sz;
    int N;
    vector<int> tree;
    void make(int n) {
        N = n / 2;
        sz = 1;
        while (sz < n) sz *= 2;
        tree.assign(sz * 2, {});
    }
    int get(int l, int r) {
        l += sz;r += sz;
        l += N;
        r += N;
        int res = 0;
        while (l <= r) {
            if (l % 2 == 1) {
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
        return res;
    }
    void ch(int v, int x) {
        v += N;
        v += sz;
        while (v) {
            tree[v] += x;
            v /= 2;
        }
    }
};
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<segtree> resulki(3);
    for (int i = 0; i < 3; ++i) {
        resulki[i].make(n * 2 + 2);
    }
    int md = 0, delt = 0;
    resulki[md].ch(delt, 1);
    for (int i = n - 1; i >= 0; --i) {
        md += 1;
        if (s[i] == '-')
            md += 1;
        md %= 3;
        if (s[i] == '+')
            delt++;
        else
            delt--;
        resulki[md].ch(delt, 1);
    }
    long long res = 0;
    for (int i = 0; i < n; ++i) {
        resulki[md].ch(delt, -1);
        res += resulki[md].get(delt, n);
        md += 2;
        if (s[i] == '-')
            md += 2;
        md %= 3;
        if (s[i] == '+')
            delt--;
        else
            delt++;
    }
    cout << res << '\n';
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}
/*

 */