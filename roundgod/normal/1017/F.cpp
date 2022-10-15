/*************************************************************************
    > File Name: F.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-08 23:30:24
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 40005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef unsigned int ll;
typedef pair<int,int> P;
ll f[4][MAXN],g[4][MAXN],st[10],n,A,B,C,D; //f[i]:pi(n/i),g[i]:pi(i)
bool is_prime[100000];
ll p1(ll x)
{
    ll y=x+1; if(x%2==0) x/=2; else y/=2;
    return x*y;
}
ll p2(ll x)
{
    ll y=x+1,z=x*2+1;
    if(x%2==0) x/=2; else y/=2;
    if(x%3==0) x/=3; else if(y%3==0) y/=3; else z/=3;
    return x*y*z;
}
ll p3(ll x)
{
    ll y=p1(x);
    return y*y;
}
ll PrimeCount(ll n)
{
    ll i,j,k,m=0;
    for(m=1;m*m<=n;m++)
    {
        f[0][m]=(n/m-1);
        f[1][m]=(p1(n/m)-1)*C;
        f[2][m]=(p2(n/m)-1)*B;
        f[3][m]=(p3(n/m)-1)*A;
    }
    for(i=1;i<=m;i++)
    {
        g[0][i]=i-1;
        g[1][i]=(p1(i)-1)*C;
        g[2][i]=(p2(i)-1)*B;
        g[3][i]=(p3(i)-1)*A;
    }
    for(i=2;i<=m;i++)
    {
        if(g[0][i]==g[0][i-1]) continue;
        st[0]=1;
        for(k=1;k<4;k++) st[k]=st[k-1]*i;
        for(j=1;j<=min(m-1,n/i/i);++j)
        {
            for(k=0;k<4;k++)
            {
                if(i*j<m) f[k][j]-=st[k]*(f[k][i*j]-g[k][i-1]);
                else f[k][j]-=st[k]*(g[k][n/i/j]-g[k][i-1]);
            }
        }
        for(j=m;j>=i*i;j--) 
            for(k=0;k<4;k++)
                g[k][j]-=st[k]*(g[k][j/i]-g[k][i-1]);
    }
    for(i=1;i<=m+1;i++) f[0][i]*=D,g[0][i]*=D;
    ll ans=0;
    for(i=1;n/i>m;i++)
        for(int k=0;k<4;k++)
            ans+=f[k][i]-g[k][m];
    return ans;
}
int main()
{
    cin>>n>>A>>B>>C>>D;
    ll res=PrimeCount(n);
    memset(is_prime,true,sizeof(is_prime));
    is_prime[0]=is_prime[1]=false;
    for(ll i=2;(i-1)*(i-1)<=n;i++)
    {
        if(is_prime[i])
        {
            ll cnt=A*i*i*i+B*i*i+C*i+D;
            ll rem=n;
            while(rem) {res+=cnt*(rem/i); rem/=i;}
            for(ll j=2*i;(j-1)*(j-1)<=n;j+=i) is_prime[j]=false;
        }
    }
    cout<<res<<endl;
    return 0;
}