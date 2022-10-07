#include<bits/stdc++.h>
#define ll long long
using namespace std;
int dp[109][109][2];
int p[109];
main(){
    int n;
    cin >> n;
    int o = 0,e=0;
    for(int i = 1; i <= n; i++){
        if(i%2==0) e++;
        else o++;
        cin >> p[i];
        if(p[i]%2==0) e--;
        else o--;

    }
    for(int i = 0; i <= n; i++)
        dp[1][i][0] = n+1,dp[1][i][1] = n+1;
    if(p[1] == 0) dp[1][1][1] = 0, dp[1][0][0] = 0;
    else dp[1][0][p[1]%2]=0;
    int x= (p[1] == 0);
    for(int i = 2; i <= n; i++){
        if(p[i] != 0){
            for(int j = 0; j <= n; j++){
                dp[i][j][(p[i]+1)%2] = n+1;
                dp[i][j][p[i]%2] = min(dp[i-1][j][p[i]%2],dp[i-1][j][(p[i]+1)%2]+1);
           }
        }
        else{
            x++;
            for(int j = 0; j <= n; j++){
                if(j > x) {dp[i][j][0] = dp[i][j][1] = n+1;  continue;}
                if(j) dp[i][j][1] = min(dp[i-1][j-1][0] + 1, dp[i-1][j-1][1]);
                else dp[i][j][1] = n+1;
                dp[i][j][0] = min(dp[i-1][j][0],dp[i-1][j][1]+1);
            }
        }
    }
    int ans = min(dp[n][o][0],dp[n][o][1]);
        cout<<ans<<endl;
}