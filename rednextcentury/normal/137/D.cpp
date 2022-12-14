#include<bits/stdc++.h>
using namespace std;
int cost[501][501];
int dp[501][501];
int b[501][501];
int main()
{
    string s;
    cin>>s;
    int n=s.size();
    for (int i=0;i<n;i++)
    {
        int l,r,c;
        l=r=i,c=0;
        while(1)
        {
            cost[l+1][r+1]=c;
            l--,r++;
            if (l<0 || r>=n)break;
            if (s[l]!=s[r])c++;
        }
        if (i==0)continue;
        l=i-1,r=i,c=(s[l]!=s[r]);
        while(1)
        {
            cost[l+1][r+1]=c;
            l--,r++;
            if (l<0 || r>=n)break;
            if (s[l]!=s[r])c++;
        }
    }
    int k;
    cin>>k;
    dp[0][0]=0;
    b[0][0]=-1;
    for (int i=1;i<=n;i++)
    {
        dp[i][0]=1000000;
        for (int j=1;j<=k;j++)
        {
            dp[i][j]=10000000;
            for (int x=i;x>=1;x--)
            {
                if (dp[x-1][j-1]+cost[x][i]<dp[i][j])
                    dp[i][j]=dp[x-1][j-1]+cost[x][i],b[i][j]=x;
            }
        }
    }
    int mn=1000000,id=-1;
    for (int i=1;i<=k;i++)
        if (dp[n][i]<mn)
            mn=dp[n][i],id=i;
    cout<<mn<<endl;
    int v=n;
    vector<string> ret;
    while(v>0)
    {
        ret.push_back(s.substr(b[v][id]-1,v-b[v][id]+1));
        v=b[v][id]-1;
        id--;
    }
    for (int i=0;i<ret.size();i++)
    {
        for (int j=0;j<ret[i].size()/2;j++)
            ret[i][j]=ret[i][ret[i].size()-j-1];
    }
    for (int i=ret.size()-1;i>=0;i--)
    {
        cout<<ret[i];
        if (i>0)cout<<"+";
    }
    cout<<endl;
}