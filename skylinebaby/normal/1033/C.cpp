#include<bits/stdc++.h>
using namespace std;
int a[123456];
int b[123456];
int c[123456];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[a[i]] = i;
	}
	c[b[n]] = 0;
	for(int i = n-1;i>=1;i--)
	{
		for(int j = b[i]%i;j<=n;j+=i)
		{
			if(j==0) continue;
			if(a[j]<=i) continue;
			//printf("%d %d %d\n",i,j,c[j]);
			if(c[j]==0) c[b[i]] = 1;
		}
	}
	for(int i = 1;i<=n;i++)
	{
		if(c[i]==1) printf("A");
		else printf("B");
	}
	printf("\n");
	return 0;
}