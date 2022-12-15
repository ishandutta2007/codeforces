#include<bits/stdc++.h>
using namespace std;
long long f[1000001];
long long mod = 998244353;
long long P(long long a,long long b)
{
    if (b==0)return 1;
    long long x = P(a,b/2);
    x=(x*x)%mod;
    if (b%2)x=(x*a)%mod;
    return x;
}
long long inv(long long x)
{
    return P(x,mod-2);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    f[0]=1;
    for (int i=1;i<=1000000;i++)
        f[i]=(f[i-1]*i)%mod;
    int n;
    cin>>n;
    long long ret = f[n];
    long long mult=n;
    for (int i=n-1;i>1;i--)
    {
        ret = ret + ((f[i]-1)*mult)%mod;
        ret%=mod;
        mult = (mult*i)%mod;
    }
    cout<<ret<<endl;
}