#include<bits/stdc++.h>
using namespace std;
int t,n,a[300001];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		if(a[1]>a[n])
			puts("NO");
		else
			puts("YES");
	}
	return 0;
}