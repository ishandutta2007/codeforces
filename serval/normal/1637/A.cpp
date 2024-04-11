#include <cstdio>
#include <algorithm>
using namespace std;
const int N=1e4+5;
int n;
int a[N];
void solve()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int mx=0;
	for (int i=1;i<=n;i++)
	{
		if (mx>a[i])
		{
			printf("YES\n");
			return;
		}
		mx=max(mx,a[i]);
	}
	printf("NO\n");
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
		solve();
	return 0;
}