#include<bits/stdc++.h>
using namespace std;
int t,n,m,c,r,visc[51];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		memset(visc,0,sizeof(visc));
		c=r=0;
		for(int i=1;i<=n;i++)
		{
			bool flag=1;
			for(int l=1;l<=m;l++)
			{
				int a;
				scanf("%d",&a);
				if(a)
				{
					flag=0;
					visc[l]=1;
				}
			}
			r+=flag;	
		}
		for(int i=1;i<=m;i++)
			c+=(visc[i]^1);
		if(min(r,c)&1)
			puts("Ashish");
		else
			puts("Vivek");
	}
	return 0;
}