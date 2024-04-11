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
#define int long long
using namespace std;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    map<int, int> ind;
    vector<int> lft(n), rgt(n);
    int r = n;
    for (int i = n-1; i >= 0; --i) {
        int vl = ind[a[i]];
        if (vl != 0) {
            r = min(r, vl);
        }
        rgt[i] = r;
        ind[a[i]] = i;
    }
    int l = -1;
    ind.clear();
    for (int i = 0; i < n; ++i) {
        int vl = ind[a[i]] - 1;
        if (vl != -1) {
            l = max(l, vl);
        }
        lft[i] = l;
        ind[a[i]] = i + 1;
    }
    vector<pair<int, int>> segs, segs2;
    for (int i = 0; i < m; ++i) {
        cin >> l >> r;
        l--;r--;
        if (rgt[l] <= r) {
            segs.emplace_back(l, r);
        }
    }
    if (segs.empty()) {
        cout << "0\n";return;
    }
    sort(all(segs));
    for (auto [l, r] : segs) {
        while (!segs2.empty() and segs2.back().first == l)
            segs2.pop_back();
        if (segs2.empty() or segs2.back().second < r)
            segs2.push_back({l, r});
    }
    segs = segs2;
    multiset<int> mt;
    int ans = n;
    for (auto [l, r] : segs) {
        mt.insert(lft[r]);
    }
    r = segs[0].second;
    mt.erase(mt.find(lft[r]));
    int extra = 0;
    map<int, int> nums;
    for (int i = segs[0].first; i <= segs[0].second; ++i) {
        nums[a[i]]++;
        if (nums[a[i]] == 2)
            extra++;
    }
    int indik = 0;
    r = segs[0].first;
    for (l = segs[0].first; l <= rgt[segs[0].first]; ++l) {
        while (extra != 0) {
            nums[a[r]]--;
            if (nums[a[r]] == 1)
                extra--;
            r++;
        }
        while (indik + 1 != segs.size() and segs[indik + 1].first == l) {
            for (int i = segs[indik].first; i < segs[indik+1].first; ++i) {
                nums[a[i]]--;
                if (nums[a[i]] == 1)
                    extra--;
            }
            for (int i = segs[indik].second + 1; i <= segs[indik+1].second; ++i) {
                nums[a[i]]++;
                if (nums[a[i]] == 2)
                    extra++;
            }
            indik++;
            mt.erase(mt.find(lft[segs[indik].second]));
        }
        while (extra != 0) {
            nums[a[r]]--;
            if (nums[a[r]] == 1)
                extra--;
            r++;
        }
        if (mt.empty())
            ans = min(ans, r - l);
        else {
            ans = min(ans, max(r, 1 + (*mt.rbegin())) - l);
        }
        nums[a[l]]++;
        if (nums[a[l]] == 2)
            extra++;
    }
    cout << ans << '\n';
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