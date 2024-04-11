#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int a[4];
		scanf("%d%d%d%d",&a[0],&a[1],&a[2],&a[3]);
		sort(a,a + 4);
		printf("%d\n",a[0] * a[2]);
	}
	return 0;
}