#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int w,l,a[MAXN],sum[MAXN];
int main()
{
	scanf("%d%d",&w,&l);
	int s=0,ans=2*INF;
	for(int i=1;i<=w-1;i++)
	{
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=l;i<=w-1;i++)
		ans=min(ans,sum[i]-sum[i-l]);
	printf("%d\n",ans);
	return 0;
}