#include<bits/stdc++.h>

using namespace std;

int a[33];

int dfs(int x,int y,int step)
{
	a[step]=x;
	if(x==y)
		return step;
	if(x<=(y>>1))
	{ 
		int h=dfs(x<<1,y,step+1);
		if(h)
		{
			return h;
		}
		else
		{
			if(x<=(y-1)/10)
			{
				int g=dfs(x*10+1,y,step+1);
				if(g)
				{
					return g;
				}
			}
			return 0;
		}
	}
	return 0;
	
}

int main()
{
	int x,y;
	cin>>x>>y;
	int q=dfs(x,y,0);
	if(q)
	{
		printf("YES\n%d\n",q+1);
		for(int i=0;i<=q;i++)
			printf("%d ",a[i]);
	}
	else
		printf("NO\n");
}