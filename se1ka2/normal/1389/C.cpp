#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        int dp[10][10][2];
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                dp[i][j][0] = dp[i][j][1] = 0;
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 10; j++){
                dp[s[i] - '0'][j][0] = dp[s[i] - '0'][j][1] + 1;
            }
            for(int j = 0; j < 10; j++){
                dp[j][s[i] - '0'][1] = dp[j][s[i] - '0'][0];
            }
        }
        int ans = 0;
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                if(i == j) ans = max(ans, dp[i][j][1]);
                else ans = max(ans, dp[i][j][1] * 2);
            }
        }
        cout << n - ans << endl;
    }
}