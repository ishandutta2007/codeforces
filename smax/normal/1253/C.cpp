#include <bits/stdc++.h>
using namespace std;

int a[200000];
long long dp[200000], prefixSum[200000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++)
        cin >> a[i];

    sort(a, a + n);
    for (int i=0; i<n; i++) {
        prefixSum[i] = (i >= m ? prefixSum[i-m] : 0) + a[i];
        dp[i] = (i > 0 ? dp[i-1] : 0) + prefixSum[i];
        cout << dp[i] << " ";
    }
    cout << "\n";

    return 0;
}