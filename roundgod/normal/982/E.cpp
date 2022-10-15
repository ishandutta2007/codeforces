#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,m,x,y,vx,vy;
ll gcd(ll a,ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
ll extgcd(ll a,ll b,ll &x,ll &y)
{
    ll d=a;
    if(b!=0)
    {
        d=extgcd(b,a%b,y,x);
        y-=(a/b)*x;
    }
    else
    {
        x=1;
        y=0;
    }
    return d;
}
int main()
{
    scanf("%I64d%I64d%I64d%I64d%I64d%I64d",&n,&m,&x,&y,&vx,&vy);
    if(vx==0&&vy==0)
    {
        puts("-1");
        return 0;
    }
    if(vx==0)
    {
        if(x!=0&&x!=n)
        {
            puts("-1");
            return 0;
        }
        if(vy<0) printf("%I64d %I64d\n",x,0LL);
        else printf("%I64d %I64d\n",x,m);
        return 0;
    }
    if(vy==0)
    {
        if(y!=0&&y!=m)
        {
            puts("-1");
            return 0;
        }
        if(vx<0) printf("%I64d %I64d\n",0LL,y);
        else printf("%I64d %I64d\n",n,y);
        return 0;
    }
    int flag1=0,flag2=0;
    if(vx==-1) {vx=1; x=n-x; flag1=1;}
    if(vy==-1) {vy=1; y=m-y; flag2=1;}
    ll x0,y0,del;
    ll ret=extgcd(n,m,x0,y0);
    if((x-y)%ret) {puts("-1"); return 0;}del=m/ret;
    x0*=(x-y)/ret;y0*=(x-y)/ret;
    while(x0<=0) x0+=del;
    while(x0-del>=1) x0-=del;
    y0=(x0*n+y-x)/m;
    if((x0&1)^(flag1&1)) printf("%I64d ",n); else printf("%I64d ",0LL);
    if((y0&1)^(flag2&1)) printf("%I64d ",m); else printf("%I64d ",0LL);
    return 0;
}