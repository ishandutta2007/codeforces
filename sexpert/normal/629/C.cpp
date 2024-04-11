    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    typedef pair<int, int> ii;
    typedef vector<int> vi;
     
    const ll MOD = 1e9 + 7;
     
    int off = 2002;
    ll dp[2005][2005];
     
    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
     
        dp[0][0] = 1;
        for(int l = 1; l <= 2004; l++) {
            for(int b = 0; b < 2004; b++) {
                dp[l][b] = (dp[l - 1][b + 1] + (b ? dp[l - 1][b - 1] : 0)) % MOD;
            }
        }
        int n, m;
        cin >> n >> m;
        int wo = 0, cur = 0;
        string s;
        cin >> s;
        for(auto c : s) {
            cur += (c == '(');
            cur -= (c == ')');
            wo = min(wo, cur);
        }
        ll ans = 0;
        for(int ba = -wo; ba <= n - m; ba++) {
            for(int l = ba; l <= n - m; l++) {
                if(ba + cur >= 2005)
                    continue;
                //cout << ba << " " << l << " " << dp[l][ba] * dp[n - m - l][ba - wo] << endl;
                ans = (ans + dp[l][ba] * dp[n - m - l][ba + cur]) % MOD;
            }
        }
        cout << ans << '\n';
    }