#include<bits/stdc++.h>
using namespace std;
int a[650];
int main()
{
	int n ;
	scanf("%d",&n);
	for(int i = 0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		a[x]=1;
	}
	int ans = 0;
	for(int i = 1;i<650;i++)
	{
		if (a[i]==1) ans ++;
	}
	printf("%d\n",ans);
	return 0;
}