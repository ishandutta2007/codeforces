#include<bits/stdc++.h>
using namespace std;
vector<int> v[1000];
int best[1001][1001];
int dp[1001][1001];
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            char x;
            cin>>x;
            if (x=='1')
                v[i].push_back(j);
        }
    }
    for (int i=0;i<n;i++)
    {
        if (v[i].size()==0)
            continue;
        best[i][0]=v[i][v[i].size()-1]-v[i][0]+1;
        for (int x=1;x<v[i].size();x++)
        {
            best[i][x]=1000000000;
            for (int j=0;j<=x;j++)
            {
                int used=j;
                int left=x-used;
                best[i][x]=min(best[i][x],v[i][v[i].size()-left-1]-v[i][j]+1);
            }
        }
        for (int x=v[i].size();x<=k;x++)
            best[i][x]=0;
    }
    for (int i=0;i<=k;i++)
        dp[0][i]=best[0][i];
    for (int i=1;i<n;i++)
    {
        for (int x=0;x<=k;x++)
        {
            dp[i][x]=1000000;
            for (int j=0;j<=x;j++)
            {
                dp[i][x]=min(dp[i][x],dp[i-1][x-j]+best[i][j]);
            }
        }
    }
    cout<<dp[n-1][k]<<endl;
}