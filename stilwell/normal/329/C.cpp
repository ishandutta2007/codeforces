#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,m,i,j,k,u,v,tot,shi,_shi;
int ban[100005][3],id[100005];

int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i)
	{
		scanf("%d%d",&u,&v);
		if(ban[u][1])ban[u][2]=v;else ban[u][1]=v;
		if(ban[v][1])ban[v][2]=u;else ban[v][1]=u;
	}
	for(i=1;i<=n;++i)id[i]=i;
	_shi=10000000/n;
	for(shi=0;shi<=100;++shi)
	{
		random_shuffle(id+1,id+n+1);
		id[n+1]=id[1];tot=0;
		for(i=1;i<=n;++i)
		{
			u=id[i];v=id[i+1];
			if(v!=ban[u][1]&&v!=ban[u][2])++tot;
		}
		if(tot>=m)
		{
			for(i=1;i<=n;++i)
			{
				u=id[i];v=id[i+1];
				if(v!=ban[u][1]&&v!=ban[u][2])
				{
					printf("%d %d\n",u,v);
					--m;if(!m)return 0;
				}
			}
		}
	}
	printf("-1\n");
}