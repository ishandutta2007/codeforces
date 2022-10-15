#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,k,a[MAXN];
int main()
{
	scanf("%I64d",&n);
	if(n<5)
	{
		printf("%d\n",n*(n-1)/2);
		return 0;
	}
	ll ans=0,now=5;
	while(n>=now*10)
		now=now*10;
	for(ll i=0;i<=8;i++)
	{
		ll res=i*now*2+now*2-1;
		if(n*2-1<res) break;
		ans+=min(res-1,n)-(i+1)*now+1;
	}
	printf("%I64d\n",ans);
	return 0;
}