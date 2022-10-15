#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll prime[MAXN];
bool is_prime[MAXN];
ll sieve(ll n)
{
    ll p=0;
    for(ll i=0;i<=n;i++) is_prime[i]=true;
    is_prime[0]=is_prime[1]=false;
    for(ll i=2;i<=n;i++)
    {
        if(is_prime[i]) prime[p++]=i;
        for(ll j=0;j<p;j++)
        {
            if(prime[j]*i>n) break;
            is_prime[prime[j]*i]=false;
            if(i%prime[j]==0) break;
        }
    }
    return p;
}
ll gcd(ll a,ll b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
ll x,y;
int main()
{
	scanf("%I64d%I64d",&x,&y);
	ll ans=0;
	ll p=sieve(1000000);
	while(y!=0)
	{
		if(x==1)
		{
			ans+=y;
			break;
		}
		ll g=gcd(x,y);
		if(g!=1)
		{
			x=x/g;
			y=y/g;
		}
		ll res=INF;
		for(ll i=0;i<p;i++)
		{
			if(prime[i]*prime[i]>x) break;
			if(x%prime[i]==0) {res=min(res,y%prime[i]); res=min(res,y%(x/prime[i]));}
		}
		//printf("%I64d\n",res);
		res=min(res,y);
		if(y>x) res=min(res,y%x);
		//printf("%I64d %I64d\n",x,y);
		ans+=res;
		y-=res; 
	}
	printf("%I64d\n",ans);
	return 0;
}