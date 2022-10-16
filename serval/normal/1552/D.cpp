#include <cstdio>
using namespace std;
const int N=15;
const int C=1e6;
int t,n;
int a[N],p[C];
void solve()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	bool chk=0;
	for (int i=1;i<=n;i++)
	{
		int cnt=0;
		p[++cnt]=0;
		for (int j=1;j<=n;j++)
			if (i!=j)
			{
				int tmp=cnt;
				for (int k=1;k<=tmp;k++)
				{
					p[++cnt]=p[k]+a[j];
					p[++cnt]=p[k]-a[j];
				}
			}
		for (int j=1;j<=cnt;j++)
			chk|=(p[j]==a[i]);
	}
	if (chk)
		printf("YES\n");
	else
		printf("NO\n");
}
int main()
{
	scanf("%d",&t);
	while (t--)
		solve();
	return 0;
}