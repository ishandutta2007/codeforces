#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,U,a[MAXN];
int main()
{
	scanf("%I64d%I64d",&n,&U);
	for(ll i=1;i<=n;i++)
		scanf("%I64d",&a[i]);
	a[n+1]=2*INF;
	double ans=-1;
	for(ll i=1;i<=n-2;i++)
	{
		ll res=*(upper_bound(a+1,a+n+1,a[i]+U)-1);
		if(res<=a[i+1]) continue;
		ans=max(ans,(double)(res-a[i+1])/(res-a[i]));
	}
	if(ans<0) puts("-1"); else printf("%.10f\n",ans);
	return 0;
}