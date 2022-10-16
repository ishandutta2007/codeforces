#include <cstdio>
#include <algorithm>
using namespace std;
int solve()
{
	int v;
	scanf("%d",&v);
	if (v%7==0)
		return v;
	v-=v%10;
	for (int i=0;i<10;i++)
		if ((v+i)%7==0)
			return v+i;
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
		printf("%d\n",solve());
	return 0;
}