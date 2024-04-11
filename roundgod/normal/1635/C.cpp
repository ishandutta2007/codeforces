#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k;
ll a[MAXN];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		bool f=true;
		for(int i=1;i<=n-1;i++) if(a[i]>a[i+1]) f=false;
		if(f)
		{
			puts("0");
			continue;
		}
		if(a[n-1]>a[n])
		{
			puts("-1");
			continue;
		}
		if(a[n]>=0)
		{
			printf("%d\n",n-2);
			for(int i=n-2;i>=1;i--) printf("%d %d %d\n",i,i+1,n);
		}
		else puts("-1");
	}
	return 0;
}