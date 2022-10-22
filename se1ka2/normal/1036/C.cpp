#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

ll solve(string s){
    if(s == "0") return 1;
    int l = s.size();
    ll dp[23][4][2];
    for(int i = 0; i <= l; i++) for(int j = 0; j <= 3; j++) dp[i][j][0] = dp[i][j][1] = 0;
    dp[0][0][0] = 1;
    for(int i = 1; i <= l; i++){
        if(s[i - 1] == '0'){
            for(int j = 0; j <= 3; j++){
                dp[i][j][0] += dp[i - 1][j][0];
                dp[i][j][1] += dp[i - 1][j][1];
            }
            for(int j = 1; j <= 3; j++){
                dp[i][j][1] += dp[i - 1][j - 1][0] * 9 + dp[i - 1][j - 1][1] * 9;
            }
        }
        else{
            for(int j = 0; j <= 3; j++){
                dp[i][j][0] += dp[i - 1][j][0] + dp[i - 1][j][1];
            }
            for(int j = 1; j <= 3; j++){
                dp[i][j][0] += dp[i - 1][j - 1][0] * (s[i - 1] - '0') + dp[i - 1][j - 1][1] * (s[i - 1] - '1');
                dp[i][j][1] += dp[i - 1][j - 1][0] * (9 - (s[i - 1] - '0')) + dp[i - 1][j - 1][1] * (10 - (s[i - 1] - '0'));
            }
        }
    }
    return dp[l][0][0] + dp[l][1][0] + dp[l][2][0] + dp[l][3][0];
}

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        ll l, r;
        cin >> l >> r;
        l--;
        string sr = to_string(r);
        string sl = to_string(l);
        reverse(sr.begin(), sr.end());
        reverse(sl.begin(), sl.end());
        cout << solve(sr) - solve(sl) << endl;
    }
}