#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<int, 2>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<vector<ii>> dp(n + 1, vector<ii>(n + 1, {26, 1000000000}));
    vector<vector<int>> grid(n + 1, vector<int>(n + 1)), good(n + 1, vector<int>(n + 1));

    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for(int j = 1; j <= n; j++)
            grid[i][j] = (s[j - 1] - 'a');
    }
    string ans;
    dp[0][1] = dp[1][0] = {0, 0};
    good[0][1] = good[1][0] = 1;
    for(int s = 2; s <= 2*n; s++) {
        ii glo = {26, 1000000000};
        for(int r = 1; r <= min(n, s - 1); r++) {
            int c = s - r;
            if(c > n)
                continue;
            if(good[r - 1][c]) {
                dp[r][c] = min(dp[r][c], {grid[r][c], dp[r - 1][c][1]});
                if(dp[r - 1][c][1] < k)
                    dp[r][c] = min(dp[r][c], ii{0, dp[r - 1][c][1] + 1});
            }
            if(good[r][c - 1]) {
                dp[r][c] = min(dp[r][c], {grid[r][c], dp[r][c - 1][1]});
                if(dp[r][c - 1][1] < k)
                    dp[r][c] = min(dp[r][c], ii{0, dp[r][c - 1][1] + 1});
            }
            glo = min(glo, dp[r][c]);
        }
        ans += ('a' + glo[0]);
        for(int r = 1; r <= min(n, s - 1); r++) {
            int c = s - r;
            if(c > n)
                continue;
            if(dp[r][c][0] == glo[0])
                good[r][c] = 1;
        }
        //cout << glo[0] << endl;
    }
    cout << ans << '\n';
}