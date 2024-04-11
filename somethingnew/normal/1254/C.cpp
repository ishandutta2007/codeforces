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
int zpr(int t, int i, int j, int k) {
    cout << t << ' ' << i << ' ' << j << ' ' << k << endl;
    int res;
    cin >> res;
    if (t == 2)
        res = -res;
    return res;
}
vector<int> solve(int a, int b, vector<int> &nums) {
    if (nums.empty())
        return {b};
    vector<pair<int, int>> numsanssize(nums.size());
    for (int i = 0; i < nums.size(); ++i) {
        numsanssize[i] = {zpr(1, a, b, nums[i]), nums[i]};
    }
    sort(all(numsanssize));
    reverse(all(numsanssize));
    vector<pair<int, int>> pls, minus;
    for (int i = 1; i < nums.size(); ++i) {
        int r = zpr(2, b, numsanssize[0].second, numsanssize[i].second);
        if (r > 0)
            pls.push_back(numsanssize[i]);
        else
            minus.push_back(numsanssize[i]);
    }
    reverse(all(pls));
    vector<int> res = {b};
    for (auto [i, ii] : pls)
        res.push_back(ii);
    res.push_back(numsanssize[0].second);
    for (auto [i, ii] : minus)
        res.push_back(ii);
    return res;
}
signed main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> pls, minus;
    for (int i = 3; i <= n; ++i) {
        int r = zpr(2, 1, 2, i);
        if (r > 0)
            pls.push_back(i);
        else
            minus.push_back(i);
    }
    vector<int> l1 = solve(1, 2, minus), l2 = solve(2, 1, pls);
    vector<int> ans;
    cout << "0 ";
    for (auto i : l1)
        ans.push_back(i);
    for (auto i : l2)
        ans.push_back(i);
    for (int i = 0; i < n; ++i) {
        if (ans[i] == 1) {
            for (int j = 0; j < n; ++j) {
                cout << ans[(i + j) % n] << ' ';
            }
            return 0;
        }
    }

}