#include<bits/stdc++.h>
using namespace std;
bool check(int x)
{
	int w;
	static int vis[20];
	memset(vis,0,sizeof(vis));
	while(x>0)
	{
		w=x%10;
		if(vis[w]) return 0;
		vis[w]=1;x/=10;
	}
	return 1;
}
int main()
{
	int l,r,i;
	scanf("%d%d",&l,&r);
	for(i=l;i<=r;i++)
	{
		if(check(i)==1) 
		{
			printf("%d",i);
			return 0;
		}
	}
	puts("-1");
	return 0;
}