#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 30
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,a[MAXN],b[MAXN];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=n;i++) scanf("%d",&b[i]);
		ll ans=0;
		for(int i=1;i<=n-1;i++)
		{
			int x=max(a[i]-a[i+1],a[i+1]-a[i])+max(b[i]-b[i+1],b[i+1]-b[i]);
			int y=max(a[i]-b[i+1],b[i+1]-a[i])+max(b[i]-a[i+1],a[i+1]-b[i]);
			ans+=min(x,y);
		}
		printf("%lld\n",ans);
	}
	return 0;
}