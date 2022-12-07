#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll Mod=1e9+7,M=1e6+5;
ll mul(const ll a,const ll b){return a*b%Mod;}
ll add(const ll a,const ll b){return (a+b)%Mod;}
ll sub(const ll a,const ll b){return ((a-b)%Mod+Mod)%Mod;}
ll power(ll x,ll cs)
{
	ll ras=1;
	while(cs)
	{
		if(cs&1ll) ras=mul(ras,x);
		x=mul(x,x);cs>>=1;
	}
	return ras;
}
ll rd()
{
	ll rx=0,fx=1;char c=getchar();
	while(c<48||c>57)
	{
		if(c=='-') fx=-1;
		c=getchar();
 	}
	while(c>=48&&c<=57)
	{
		rx=rx*10+c-48;
		c=getchar();
	}
	return rx*fx;
}
ll n,P,ans;
ll a[M];
void Solve()
{
	ll i,der,las;
	der=0;ans=0;
	n=rd();P=rd();
	for(i=1;i<=n;i++) a[i]=rd();
	if(P==1)
	{
		printf("%lld\n",n&1ll);
		return ;
	}
	sort(a+1,a+n+1);
	//printf("n %lld\n",n);
	for(i=n;i>=1;i--)
	{
		if(i==n||der==0) las=a[i];
		else
		{
			while(las>a[i]&&der<M) las--,der*=P;
		}

		
		if(der>0)
		{
			ans=sub(ans,power(P,a[i]));
			der--;
		}
		else
		{
			der++;
			ans=power(P,a[i]);
		}
		//printf("OK %lld %lld   %lld\n",i,a[i],ans);
	}
	printf("%lld\n",ans);
}
int main()
{
	ll T;
	T=rd();
	while(T--) Solve();
	return 0;
}