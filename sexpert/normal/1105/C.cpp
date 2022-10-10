    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;
     
    const int MAXN = 2e5 + 5;
    const ll MOD = 1e9 + 7;
    ll cnt[3], dp[MAXN][3];
     
    int main() {
        int n;
        ll l, r;
        cin >> n >> l >> r;
        cnt[0] = r/3 - (l - 1)/3;
        cnt[1] = (r + 2)/3 - (l + 1)/3;
        cnt[2] = (r + 1)/3 - l/3;
        dp[0][0] = 1;
        for(int m = 0; m < n; m++) {
            for(int c1 = 0; c1 < 3; c1++) {
                for(int c2 = 0; c2 < 3; c2++) {
                    dp[m + 1][(c1 + c2)%3] = (dp[m + 1][(c1 + c2)%3] + dp[m][c1] * cnt[c2]) % MOD;
                }
            }
        }
        cout << dp[n][0] << endl;
    }