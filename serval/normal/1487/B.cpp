#include <cstdio>
#include <algorithm>
using namespace std;
int t;
int n,k;
void solve()
{
	scanf("%d%d",&n,&k);
	if (n&1)
		printf("%d\n",(k+(k-1)/(n/2)-1)%n+1);
	else
		printf("%d\n",(k-1)%n+1);
}
int main()
{
	scanf("%d",&t);
	while (t--)
		solve();
	return 0;
}