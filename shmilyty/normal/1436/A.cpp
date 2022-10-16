#include<bits/stdc++.h>
using namespace std;
int t,n,m,a,sum;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		sum=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a);
			sum+=a;
		}
		if(sum==m)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}