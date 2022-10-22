#include <bits/stdc++.h>

using namespace std;

int main() {
    int w, b;
    cin >> w >> b;

    int w1 = w, b1 = b;

    int n = b + w;

    long double ans = 0;
    vector<vector<long double>> dp(w + 1, vector<long double>(b + 1, 0));
    dp[w][b] = 1;

    //while(!q.empty()) {
    for(int sum = n; sum > 0; sum--)
        for(w = max(0, sum - b1); w <= min(sum, w1); w++) {
            b = sum - w;
            //cout << w << ' ' << b << ' ' << dp[w][b] << endl;

            if((w + b) % 3 == n % 3) {
                if(w > 0) {
                    ans += w * dp[w][b] / sum;
                }

                if(b > 0) {
                    dp[w][b - 1] += b * dp[w][b] / sum;
                }
            } else if((w + b + 1) % 3 == n % 3) {
                if(b > 0) {
                    dp[w][b - 1] += b * dp[w][b] / sum;
                }
            } else {
                if(w > 0) {
                    dp[w - 1][b] += w * dp[w][b] / sum;
                }

                if(b > 0) {
                    dp[w][b - 1] += b * dp[w][b] / sum;
                }
            }
        }

    cout << setprecision(20) << fixed << ans << endl;
}