#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,k,s,t;
ll c[MAXN],v[MAXN],g[MAXN];
bool C(ll vol)
{
	ll tt=0;
	for(ll i=1;i<=k+1;i++)
	{
		if(vol<g[i]-g[i-1]) return false;
		else if(vol>=2*(g[i]-g[i-1])) tt+=g[i]-g[i-1];
		else 
		{
			ll dis=(g[i]-g[i-1])*2-vol;
			tt+=g[i]-g[i-1]+dis;
		}
	}
	return tt<=t;
}
int main()
{
	scanf("%I64d%I64d%I64d%I64d",&n,&k,&s,&t);
	for(ll i=1;i<=n;i++) scanf("%I64d%I64d",&c[i],&v[i]);
	for(ll i=1;i<=k;i++) scanf("%I64d",&g[i]);
	sort(g+1,g+1+k);
	g[0]=0;g[k+1]=s;
	ll l=1,r=2*INF+1;
	while(r-l>1)
	{
		ll mid=(l+r)/2;
		if(C(mid)) r=mid; else l=mid;
	}
	ll ans=2*INF+1;
	for(ll i=1;i<=n;i++) if(v[i]>=r) ans=min(ans,c[i]);
	if(ans==2*INF+1) puts("-1"); else printf("%I64d\n",ans);
	return 0;
}