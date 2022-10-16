#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int t;
int n;
void solve()
{
	scanf("%d",&n);
	printf("%d\n",((int)sqrt(2*n-1)-1)/2);
}
int main()
{
	scanf("%d",&t);
	while (t--)
		solve();
	return 0;
}