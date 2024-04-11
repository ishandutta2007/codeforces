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
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> nums(m);
    for (int i = 0; i < m; ++i) {
        cin >> nums[i];
    }
    sort(all(nums));
    nums.push_back(nums[0] + n);
    vector<int> segs;
    for (int i = 0; i < m; ++i) {
        segs.push_back(nums[i + 1] - nums[i] - 1);

    }
    sort(all(segs));
    reverse(all(segs));
    int res = 0;
    int k = 0;
    for (auto i : segs) {
        i -= k * 2;
        if (i > 2) {
            res += i - 1;
            k += 2;
        } else if (i > 0) {
            res += 1;
            k++;
        }
    }
    cout << n - res << '\n';
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