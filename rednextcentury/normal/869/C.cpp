#include <bits/stdc++.h>
using namespace std;
long long c[5001][5001];
long long mod=998244353;
long long C(long long a,long long b)
{
    if (c[a][b]!=-1)
        return c[a][b];
    if (a==b)
        return c[a][b]=1;
    if (b==0)
        return c[a][b]=1;
    c[a][b]=(C(a-1,b-1)+C(a-1,b))%mod;
    return c[a][b];
}
long long fact[1000000];
int main()
{
    memset(c,-1,sizeof(c));
    fact[0]=1;
    for (int i=1;i<=5000;i++)
        fact[i]=(fact[i-1]*i)%mod;
    int x,y,z;
    cin>>x>>y>>z;
    long long r1=0,r2=0,r3=0;
    for (int i=0;i<=min(x,y);i++)
    {
        r1+=(((C(x,i)*C(y,i))%mod)*fact[i])%mod;
        r1%=mod;
    }
    for (int i=0;i<=min(x,z);i++)
    {
        r2+=(((C(x,i)*C(z,i))%mod)*fact[i])%mod;
        r2%=mod;
    }
    for (int i=0;i<=min(z,y);i++)
    {
        r3+=(((C(z,i)*C(y,i))%mod)*fact[i])%mod;
        r3%=mod;
    }
    r1=(r1*r2)%mod;
    r1=(r1*r3)%mod;
    cout<<r1<<endl;
}