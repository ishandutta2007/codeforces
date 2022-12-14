# include <bits/stdc++.h>
using namespace std;
int pre[1000000];
int last[1000000];
int occur[1000000];
string s,t;
void PRE()
{
    int n=t.length();
    int i=0,j=-1;
    pre[i]=j;
    while(i<n)
    {
        while(j>=0 && t[i]!=t[j])
            j=pre[j];
        i++,j++;
        pre[i]=j;
    }
}
void KMP()
{
    int n=s.length();
    int m=t.length();
    int i=0,j=0;
    int l=-1;
    while(i<n)
    {
        while(j>=0 && s[i]!=t[j])
            j=pre[j];
        j++;
        i++;
        if (j==m)
        {
            j=pre[j];
            occur[i]=1;
            l=i-m;
        }
        last[i]=l;
    }
}
long long dp[1000000];
long long sum[1000000],sum1[1000000];
int main()
{
    cin>>s>>t;
    PRE();
    KMP();
    int n=s.length();
    long long ans=0;
    for (int i=1;i<=n;i++)
    {
        if (last[i]==-1)continue;
        if (!occur[i])
            dp[i]=dp[i-1];
        else
            dp[i]=sum[last[i]]+last[i]+1;
        sum1[i]=dp[i]+sum1[i-1];
        sum[i]=sum1[i]+sum[i-1];
        sum[i]=sum[i]%1000000007;
        ans+=dp[i]%1000000007;
        ans%=1000000007;
    }
    cout<<ans<<endl;
}