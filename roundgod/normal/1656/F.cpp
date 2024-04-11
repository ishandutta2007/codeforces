#include<bits/stdc++.h>
#define MAXN 200005
#define INF 2000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,a[MAXN];
ll s;
pair<ll,ll> check(int x)
{
	if(a[n]+x<=0)
	{
		ll ans=0,cf=0;
		for(int i=1;i<=n-1;i++)
		{
			ans+=1LL*(a[i]+x)*(a[n]+x)-1LL*x*x;
			cf+=(a[i]+a[n]);
		}
		return make_pair(cf,ans);
	}
	if(a[1]+x>=0)
	{
		ll ans=0,cf=0;
		for(int i=2;i<=n;i++)
		{
			ans+=1LL*(a[i]+x)*(a[1]+x)-1LL*x*x;
			cf+=(a[i]+a[1]);
		}
		return make_pair(cf,ans);
	}
	int id=0;
	for(int i=1;i<=n;i++) if(a[i]+x>=0) {id=i-1; break;}
	ll ans=0,cf=0;
	for(int i=1;i<=id;i++)
	{
		ans+=1LL*(a[i]+x)*(a[n]+x)-1LL*x*x;
		cf+=(a[i]+a[n]);
	}
	for(int i=id+1;i<=n-1;i++)
	{
		ans+=1LL*(a[i]+x)*(a[1]+x)-1LL*x*x;
		cf+=(a[i]+a[1]);
	}
	return make_pair(cf,ans);
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		s=0;
		for(int i=1;i<=n;i++) s+=a[i];
		if((s+1LL*(n-2)*a[1]>0)||(s+1LL*(n-2)*a[n]<0)) {puts("INF"); continue;}
		int l=-1000001,r=1000001;
		while(r-l>1)
		{
			int mid=(l+r)/2;
			if(check(mid).F>=0) l=mid; else r=mid; 
		}
		auto p=check(l);
		auto q=check(l+1);
		printf("%lld\n",max(p.S,q.S));
	}
	return 0;
}