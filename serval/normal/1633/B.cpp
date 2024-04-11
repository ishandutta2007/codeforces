#include <cstdio>
#include <algorithm>
using namespace std;
const int N=2e5+5;
char s[N];
int solve()
{
	scanf("%s",s+1);
	int c0=0,c1=0;
	for (int i=1;s[i];i++)
		if (s[i]=='0')
			c0++;
		else
			c1++;
	if (c0==0||c1==0)
		return 0;
	if (c0==c1)
		return c0-1;
	return min(c0,c1);
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
		printf("%d\n",solve());
	return 0;
}