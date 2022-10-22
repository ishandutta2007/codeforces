#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		if(k==1)
		{
			puts("YES");
			for(int i=1;i<=n;i++)
				printf("%d\n",i);
			continue;
		}
		if(n&1)
			puts("NO");
		else
		{
			puts("YES");
			int x=1,y=2;
			for(int i=1;i<=n;i+=2)
			{
				for(int j=1;j<=k;j++)
					printf("%d ",x),x+=2;
				puts("");
				for(int j=1;j<=k;j++)
					printf("%d ",y),y+=2;
				puts("");
			}
		}
	}
	return 0;
}