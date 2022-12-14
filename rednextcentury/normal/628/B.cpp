#include<bits/stdc++.h>
using namespace std;
long long dp[1000001][5];
int main()
{

    string s;
    cin>>s;
    int n=s.length();
    dp[0][(s[0]-'0')%4]=1;
    long long ans=0;
    for (int i=0;i<n-1;i++)
    {
        dp[i+1][(s[i+1]-'0')%4]=1;
        for (int j=0;j<4;j++)
        {
            dp[i+1][(j*10+(s[i+1]-'0'))%4]+=dp[i][j];
        }
        ans+=dp[i][0];
    }
    cout<<ans+dp[n-1][0]<<endl;
}