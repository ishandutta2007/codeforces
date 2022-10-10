#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2020;
int dp[MAXN][MAXN];
int a[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, h, l, r;
    cin >> n >> h >> l >> r;

    for(int i = 0; i <= n; i++)
        fill(dp[i], dp[i] + MAXN, -1000000000);
    
    dp[0][0] = 0;
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        for(int j = 0; j < h; j++) {
            int re = (j + t) % h;
            if(l <= re && re <= r)
                dp[i + 1][re] = max(dp[i + 1][re], dp[i][j] + 1);
            else
                dp[i + 1][re] = max(dp[i + 1][re], dp[i][j]);
            re = (j + t - 1) % h;
            if(l <= re && re <= r)
                dp[i + 1][re] = max(dp[i + 1][re], dp[i][j] + 1);
            else
                dp[i + 1][re] = max(dp[i + 1][re], dp[i][j]);
        }
    }
    cout << *max_element(dp[n], dp[n] + h) << '\n';
}