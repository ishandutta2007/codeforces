#include<bits/stdc++.h>
using namespace std;
int t,n,m,a,flag,vis[1001];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		memset(vis,0,sizeof(vis));
		flag=1;
		while(n--)
		{
			scanf("%d",&a);
			vis[a]=1;
		}
		while(m--)
		{
			scanf("%d",&a);
			if(!flag)
				continue;
			if(vis[a])
			{
				puts("YES");
				cout<<1<<" "<<a<<endl;
				flag=0;
			}
		}
		if(flag)
			puts("NO"); 
	}
	return 0;
}