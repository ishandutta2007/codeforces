#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int r, n, i, j, x, y, b, mn = 2001;
	
	scanf("%d %d", &n, &b);

	r = b;

	while(n--)
	{
		scanf("%d",&x);
		
		if(mn!=2001)
		{
			int dollars = b/mn;
			r = max( r , b%mn + dollars*x);
		}

		mn = min(mn,x);
	}

	printf("%d\n",r);

	return 0;
}