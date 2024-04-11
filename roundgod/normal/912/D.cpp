#include<bits/stdc++.h>
#define MAXN 300005
using namespace std;
typedef long long ll;
ll n,m,r,k;
ll a[MAXN],b[MAXN];
ll cnta[MAXN],cntb[MAXN],suma[MAXN],sumb[MAXN];
ll findorder(ll x)
{
	ll cnt=0;
	for(ll i=1;i<=n;i++)
	{
		if((x-1)/a[i]>=m) continue;
		cnt+=m-cntb[(x-1)/a[i]];
	}
	return cnt;
}
ll findsum(ll x)
{
	ll s=0;
	for(ll i=1;i<=n;i++)
	{
		if((x-1)/a[i]>=m) continue;
		s+=a[i]*(sumb[m]-sumb[(x-1)/a[i]]);
	}
	return s;
}
int main()
{
	scanf("%I64d%I64d%I64d%I64d",&n,&m,&r,&k);
	memset(cnta,0,sizeof(cnta));
	memset(cntb,0,sizeof(cntb));
	for(ll i=1;i<=n;i++)
	{
		a[i]=min(n+1,i+r)-max(i,r);
		cnta[a[i]]++;
	}
	for(ll j=1;j<=m;j++)
	{
		b[j]=min(m+1,j+r)-max(j,r);
		cntb[b[j]]++;
	}
	suma[0]=sumb[0]=0;
	for(ll i=1;i<MAXN;i++)
		suma[i]=suma[i-1]+cnta[i]*i;
	for(ll i=1;i<MAXN;i++)
		sumb[i]=sumb[i-1]+cntb[i]*i;
	for(ll i=1;i<MAXN;i++)
		cnta[i]+=cnta[i-1];
	for(ll i=1;i<MAXN;i++)
		cntb[i]+=cntb[i-1];
	ll lb=1,rb=r*r+1;
	while(rb-lb>1)
	{
		ll mid=(lb+rb)/2;
		if(findorder(mid)<=k) rb=mid; else lb=mid;
	}
	ll x=findorder(lb),ans=findsum(lb);
	printf("%.10f\n",(double)(ans-(x-k)*lb)/((n-r+1)*(m-r+1)));
	return 0;
}