#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    long long s = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
    }
        
        
    vector<long long> dp(n, 0);
    dp[0] = a[0] % 3;
    for(int i = 1; i < n; i++) {
        
        int cnt = min(a[i] / 2 * 1ll, dp[i - 1]);
        a[i] -= cnt * 2;
        
        dp[i] = dp[i - 1] - cnt + a[i] % 3;
        //cout << dp[i] << endl;
    }
    
    cout << (s - dp[n - 1]) / 3;
}