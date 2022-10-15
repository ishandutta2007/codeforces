#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n,x1,x2;
P a[MAXN];
ll b[MAXN],lim,length;
int main()
{
	scanf("%I64d%I64d%I64d",&n,&x1,&x2);
	for(ll i=1;i<=n;i++) 
	{
		scanf("%I64d",&a[i].F);
		a[i].S=i;
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++) b[i]=a[i].F;
	lim=-1;length=-1;
	for(ll i=n;i>=1;i--) 
	{
		if((x2-1)/b[i]+i<=n)
		{
			lim=i;
			length=(x2-1)/b[i]+1;
			break;
		}
	}
	//printf("%I64d %I64d\n",lim,length);
	if(lim==-1) {puts("No"); return 0;}
	for(ll i=1;i<=n-1;i++)
	{
		ll len=(x1-1)/b[i]+1;
		if(i+len<=lim)
		{
			puts("Yes");
			printf("%I64d %I64d\n",len,length);
			for(ll j=i;j<i+len;j++)
				printf("%I64d ",a[j].S);
			puts("");
			for(ll j=lim;j<lim+length;j++)
				printf("%I64d ",a[j].S);
			return 0;
		}
	}
	swap(x1,x2);
	lim=-1;length=-1;
	for(ll i=n;i>=1;i--)
	{
		if((x2-1)/b[i]+i<=n)
		{
			lim=i;
			length=(x2-1)/b[i]+1;
			break;
		}
	}
	if(lim==-1) {puts("No"); return 0;}
	for(ll i=1;i<=n-1;i++)
	{
		ll len=(x1-1)/b[i]+1;
		if(i+len<=lim)
		{
			puts("Yes");
			printf("%I64d %I64d\n",length,len);
			for(ll j=lim;j<lim+length;j++)
				printf("%I64d ",a[j].S);
			puts("");
			for(ll j=i;j<i+len;j++)
				printf("%I64d ",a[j].S);
			return 0;
		}
	}
	puts("No");
	return 0;
}