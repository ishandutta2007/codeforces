#include <cstdio>
#include <algorithm>
using namespace std;
int t;
int n;
void solve()
{
	scanf("%d",&n);
	int c=-1;
	for (int i=1;i<=n;i++)
	{
		for (int j=i+1;j<=n;j++)
			if ((n&1^1)&&i<=n/2&&j==i+n/2)
				printf("0 ");
			else
				printf("%d ",c=-c);
		if (n&1^1)
			c=-1;
	}
	printf("\n");
}
int main()
{
	scanf("%d",&t);
	while (t--)
		solve();
	return 0;
}