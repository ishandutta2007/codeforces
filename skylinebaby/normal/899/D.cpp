#include<bits/stdc++.h>
using namespace std;
main()
{
	int n;
	scanf("%d",&n);
	int m = (int)log10(2*n+0.5);
	int x = (int)(pow(10,m)+0.5);
	int s = n/x;
	int t = n%x;
	int ans = (x/2)*s*s;
	if (t*2>=x)
	{
		ans += (t-x/2+1)*(s+1);
		if (t+1==x) ans--;
		ans += (x/2-1)*s;
	}
	else 
	{
		ans += t*s;
	}
	if (n<=4) ans += (n*(n-1))/2;
	printf("%d\n",ans);
	return 0;
}