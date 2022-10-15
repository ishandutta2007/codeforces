#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n,k,id[MAXN],ans[MAXN];
P a[MAXN];
int main()
{
	scanf("%I64d%I64d",&n,&k);
	for(ll i=1;i<=n;i++) scanf("%I64d",&a[i].F),a[i].S=i;
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++) id[a[i].S]=i;
	ll cnt=0;
	for(ll i=1;i<=n;i++) 
	{
		if(i!=1&&a[i].F>a[i-1].F) cnt=i-1;
		ans[a[i].S]=cnt;
	}
	for(ll i=1;i<=k;i++)
	{
		ll x,y;
		scanf("%I64d%I64d",&x,&y);
		x=id[x],y=id[y];
		if(a[x].F<a[y].F) ans[a[y].S]--; 
		if(a[y].F<a[x].F) ans[a[x].S]--;
	}
	for(ll i=1;i<=n;i++) printf("%I64d ",ans[i]);
	return 0;
}