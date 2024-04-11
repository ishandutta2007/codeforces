#include <cstdio>
#include <algorithm>
using namespace std;
const int N=2e5+5;
int n;
int a[N];
void solve()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int mx=0,ans=0;
	for (int i=1;i<=n;i++)
	{
		mx=max(mx,a[i]);
		if (mx==i)
			ans++;
	}
	printf("%d\n",ans);
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
		solve();
	return 0;
}