#include "list"
#include <iostream>
#include <utility>
#include <vector>
#include "fstream"
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#include "queue"
#include "complex"
#include "bitset"
#define all(x) (x).begin(), (x).end()

using namespace std;
vector<pair<int, int>> pdel(int x) {
    vector<pair<int, int>> ans;
    for (int i = 2; i * i <= x; ++i) {
        int cnt = 0;
        while (x % i == 0) {
            x /= i;
            cnt++;
        }
        if (cnt != 0)
            ans.push_back({cnt, i});
    }
    if (x != 1)
        ans.push_back({1, x});
    return ans;
}
signed main() {
    // 17:43
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    vector<int> nums(1e5);
    vector<vector<int>> prig(n + 1, vector<int>(24));
    for (int i = 0; i < 24; ++i) {
        prig.back()[i] = n;
    }
    int cnt = 0;
    int r = 0;
    for (int l = 0; l < n; ++l) {
        while (cnt == 0 and r != n) {
            for (auto [ccnt, i] : pdel(a[r])) {
                if (nums[i] > 1)
                    cnt--;
                nums[i] += 1;
                if (nums[i] > 1)
                    cnt++;
            }
            r++;
        }
        prig[l][0] = r - 1 + (cnt == 0);
        for (auto [ccnt, i]  : pdel(a[l])) {
            if (nums[i] > 1)
                cnt--;
            nums[i] -= 1;
            if (nums[i] > 1)
                cnt++;
        }
    }
    for (int i = 1; i < 24; ++i) {
        for (int j = 0; j < n; ++j) {
            prig[j][i] = prig[prig[j][i-1]][i-1];
        }
    }
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        l--;
        int res = 0;
        for (int j = 23; j >= 0; --j) {
            if (prig[l][j] < r) {
                l = prig[l][j];
                res += (1 << j);
            }
        }
        cout << res + 1 << '\n';
    }
}