#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int ans = -1;
	for(int i = 1;i*i<=n;i++)
	{
		if (n%i==0) ans += 2;
		if (i*i==n) ans -= 1;	
	}
	printf("%d\n",ans);
	return 0;
}