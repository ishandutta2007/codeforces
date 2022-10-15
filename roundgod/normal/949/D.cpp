#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,d,b,a[MAXN],ans;
int main()
{
	ans=0;
	scanf("%I64d%I64d%I64d",&n,&d,&b);
	for(ll i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i]);
		a[i]+=a[i-1];
	}
	for(ll i=1;i<=(n+1)/2;i++)
		ans=max(ans,max(i-a[min(n,i*(d+1))]/b,i-(a[n]-a[max(0ll,n-i*(d+1))])/b));
	printf("%I64d\n",ans);
}