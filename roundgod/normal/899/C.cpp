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
	ll s=(1+n)*n/2;
	puts(s&1?"1":"0");
	printf("%I64d ",(n+1)/2);
	ll t=0;
	if(n&1)
	{
		printf("1 ");
		for(ll i=2;i<=n;i+=2)
		{
			if(t==0) printf("%I64d ",i); else printf("%I64d ",i+1);
			t=1-t;
		}
		return 0;
	}
	for(ll i=1;i<=n;i+=2)
	{
		if(t==0) printf("%I64d ",i); else printf("%I64d ",i+1);
		t=1-t;
	}
	return 0;
}