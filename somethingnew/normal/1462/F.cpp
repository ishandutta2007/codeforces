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
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<pair<int, int>> segs(n);
    vector<int> l(n), r(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
        segs[i] = {l[i], r[i]};
    }
    sort(rall(l));
    sort(all(r));
    map<int, int> lmap, rmap;
    for (int j = 0; j < n; ++j) {
        rmap[r[j]] = j + 1;
    }
    for (int k = 0; k < n; ++k) {
        lmap[l[k]] = k + 1;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int res = n;
        auto k = rmap.lower_bound(segs[i].first);
        if(k != rmap.begin()) {
            k--;
            res -= (*k).second;
        }
        auto t = lmap.upper_bound(segs[i].second);
        if(t != lmap.end())
            res -= (*t).second;
        ans = max(res, ans);
    }
    cout << n - ans << endl;
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}