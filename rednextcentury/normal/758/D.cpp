#include<bits/stdc++.h>
using namespace std;
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
long long base;
string s;
long long dp[1000][1000];
int n;
long long conv(string x)
{
    long long ret=0;
    for(int i=0;i<x.size();i++)
    {
        ret=ret*10+x[i]-'0';
    }
    return ret;
}
long long p[100];
bool check(string op,int k)
{
    if (op.length()>9)return 0;
    if (p[k]==-1)
        return 0;
    long long x=conv(op);
    if (x>=base)return 0;
    if (x==0)return 1;
    if (1000000000000000000LL/x < p[k])
        return 0;
    return 1;
}
long long get(string op,int k)
{
    long long x=conv(op);
    return x*p[k];
}
long long calc()
{

    for (int i=1;i<=n;i++)
    {
        dp[i][0]=-1;
        for (int k=1;k<=n;k++)
        {
            string cur="";
            dp[i][k]=1000000000000000001LL;
            for (int j=i;j>=1;j--)
            {
                cur=cur+s[j];
                if (cur[0]=='0' && cur.length()>1)continue;
                if (!check(cur,k-1))
                    break;
                if (dp[j-1][k-1]==-1)
                    continue;
                dp[i][k]=min(dp[i][k],dp[j-1][k-1]+get(cur,k-1));
            }
            if (dp[i][k]==1000000000000000001LL)
                dp[i][k]=-1;
        }
    }
    long long ret=1000000000000000001LL;
    for (int i=1;i<=n;i++)
    {
        if (dp[n][i]!=-1)
        {
            ret=min(ret,dp[n][i]);
        }
    }
    return ret;
}
int main()
{
    fast_io
    cin>>base>>s;
    reverse(s.begin(),s.end());
    n=s.size();
    s="$"+s;
    p[0]=1;
    for (int i=1;i<=70;i++){
        if (p[i-1]==-1)
        {
            p[i]=-1;
            continue;
        }
        if (1000000000000000000LL/p[i-1] < base)
            p[i]=-1;
        else
        p[i]=p[i-1]*base;
    }
    cout<<calc()<<endl;

}