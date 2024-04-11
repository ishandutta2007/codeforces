#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n;
P a[MAXN],b[MAXN],c[MAXN],d[MAXN];
int main()
{
	scanf("%I64d",&n);
	ll t1=0,t2=0;
	for(ll i=0;i<n;i++)
	{
		ll u,v;
		scanf("%I64d%I64d",&u,&v);
		if((u+v)&1) a[t1++]=P(u+v,u-v); else b[t2++]=P(u+v,u-v);
	}
	sort(a,a+t1);
	sort(b,b+t2);
	ll ans=0,l,r;
	if(t1>3)
	{
		l=a[0].S;r=a[0].S;
		for(ll i=0;i<t1-1;i++)
		{
			l=min(a[i].S,l);
			r=max(a[i].S,r);
			c[i].F=l,c[i].S=r;
		}
		l=a[t1-1].S;r=a[t1-1].S;
		for(ll i=t1-1;i>0;i--)
		{
			l=min(a[i].S,l);
			r=max(a[i].S,r);
			d[i-1].F=l,d[i-1].S=r;
		}
		for(ll i=0;i<t1-1;i++)
			ans+=(a[i+1].F-a[i].F)*max(0LL,min(c[i].S,d[i].S)-max(c[i].F,d[i].F));
	}
	if(t2>3)
	{
		ll l=b[0].S;r=b[0].S;
		for(ll i=0;i<t2-1;i++)
		{
			l=min(b[i].S,l);
			r=max(b[i].S,r);
			c[i].F=l,c[i].S=r;
		}
		l=b[t2-1].S;r=b[t2-1].S;
		for(ll i=t2-1;i>0;i--)
		{
			l=min(b[i].S,l);
			r=max(b[i].S,r);
			d[i-1].F=l,d[i-1].S=r;
		}
		for(ll i=0;i<t2-1;i++)
			ans+=(b[i+1].F-b[i].F)*max(0LL,min(c[i].S,d[i].S)-max(c[i].F,d[i].F));
	}
	printf("%I64d\n",ans/4);
	return 0;
}