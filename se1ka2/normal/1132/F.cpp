#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int dp[503][503];
    for(int i = 0; i < n; i++) for(int j = 0; j < i; j++) dp[i][j] = 1000000;
    for(int i = 0; i < n; i++) for(int j = i; j < n; j++) dp[i][j] = 0;
    for(int i = 0; i < n; i++){
        dp[i][i] = 1;
        for(int j = i - 1; j >= 0; j--){
            dp[i][j] = dp[i - 1][j] + 1;
            for(int k = i - 1; k >= j; k--){
                if(s[k] == s[i]) dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - 1][k + 1]);
            }
        }
    }
    cout << dp[n - 1][0] << endl;
}