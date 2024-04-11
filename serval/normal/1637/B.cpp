#include <cstdio>
#include <algorithm>
using namespace std;
const int N=1e4+5;
int n;
int a[N];
int ans;
void solve()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	ans=0;
	for (int i=1;i<=n;i++)
	{
		ans+=i*(n-i+1);
		if (a[i]==0)
			ans+=i*(n-i+1);
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