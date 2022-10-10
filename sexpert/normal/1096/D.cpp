#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string st;
    cin>>n>>st;
    long long cost[n+5];
    for(int i=1; i<=n; i++){
        cin>>cost[i];
    }
    long long dp[n+5][5];
    dp[0][1]=0;
    dp[0][2]=0;
    dp[0][3]=0;
    dp[0][4]=0;
    for(int i=1; i<=n; i++){
        if(st[i-1]=='h') dp[i][1]=dp[i-1][1]+cost[i];
        else dp[i][1]=dp[i-1][1];
        if(st[i-1]=='a') dp[i][2]=min(dp[i-1][1], dp[i-1][2]+cost[i]);
        else dp[i][2]=dp[i-1][2];
        if(st[i-1]=='r') dp[i][3]=min(dp[i-1][2], dp[i-1][3]+cost[i]);
        else dp[i][3]=dp[i-1][3];
        if(st[i-1]=='d') dp[i][4]=min(dp[i-1][3], dp[i-1][4]+cost[i]);
        else dp[i][4]=dp[i-1][4];
    }
    cout<<dp[n][4]<<endl;
}