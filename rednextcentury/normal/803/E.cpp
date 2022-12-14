#include<bits/stdc++.h>
using namespace std;
int dp[1001][3001];
int b[1001][2300];
string s;
int n,k;
int DP(int i,int cur)
{
    if (i==n)
        return (cur==2*k) || (cur==0);
    if (cur==2*k || cur==0)
        return 0;
    if (dp[i][cur]!=-1)return dp[i][cur];
    if (s[i]=='L')
    {
        b[i][cur]=-1;
        return DP(i+1,cur-1);
    }
    else if (s[i]=='W')
    {
        b[i][cur]=1;
        return dp[i][cur]=DP(i+1,cur+1);
    }
    else if (s[i]=='D')
    {
        b[i][cur]=0;
        return dp[i][cur]=DP(i+1,cur);
    }
    else
    {
        if (DP(i+1,cur+1))
        {
            b[i][cur]=1;
            return dp[i][cur]=1;
        }
        if (DP(i+1,cur-1))
        {
            b[i][cur]=-1;
            return dp[i][cur]=1;
        }
        if (DP(i+1,cur))
        {
            b[i][cur]=0;
            return dp[i][cur]=1;
        }
        return dp[i][cur]=0;
    }
}
int main()
{
    memset(dp,-1,sizeof(dp));
    cin>>n>>k>>s;
    if (DP(0,k))
    {
        int x=k;
        for (int i=0;i<n;i++)
        {
            if (b[i][x]==1)
                s[i]='W',x++;
            else if (b[i][x]==-1)
                s[i]='L',x--;
            else s[i]='D';
        }
        cout<<s<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
}