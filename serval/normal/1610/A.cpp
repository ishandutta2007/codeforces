#include <cstdio>
#include <algorithm>
using namespace std;
int T;
int n,m;
void solve()
{
	scanf("%d%d",&n,&m);
	if (n==1&&m==1)
	{
		printf("0\n");
		return;
	}
	printf("%d\n",min(2,min(n,m)));
}
int main()
{
	scanf("%d",&T);
	while (T--)
		solve();
	return 0;
}