#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50;
int n;
int p[N],vis[N];
void Solve()
{
	int i,x,now;
	scanf("%d",&n);
	for(i=1;i<=n;i++) 
	{
		scanf("%d",&x);
		p[x]=i;
		vis[i]=0;
	}
	vis[n+1]=1;
	vis[p[1]]=1;now=p[1];
	for(i=2;i<=n;i++)
	{
		if(vis[now+1]!=1&&p[i]!=now+1)
		{
			puts("No");
			return ;
		}
		now=p[i];
		vis[p[i]]=1;
	}
	puts("Yes");
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--) Solve();
}