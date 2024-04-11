#include <iostream>
#include "cmath"
#include "string"
#include "vector"
#include "set"
#include "algorithm"
#include "map"
#include "queue"
#include "array"
#include "numeric"
#include "iomanip"
using namespace std;
#define all(x) x.begin(), x.end()
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<pair<int, int>> crd(n + 1, {-1, -1});
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (crd[a[i]].first == -1)
            crd[a[i]].first = i;
        crd[a[i]].second = i;
    }
    vector<int> add(n + 1);
    vector<int> ex(n);
    vector<pair<int, int>> segs;
    for (int i = 1; i <= n; ++i) {
        if (crd[i].first != crd[i].second) {
            add[crd[i].first + 1]++;
            add[crd[i].second]--;
            segs.push_back({crd[i].first, crd[i].second});
        }
    }
    int val = 0;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        val += add[i];
        ex[i] = (val > 0);
        res += ex[i];
    }
    for (auto [l, r] : segs) {
        res += ex[l] == 0;
        res += ex[r] == 0;
    }
    sort(all(segs));
    vector<pair<int, int>> segs2;
    int cmp = 0;
    for (auto [l, r] : segs) {
        if (segs2.empty() or segs2.back().second < l) {
            cmp++;
            segs2.push_back({l, r});
            continue;
        }
        if (segs2.back().first <= l and r <= segs2.back().second)
            continue;
        while (segs2.size() >= 2 and segs2[segs2.size() - 2].second >= l)
            segs2.pop_back();
        segs2.push_back({l, r});
    }
    //cout << res << ' ' << segs2.size() << ' ' << cmp << '\n';
    cout << res - (int)segs2.size() - cmp << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}