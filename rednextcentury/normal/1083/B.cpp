#include <bits/stdc++.h>
using namespace std;
long long dp[1000000][2][2]; // i lower upper
long long ret[1000000];
string s,t;
void sol()
{
    memset(dp,0,sizeof(dp));
    if (s[0]==t[0])
        dp[0][1][1]=1;
    else if (s[0]=='a' && t[0]=='b')
        dp[0][1][0]=1,dp[0][0][1]=1;
    for (int i=0;i+1<s.size();i++)
    {
        for (int j=0;j<2;j++)
        {
            for (int x=0;x<2;x++)
            {
                dp[i][j][x]=min(1000000000LL,dp[i][j][x]);
                int l = s[i+1]-'a';
                int r = t[i+1]-'a';
                if (j==0)l=0;
                if (x==0)r=1;
                for (int op=l;op<=r;op++)
                {
                    int newJ = j && (op==l);
                    int newX = x && (op==r);
                    dp[i+1][newJ][newX]+=dp[i][j][x];
                }
            }
        }
    }
    for (int i=0;i<s.size();i++)
        ret[i]=min(1000000000LL,dp[i][0][0]+dp[i][1][0]+dp[i][0][1]+dp[i][1][1]);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    long long n;
    long long k;
    cin>>n>>k;
    cin>>s>>t;
    sol();
    long long ans=0;
    long long sub = 0;
    for (int i=0;i<s.size();i++)
    {
        ret[i]-=sub;
        if (ret[i]<0)continue;
        if (k>ret[i])
        {
            sub+=ret[i];
            k-=ret[i];
            ans+=(n-i)*ret[i];
        }
        else
        {
            sub+=k;
            ans+=k*(n-i);
            k=0;
        }
        if (k==0)break;
    }
    cout<<ans<<endl;
}