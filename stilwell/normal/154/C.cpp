#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,m,i,j,k,u,v,tot,x[1000005],y[1000005];
unsigned long long a[1000005],Hash[1000005],ans;
int id[1000005];

inline bool cmp(const int &x,const int &y){return a[x]<a[y];}

int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)Hash[i]=rand()%10000+rand()%10000ll*10000ll+rand()%10000*100000000ll;
	for(i=1;i<=m;++i)
	{
		scanf("%d%d",&u,&v);
		a[u]^=Hash[v];
		a[v]^=Hash[u];
		x[i]=u;y[i]=v;
	}
	for(i=1;i<=n;++i)id[i]=i;
	sort(id+1,id+n+1,cmp);
	tot=0;
	for(i=2;i<=n;++i)
	{
		if(a[id[i]]!=a[id[i-1]])tot=0;else ++tot;
		ans+=tot;
	}
	for(i=1;i<=m;++i)
	if((a[x[i]]^Hash[x[i]])==(a[y[i]]^Hash[y[i]]))
	++ans;
	printf("%I64u\n",ans);
}