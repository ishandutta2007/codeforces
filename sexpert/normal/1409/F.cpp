#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX = 205;
int dp[MAX][MAX][MAX];

void chmax(int &x, int y) {
    x = max(x, y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    string s, t;
    cin >> n >> k >> s >> t;
    memset(dp, -1, sizeof dp);
    dp[0][0][0] = 0;
    for(int ps = 0; ps < n; ps++) {
        for(int cnt_a = 0; cnt_a <= ps; cnt_a++) {
            for(int rep = 0; rep <= min(k, ps); rep++) {
                if(dp[ps][cnt_a][rep] == -1)
                    continue;
                // change to a
                if(rep < k)
                    chmax(dp[ps + 1][cnt_a + 1][rep + 1], dp[ps][cnt_a][rep] + (t[0] == t[1] ? cnt_a : 0));
                // change to b
                if(rep < k)
                    chmax(dp[ps + 1][cnt_a + (t[0] == t[1])][rep + 1], dp[ps][cnt_a][rep] + cnt_a);
                // don't change
                chmax(dp[ps + 1][cnt_a + (t[0] == s[ps])][rep], dp[ps][cnt_a][rep] + (t[1] == s[ps] ? cnt_a : 0));
            }
        }
    }
    /*for(int ps = 0; ps <= n; ps++) {
        for(int cnt_a = 0; cnt_a <= ps; cnt_a++) {
            for(int rep = 0; rep <= min(k, ps); rep++) {
                if(dp[ps][cnt_a][rep] == -1)
                    continue;
                cout << ps << " " << cnt_a << " " << rep << ": " << dp[ps][cnt_a][rep] << '\n';
            }
        }
    }*/
    int ans = 0;
    for(int cnt_a = 0; cnt_a <= n; cnt_a++) {
        for(int rep = 0; rep <= k; rep++) {
            ans = max(ans, dp[n][cnt_a][rep]);
        }
    }
    cout << ans << '\n';
}