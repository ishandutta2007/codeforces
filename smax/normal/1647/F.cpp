#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++)
        cin >> a[i];
    
    int ret = 0;
    for (int rep=0; rep<2; rep++) {
        int mx = int(max_element(a.begin(), a.end()) - a.begin()), minRight = INT_MIN;
        // after first maximum
        // dp stores minimum start of decreasing sequence not including a[i]
        for (int i=n-2; i>=mx; i--) {
            // dp[i] = dp[i+1] if a[i] > a[i+1]
            // dp[i] = a[i+1] if a[i] > dp[i+1]
            minRight = min(a[i] > a[i+1] ? minRight : INT_MAX, a[i] > minRight ? a[i+1] : INT_MAX);
        }
        // before second maximum
        // dp stores minimum end of increasing sequence not including a[i]
        vector<int> dp(n);
        dp[0] = INT_MIN;
        for (int i=1; i<mx; i++) {
            // dp[i] = dp[i-1] if a[i] > a[i-1]
            // dp[i] = a[i-1] if a[i] > dp[i-1]
            dp[i] = min(a[i] > a[i-1] ? dp[i-1] : INT_MAX, a[i] > dp[i-1] ? a[i-1] : INT_MAX);
        }
        // between second and first maximum
        // dpInc stores maximum start of decreasing sequence if a[i] is part of increasing
        // dpDec stores minimum start of increasing sequence if a[i] is part of decreasing
        // note definition is flipped here, increasing and decreasing from the right
        int dpInc = INT_MIN, dpDec = minRight;
        for (int i=mx-1; i>=0; i--) {
            // dpInc = dpInc if a[i] > a[i+1]
            // dpInc = a[i+1] if a[i] > dpDec
            // dpDec = dpDec if a[i] < a[i+1]
            // dpDec = a[i+1] if a[i] < dpInc
            tie(dpInc, dpDec) = make_pair(max(a[i] > a[i+1] ? dpInc : INT_MIN, a[i] > dpDec ? a[i+1] : INT_MIN), min(a[i] < a[i+1] ? dpDec : INT_MAX, a[i] < dpInc ? a[i+1] : INT_MAX));
            if (dp[i] < dpInc)
                ret++;
        }
        reverse(a.begin(), a.end());
    }
    cout << ret << "\n";
    
    return 0;
}