#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> pr(n);
    for (int i = 0; i < n; i++) {
        cin >> pr[i];
        pr[i]--;
    }

    vector<int> dp(n);
    for (int i = 0; i < n; i++) {
        int left_bound = pr[i];
        dp[i] = min(k, i - left_bound - 1) + min(k, n - i - 1) + 1;
        if (left_bound >= 0) {
            dp[i] += dp[left_bound];
            if (left_bound + k >= i - k) dp[i] -= min(left_bound + k, n - 1) - max(i - k, left_bound + 1) + 1;
        }
        cout << dp[i] << ' ';
    }

    cout << endl;

    return 0;
}