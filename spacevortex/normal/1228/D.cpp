#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=3e5+20;
int n,m;
int col[N],a[10],b[10];
vector<int> e[N];
int main()
{
	int i,j,u,v,val,tag;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		e[u].pb(v);e[v].pb(u);
	}
	for(i=1;i<=n;i++)
	{
		memset(b,0,sizeof(b));
		for(int v:e[i])
		{
			if(col[v]==0) continue;
			b[col[v]]++;
		}
		val=-1;tag=0;
		for(j=1;j<=3;j++)
		{
			if(b[j]>0&&b[j]<a[j])
			{
				puts("-1");
				return 0;
			}
			if(b[j]==0)
			{
				if(a[j]>0)
				{
					if(tag)
					{
						puts("-1");
						return 0;
					}
					else tag=1,val=j;
				}
				else if(tag==0) val=j;
			}
		}
		if(val==-1) 
		{
			puts("-1");
			return 0;
		}
		a[val]++;
		col[i]=val;
		//printf("#%d %d\n",i,val);
	}
	if(a[1]==0||a[2]==0||a[3]==0)
	{
		puts("-1");
		return 0;
	}
	for(i=1;i<=n;i++) printf("%d ",col[i]);
	return 0;
}