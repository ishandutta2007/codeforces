#include<bits/stdc++.h>
using namespace std;
int dp[5009][5009];
int mod=1e9+7;
main()

{
    dp[0][0]=1;
    int n;
    cin>>n;
    int z=0;
    for (int i=1; i<=n; i++)
    {
        char k;
        cin>>k;
        if(k=='f') {for (int j=0; j<=n; j++) dp[i][j+1]=dp[i-1][j]; continue;}
        int S=0;
        for (int j=n; j>=0; j--)
            {
                S=(S+dp[i-1][j])%mod;
                dp[i][j]=S;
            }
        z=0;
    }
    cout<<dp[n][0]<<endl;
}