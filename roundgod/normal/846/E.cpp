#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,a[MAXN],p[MAXN],cost[MAXN];
ll mul(ll x,ll y)
{
	if(x>INF/y) return INF;
	return min(x*y,INF);
}
int main()
{
	scanf("%I64d",&n);
	for(ll i=1;i<=n;i++)
		scanf("%I64d",&a[i]);
	ll x;
	for(ll i=1;i<=n;i++)
	{
		scanf("%I64d",&x);
		a[i]=x-a[i];
	}
	for(ll i=2;i<=n;i++)
		scanf("%I64d%I64d",&p[i],&cost[i]);
	for(ll i=n;i>=2;i--)
	{
		if(a[i]>=INF) {puts("NO"); return 0;}
		if(a[i]<=0) a[p[i]]+=a[i];
		else a[p[i]]=min(INF,a[p[i]]+mul(a[i],cost[i]));
	}
	if(a[1]>0) puts("NO"); else puts("YES");
	return 0;
}