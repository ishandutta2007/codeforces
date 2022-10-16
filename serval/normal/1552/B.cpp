#include <cstdio>
#include <algorithm>
using namespace std;
const int N=50005;
int t;
int n,mn;
int v[5][N];
bool lss(int a,int b)
{
	int c=0;
	for (int i=0;i<5;i++)
		if (v[i][a]<v[i][b])
			c++;
	return c>=3;
}
void solve()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		for (int j=0;j<5;j++)
			scanf("%d",&v[j][i]);
	mn=1;
	for (int i=2;i<=n;i++)
		if (lss(i,mn))
			mn=i;
	int c=0;
	for (int i=1;i<=n;i++)
		if (lss(mn,i))
			c++;
	if (c==n-1)
		printf("%d\n",mn);
	else
		printf("-1\n");
}
int main()
{
	scanf("%d",&t);
	while (t--)
		solve();
	return 0;
}