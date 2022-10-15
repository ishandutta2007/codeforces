#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,a,b;
ll hp[MAXN],dmg[MAXN];
ll gain[MAXN];
bool used[MAXN];
int main()
{
	scanf("%I64d%I64d%I64d",&n,&a,&b);
	ll ans=0;
	for(ll i=0;i<n;i++) 
	{
		scanf("%I64d%I64d",&hp[i],&dmg[i]);
		ans+=dmg[i];
	}
	for(ll i=0;i<n;i++)
	{
		ll t=hp[i]<<a;
		gain[i]=t>dmg[i]?t-dmg[i]:0;
	}
	priority_queue<P> pque;
	for(ll i=0;i<n;i++)
		if(hp[i]>dmg[i]) pque.push(P(hp[i]-dmg[i],i));
	memset(used,false,sizeof(used));
	if(b==0)
	{
		printf("%I64d\n",ans);
		return 0;
	}
	ll least=0;
	while(b>0&&pque.size())
	{
		P p=pque.top();
		pque.pop();
		ans+=p.F;used[p.S]=true;
		b--;
		if(b==0) least=p.F;
	}
	ll res=0;
	if(b>0)
	{
		for(ll i=0;i<n;i++)
		{
			ll q=hp[i]>dmg[i]?gain[i]-(hp[i]-dmg[i]):gain[i];
			if(q>res) res=q;
		}
		ans+=res;
		printf("%I64d\n",ans);
		return 0;
	}
	else
	{
		for(ll i=0;i<n;i++)
		{
			ll q=(hp[i]>dmg[i]&&used[i])?gain[i]-(hp[i]-dmg[i]):gain[i]-least;
			if(q>res) res=q;
		}
		ans+=res;
		printf("%I64d\n",ans);
	}
	return 0;
}