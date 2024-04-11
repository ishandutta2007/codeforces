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
int slv(vector<vector<int>> cnt) {
    vector<pair<int, int>> res;
    if (cnt[0].empty())
        return 0;
    reverse(all(cnt[0]));
    int vl = cnt[0].back();
    res.push_back({vl, 0});
    cnt[0].pop_back();
    reverse(all(cnt[0]));
    for (int i = 1;; i ^= 1) {
        if (cnt[i].empty())
            break;
        res.push_back({cnt[i].back(), i});
        cnt[i].pop_back();
    }
    for (auto i : cnt[0])
        res.push_back({i, 0});
    for (auto i : cnt[1])
        res.push_back({i, 1});
    int val = 0;
    int lst = 2;
    for (auto i : res) {
        if ((lst ^ 1) == i.second) {
            val += 2 * i.first;
        } else {
            val += i.first;
        }
        lst = i.second;
    }
    return val;
}
void solve() {
    int n;
    vector<vector<int>> clr(2);
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        clr[a[i]].push_back(val);
    }
    sort(all(clr[0]));
    sort(all(clr[1]));
    int v1 = slv(clr);
    swap(clr[0], clr[1]);
    cout << max(v1, slv(clr)) << '\n';
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