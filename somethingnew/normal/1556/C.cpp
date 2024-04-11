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
#define int long long
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        if (i % 2)
            nums[i] = -nums[i];
    }
    int res = 0;
    for (int l = 0; l < n; l += 2) {
        int cnt = 0;
        int mincnt = 0;
        for (int r = l + 1; r < n; ++r) {
            if ((r - l) % 2) {
                int k1 = -mincnt, k2 = nums[l];
                int r1 = cnt + k1, r2 = cnt + k2;
                r1 = max(1ll, r1);
                r2 = min(-nums[r], r2);
                //cout << l << ' ' << r << ' ' << r1 << ' ' << r2 << endl;
                if (r1 <= r2)
                    res += r2 - r1 + 1;
            }
            cnt += nums[r];
            mincnt = min(mincnt, cnt);
            if (nums[l] + cnt < 0)
                break;
        }
    }
    cout << res << '\n';
}
signed main() {
    ios_base::sync_with_stdio(0);
    int n = 1;
    //cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}