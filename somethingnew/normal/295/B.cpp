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

using namespace std;
signed main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<vector<int>> g(n, vector<int>(n));
    for (auto &i : g)
        for (auto &j : i)
            cin >> j;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        nums[i]--;
    }
    vector<long long> res;
    reverse(all(nums));
    for (int k = 0; k < n; ++k) {
        long long res2 = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                g[i][j] = min(g[i][j], g[i][nums[k]] + g[nums[k]][j]);
        for (int i = 0; i <= k; ++i)
            for (int j = 0; j <= k; ++j)
                res2 += g[nums[i]][nums[j]];
        res.push_back(res2);
    }
    reverse(all(res));
    for (auto i : res)
        cout << i << ' ';
}