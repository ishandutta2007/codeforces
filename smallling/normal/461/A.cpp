#include<cstdio>
#include<algorithm>

using namespace std;

int n,a[300010];
long long ans,sum;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),sum+=1ll*a[i];
	ans=sum;
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++)
		ans+=sum,sum-=1ll*a[i];
	printf("%I64d",ans);
}