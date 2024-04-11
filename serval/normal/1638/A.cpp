#include <cstdio>
using namespace std;
const int N=505;
int n;
int a[N];
void solve()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
		if (a[i]!=i)
		{
			for (int j=i;j<=n;j++)
				if (a[j]==i)
				{
					for (int l=i,r=j;l<r;l++,r--)
						a[l]^=a[r]^=a[l]^=a[r];
					break;
				}
			break;
		}
	for (int i=1;i<=n;i++)
		printf("%d%c",a[i]," \n"[i==n]);
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
		solve();
	return 0;
}