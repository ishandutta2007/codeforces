#include <iostream>
#include <string>
using namespace std;

const int INF = 1000000000;

string s[1000002];
int b[1000002];
int dp[1000002][8];
int p[8] = {0, 1, 1, 2, 1, 2, 2, 3};

int main()
{
    int n, m;
    cin >> n >> m;
    if(n > 3 && m > 3){
        cout << -1 << endl;
        return 0;
    }
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    if(n <= m){
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++) b[i] += ((s[j][i] - '0') << j);
        }
    }
    else{
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++) b[i] += ((s[i][j] - '0') << j);
        }
        swap(n, m);
    }
    if(n == 1){
        cout << 0 << endl;
        return 0;
    }
    for(int j = 0; j < (1 << n); j++){
        dp[0][j] = p[j ^ b[0]];
    }
    if(n == 2){
        for(int i = 1; i < m; i++){
            for(int j = 0; j < (1 << n); j++){
                dp[i][j] = p[j ^ b[i]];
                if(j == 0 || j == 3) dp[i][j] += min(dp[i - 1][1], dp[i - 1][2]);
                else dp[i][j] += min(dp[i - 1][0], dp[i - 1][3]);
            }
        }
    }
    else{
        for(int i = 1; i < m; i++){
            for(int j = 0; j < (1 << n); j++){
                dp[i][j] = p[j ^ b[i]];
                if(j == 0 || j == 7) dp[i][j] += min(dp[i - 1][2], dp[i - 1][5]);
                else if(j == 1 || j == 6) dp[i][j] += min(dp[i - 1][3], dp[i - 1][4]);
                else if(j == 2 || j == 5) dp[i][j] += min(dp[i - 1][0], dp[i - 1][7]);
                else dp[i][j] += min(dp[i - 1][1], dp[i - 1][6]);
            }
        }
    }
    int ans = INF;
    for(int j = 0; j < (1 << n); j++) ans = min(ans, dp[m - 1][j]);
    cout << ans << endl;
}