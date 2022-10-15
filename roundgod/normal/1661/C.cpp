#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000000000000LL
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,a[MAXN];
ll ans;
ll check(int x)
{
	ll odd=0,even=0;
	for(int i=1;i<=n;i++)
	{
		int dif=x-a[i];
		if(dif&1) odd++;
		even+=dif/2;
	}
	if(even>odd)
	{
		ll need=(even-odd)/3;
		odd+=2*need; even-=need;
	}
	if(odd==even) return 2*odd;
	else if(odd>even) return 2*odd-1;
	else if(even==odd+1) return 2*even;
	else return 2*odd+3;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int maxi=0;
		for(int i=1;i<=n;i++) 
		{
			scanf("%d",&a[i]);
			maxi=max(maxi,a[i]);
		}
		ans=INF;
		ans=min(ans,check(maxi));
		ans=min(ans,check(maxi+1));
		printf("%lld\n",ans);
	}
	return 0;
}