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
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> nums(n);
    for (auto & i : nums) cin >> i;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        res += nums[i] * b;
    }
    int sm = res / b;
    vector<int> prefsum(n + 1);
    for (int i = 0; i < n; ++i) {
        prefsum[i + 1] = prefsum[i] + nums[i];
    }
    for (int i = 0; i < n; ++i) {
        res = min(res, (a + b) * nums[i] + b * (sm - prefsum[i + 1] - (n - i - 1) * nums[i]));
    }
    cout << res << '\n';
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