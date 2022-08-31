#include <iostream>
#include <cassert>

using namespace std;

const int MX = 200005;
int a[MX];
int dp[MX];

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    dp[n-1] = 1;
    int sum = a[n-1];
    assert(m >= 1 && sum <= k);
    int res = 1;
    for (int r = n - 1, l = n - 2; l >= 0; l--) {
        sum += a[l];
        if (sum <= k) {
            dp[l] = dp[l + 1];
        } else {
            while (sum > k) {
                sum -= a[r--];
            }
            dp[l] = dp[r + 1] + 1;
        }
        // cout << l << ", " << dp[l] << endl;
        if (dp[l] <= m)
            res = n - l;
    }
    cout << res << endl;
    return 0;
}