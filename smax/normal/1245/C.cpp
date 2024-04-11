#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int dp[100001] = {1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    for (int i=0; i<s.length(); i++) {
        dp[i+1] = (s[i] == 'w' || s[i] == 'm' ? 0 : dp[i]);
        if (i > 0 && s[i] == s[i-1] && (s[i] == 'u' || s[i] == 'n'))
            dp[i+1] = (dp[i+1] + dp[i-1]) % MOD;
    }

    cout << dp[s.length()] << "\n";

    return 0;
}