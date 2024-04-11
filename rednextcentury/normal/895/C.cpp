#include <bits/stdc++.h>
using namespace std;
long long mod=1000000007;
long long P(long long a,long long b)
{
    if (b==0)return 1;
    long long x =P(a,b/2);
    x=(x*x)%mod;
    if (b%2)x=(x*a)%mod;
    return x;
}
long long inv(long long x){return P(x,mod-2);}
long long F[1000000];
long long C(long long n,long long k)
{
    if (k==0)return 1;
    long long A = F[n];
    long long B = F[n-k] * F[k];
    B%=mod;
    B=inv(B);
    return (A*B)%mod;
}
long long num[71];
long long Odd[71];
long long Even[71];
int msk[71];
long long dp[2][1000000];
bool prime(int x)
{
    for (int i=2;i<x;i++)
        if (x%i==0)return 0;
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    vector<int> pr;
    for (int i=2;i<=70;i++)if (prime(i))pr.push_back(i);
    int n;
    cin>>n;
    F[0]=1;
    for (int i=1;i<=n;i++)
    {
        F[i]=(F[i-1]*i)%mod;
    }
    while(n--)
    {
        int x;
        cin>>x;
        num[x]++;
    }
    for (int i=1;i<=70;i++)
    {
        int x=i;
        int mask=0;
        for (int j=0;j<pr.size();j++)
        {
            int cur=0;
            while(x%pr[j]==0)
                x/=pr[j],cur=1-cur;
            mask+=(1<<j)*cur;
        }
        msk[i]=mask;
        for (int j=0;j<=num[i];j++)
        {
            if (j%2)
                Odd[i]=(Odd[i]+C(num[i],j))%mod;
            else
                Even[i]=(Even[i]+C(num[i],j))%mod;
        }
    }

    long long mx = (1<<((int)pr.size()));
    dp[0][0]=1;
    int p=0;
    for (int i=0;i<70;i++)
    {
        for (int j=0;j<mx;j++)dp[!p][j]=0;
        for (int j=0;j<mx;j++)
        {
            dp[!p][j^msk[i+1]]=(dp[!p][j^msk[i+1]]+(dp[p][j]*Odd[i+1])%mod)%mod;
            dp[!p][j]=(dp[!p][j]+(dp[p][j]*Even[i+1])%mod)%mod;
        }
        p=!p;
    }
    cout<<(dp[p][0]-1+mod)%mod<<endl;
}