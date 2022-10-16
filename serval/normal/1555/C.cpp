#include <cstdio>
#include <algorithm>
using namespace std;
const int N=1e5+5;
int t;
int n;
int a[N],b[N];
int solve()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		a[i]+=a[i-1];
	}
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		b[i]+=b[i-1];
	}
	int ans=a[n]-a[1];
	for (int i=1;i<=n;i++)
		ans=min(ans,max(a[n]-a[i],b[i-1]));
	return ans;
}
int main()
{
	scanf("%d",&t);
	while (t--)
		printf("%d\n",solve());
	return 0;
}