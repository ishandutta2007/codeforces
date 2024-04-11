#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
int c[505];
bool dp[505][505][505];
vector<int> ans;
signed main()
{
    cin>>n>>k;
    dp[0][0][0]=1;
    for(int i=1;i<=n;i++)
        cin>>c[i];
    for(int z=1;z<=n;z++)
        for(int i=0;i<=k;i++)
            for(int j=0;j<=i&&j<=k;j++)
            {
                if(dp[z-1][i][j] || i>=c[z]&&dp[z-1][i-c[z]][j] || j>=c[z]&&dp[z-1][i-c[z]][j-z[c]])
                    dp[z][i][j]=1;
            }
    for(int i=0;i<=k;i++)
        if(dp[n][k][i])
            ans.push_back(i);
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
}