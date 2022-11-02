#include<cmath>
#include<bitset>
#include<cstdio>
#include<algorithm>

#define N 3010

using namespace std;

struct lhy{
	int x,y,l;
}edge[N*N>>1];

int n,tot,x[N],y[N];
bitset<N>flag[N];

inline int cmp(const lhy &a,const lhy &b)
{
	return a.l>b.l;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&x[i],&y[i]);
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
			edge[++tot].x=i,edge[tot].y=j,edge[tot].l=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
	sort(edge+1,edge+1+tot,cmp);
	for(int i=1;i<=tot;i++)
	{
		if((flag[edge[i].x]&flag[edge[i].y])!=0)
		{
			printf("%.10lf",sqrt(edge[i].l)/2);
			return 0;
		}
		flag[edge[i].x][edge[i].y]=1;
		flag[edge[i].y][edge[i].x]=1;
	}
}