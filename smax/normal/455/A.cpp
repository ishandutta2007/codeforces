#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    long long a[100001], dp[100001];
    memset(a, 0, sizeof(a));
    cin >> n;
    for (int i=0; i<n; i++) {
        int j;
        cin >> j;
        a[j]++;
    }
    
    dp[0] = 0;
    dp[1] = a[1];
    for (int i=2; i<=100000; i++)
        dp[i] = max(dp[i-1], dp[i-2] + i * a[i]);
    
    cout << dp[100000] << endl;
    
    return 0;
}