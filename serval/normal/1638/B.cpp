#include <cstdio>
#include <algorithm>
using namespace std;
const int N=1e5+5;
int n;
int a[N];
void solve()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int o=0,e=0;
	for (int i=1;i<=n;i++)
	{
		if (a[i]&1)
		{
			if (o>a[i])
			{
				printf("No\n");
				return;
			}
			o=max(o,a[i]);
		}
		else
		{
			if (e>a[i])
			{
				printf("No\n");
				return;
			}
			e=max(e,a[i]);
		}
	}
	printf("Yes\n");
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
		solve();
	return 0;
}