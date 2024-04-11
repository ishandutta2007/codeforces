#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000000000000
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n,L;
ll cost[MAXN];
ll findcost(ll x)
{
	if(x==0) return 0;
	ll cnt=0,t=x;
	while(t>0)
	{
		t=t>>1;
		cnt++;
	}
	ll ans=min(cost[cnt+1],cost[cnt]+findcost(x-(1<<(cnt-1))));
	return ans;
}
int main()
{
	scanf("%I64d%I64d",&n,&L);
	for(ll i=1;i<=32;i++)
		cost[i]=INF;
	for(ll i=1;i<=n;i++)
		scanf("%I64d",&cost[i]);
	for(ll i=n;i>1;i--)
		for(ll j=i-1;j>=1;j--)
			if(cost[j]>cost[i]) cost[j]=cost[i];
	for(ll i=2;i<=32;i++)
		cost[i]=min(cost[i],2*cost[i-1]);
	printf("%I64d\n",findcost(L));
	return 0;
}