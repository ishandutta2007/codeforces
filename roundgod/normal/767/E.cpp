#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n,m,c[MAXN],w[MAXN];
priority_queue<P,vector<P>,greater<P> >pque;
bool used[MAXN];
int main()
{
	scanf("%I64d%I64d",&n,&m);
	ll s=0;
	for(ll i=0;i<n;i++)
		scanf("%I64d",&c[i]);
	for(ll i=0;i<n;i++)
	{
		scanf("%I64d",&w[i]);
		w[i]=w[i]*((100-c[i]%100)%100);
	}
	memset(used,false,sizeof(used));
	ll ans=0;
	for(ll i=0;i<n;i++)
	{
		if(c[i]%100==0) continue;
		m-=c[i]%100;
		pque.push(P(w[i],i));
		if(m<0)
		{
			P p=pque.top();
			pque.pop();
			m+=100;
			ans+=p.F;
			used[p.S]=true;
		}
	}
	printf("%I64d\n",ans);
	for(ll i=0;i<n;i++)
	{
		if(!used[i]) printf("%I64d %I64d\n",c[i]/100,c[i]%100);
		else printf("%I64d %I64d\n",c[i]/100+1,0);
	}
	return 0;
}