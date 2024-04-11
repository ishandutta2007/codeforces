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
pair<int, int> getlr(vector<pair<int, int>> &a, int l, int r) {
    int cnt = lower_bound(all(a), pair<int, int>{r+1, 0}) - lower_bound(all(a), pair<int, int>{l, 0});
    if (cnt != 1)
        return {cnt, 0};
    return {1, lower_bound(all(a), pair<int, int>{l, 0})->second};
}
void solve() {
    vector<map<int, vector<pair<int, int>>>> mp(31);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        int temp = 0;
        for (int j = 29; j >= 0; --j) {
            temp += (1 << j) & x;
            mp[j][temp].push_back({i, x});
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        l--;r--;
        int temp = 0;
        vector<int> myel;
        for (int j = 29; j >= 0; --j) {
            pair<int, int> zer = getlr(mp[j][temp], l, r);
            int cnt = zer.first;
           // cerr << cnt << endl;
            for (auto tt : myel) {
                if (tt == -1)
                    continue;
                if ((tt & (1 << j)) == 0)
                    cnt++;
            }
            if (cnt < 2) {
                if (zer.first == 1) {
                    myel.push_back(zer.second);
                }
                temp += (1 << j);
            } else {
                for (auto &tt : myel) {
                    if (tt == -1)
                        continue;
                    if ((tt & (1 << j)))
                        tt = -1;
                }
            }
        }
        cout << temp << '\n';
    }
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