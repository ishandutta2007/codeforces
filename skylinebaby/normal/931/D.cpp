#include<bits/stdc++.h>
using namespace std;
int a[111111];
int b[111111];
int main()
{
	int n;
	scanf("%d",&n);
	a[1]=0;
	b[0]=1;
	int ans = 1;
	for(int i = 2;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		a[i]=a[x]+1;
		b[a[i]]=b[a[i]]^1;
		ans = ans + 2*b[a[i]]-1;
	}
	printf("%d\n",ans);
	return 0;
}