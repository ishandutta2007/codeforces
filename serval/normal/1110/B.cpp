#include <cstdio>
#include <algorithm>
using namespace std;
const int N=100005;
int n,m,k;
int a[N],b[N];
long long ans;
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	ans=n;
	for (int i=1;i<n;i++)
		b[i]=a[i+1]-a[i]-1;
	sort(b+1,b+n);
	for (int i=1;i<=n-k;i++)
		ans+=b[i];
	printf("%lld\n",ans);
	return 0;
}