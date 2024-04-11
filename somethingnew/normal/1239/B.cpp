#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include "bitset"
#include "iomanip"
#include <random>
#include "map"
typedef double ld;
typedef long long ll;
#define int long long
#define all(x) x.begin(), x.end()
using namespace std;
pair<int, pair<int, int>> sl0(vector<int> nums) {
    int n = nums.size();
    int v = -1;
    int ck = 0;
    for (int i = 0; i < n; ++i) {
        if (nums[i] == 0) {
            v = i;
            ck++;
        }
    }
    vector<int> nums2;
    for (int i = v; i < n; ++i) {
        nums2.push_back(nums[i]);
    }
    for (int i = 0; i < v; ++i) {
        nums2.push_back(nums[i]);
    }
    int l = -1;
    int cnt = 0;
    pair<int, pair<int, int>> ans = {ck, {0, 0}};
    for (int i = 0; i < n; ++i) {
        //cerr << nums2[i] << ' ';
        if (nums2[i] == 0) {
            l = -1;
            cnt = 0;
        }
        if (nums2[i] == 2 and l != -1) {
            cnt++;
        }
        if (nums2[i] == 1) {
            if (l == -1)
                l = i;
            else {
                if (ans.first < ck + cnt) {
                    ans = {ck + cnt, {(l + v) % n, (i - 1 + v) % n}};
                }
                cnt = 0;
                l = i;
            }
        }
    }
    //cerr << ans.first << ' ' << ans.second.first << ' ' << ans.second.second;
    return ans;
}
pair<int, pair<int, int>> sl1(vector<int> nums) {
    int n = nums.size();
    int ck = 0;
    for (int i = 0; i < n; ++i) {
        nums[i]--;
        if (nums[i] == 0) {
            ck++;
        }
    }
    int l = -1;
    int cnt = 0;
    pair<int, pair<int, int>> ans = {-1, {0, 0}};
    for (int i = 0; i < 2 * n; ++i) {
        //cerr << nums[i % n] << ' ';
        if (nums[i % n] == 0) {
            cnt++;
            if (l == -1)
                l = i % n;
            if (ans.first < cnt) {
                //cout << l << ' ' << i << ' ' << cnt << endl;
                ans = {cnt, {(l + n - 1) % n, i % n}};
            }
        }
        if (nums[i % n] == -1) {
            l = -1;
            cnt = 0;
        }
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> nums(n + 1);
    int v = 0;
    int k = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(')
            nums[i + 1] = nums[i] + 1;
        else
            nums[i + 1] = nums[i] - 1;
        k = min(nums[i + 1], k);
        //cout << nums[i + 1] << ' ';
    }
    for (auto &i : nums) {
        i -= k;
        //cout << i << ' ';
    }
    if (nums[0] != nums[n]) {
        cout << "0\n1 1";
        return 0;
    }
    nums.pop_back();
    auto ans = max(sl1(nums), sl0(nums));
    cout << ans.first << '\n' << ans.second.first + 1 << ' ' << ans.second.second + 1;
}