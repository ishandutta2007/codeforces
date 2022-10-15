#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,a,b;
int x[MAXN];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&a,&b);
		for(int i=1;i<=n;i++) scanf("%d",&x[i]);
		ll ans=0;
		for(int i=1;i<=n;i++) ans+=1LL*x[i]*b;
		for(int i=1;i<=n;i++)
			ans-=1LL*(x[i]-x[i-1])*max(0LL,1LL*b*(n-i)-a);
		printf("%lld\n",ans);
	}
	return 0;
}