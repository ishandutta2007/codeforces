#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll dp[3]{0};
    ll p = 1;
    for(int i = 0; i < n; i++){
        if(s[i] == 'a') dp[0] = (dp[0] + p) % MOD;
        if(s[i] == 'b') dp[1] = (dp[1] + dp[0]) % MOD;
        if(s[i] == 'c') dp[2] = (dp[2] + dp[1]) % MOD;
        if(s[i] == '?'){
            dp[2] = (dp[2] * 3 + dp[1]) % MOD;
            dp[1] = (dp[1] * 3 + dp[0]) % MOD;
            dp[0] = (dp[0] * 3 + p) % MOD;
            p = p * 3 % MOD;
        }
    }
    cout << dp[2] << endl;
}