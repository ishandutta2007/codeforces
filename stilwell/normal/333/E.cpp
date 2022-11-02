#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <bitset>
#include <algorithm>
using namespace std;

int n,i,j,k,tot;
int x[3005],y[3005];
double dist[3005][3005];
bitset<3005> f[3005];

struct node
{
	int u,v;
	double c;
}t[5000005];

double sqr(double x){return x*x;}
inline bool cmp(const node &a,const node &b){return a.c>b.c;}

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d%d",&x[i],&y[i]);
	for(i=1;i<=n;++i)
	for(j=1;j<=n;++j)
	if(i==j)dist[i][j]=-100000;
	else dist[i][j]=sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j]));
	for(i=1;i<=n;++i)
	for(j=i+1;j<=n;++j)
	{
		++tot;
		t[tot].u=i;
		t[tot].v=j;
		t[tot].c=dist[i][j];
	}
	sort(t+1,t+tot+1,cmp);
	for(i=1;i<=tot;++i)
	{
		j=t[i].u;k=t[i].v;
		if((f[j]&f[k]).any())
		{
			printf("%.20lf\n",t[i].c/2);
			return 0;
		}
		f[j][k]=1;f[k][j]=1;
	}
}