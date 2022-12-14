#include<bits/stdc++.h>
using namespace std;
long long mod = 998244353;
long long P(long long a,long long b)
{
    if (b==0)return 1;
    if (b%2)return (a*(P(a,b-1)))%mod;
    long long x = P(a,b/2);
    return (x*x)%mod;
}
long long inv(long long x)
{
    if(x==0)return 1;
    return P(x,mod-2);
}
long long dp[5001][5001];
long long sum[5001];
long long a[5001];
int first[5001];
int num[50001];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++)
    {
        if (first[a[i]]==0)
            first[a[i]]=i;
        num[a[i]]++;
    }
    long long ret=0,A=0,B=0;
    for (int k=1;k<=n;k++)
    {
        if (k==1)
            sum[0]=1;
        else
            sum[0]=0;
        for (int i=1;i<=n;i++)
            sum[i]=(sum[i-1]+dp[k-1][i])%mod;
        A=inv(n-k+1);
B=inv(n-k);
        for (int i=k;i<=n;i++)
        {

            dp[k][i]=(sum[first[a[i]]-1]*A)%mod;
            if (n==k)continue;
            long long P = (num[a[i]]-1);
            long long Q = B;
            ret+=(dp[k][i] * ((P*Q)%mod))%mod;
            ret%=mod;
        }
    }
    cout<<ret<<endl;
}