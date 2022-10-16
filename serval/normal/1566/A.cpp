#include <cstdio>

using namespace std;

int T;

int n,s;
void solve()
{
	scanf("%d%d",&n,&s);
	int k=(n+1)/2;
	s/=n-(k-1);
	printf("%d\n",s);
}

int main()
{
	scanf("%d",&T);
	while (T--)
		solve();
	return 0;
}