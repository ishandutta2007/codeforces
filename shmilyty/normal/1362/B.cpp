#include<bits/stdc++.h>
using namespace std;
int b[1030][1030],a[1030];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			for(int j=1;j<=1024;j++)
				b[j][i]=a[i]^j;
		}
		for(int i=1;i<=1024;i++)
			sort(b[i]+1,b[i]+n+1);
		sort(a+1,a+n+1);
		int tag=0;
		for(int i=1;i<=1024;i++)
		{
			int flag=0;
			for(int j=1;j<=n;j++)
				if(b[i][j]!=a[j])
				{
					flag=1;
					break;
				}
			if(flag==0)
			{
				printf("%d\n",i);
				tag=1;
				break;
			}
		}
		if(tag==0)
			printf("-1\n");
	}
	return 0;
}