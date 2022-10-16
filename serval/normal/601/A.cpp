#include <cstdio>
using namespace std;
int n,m,i,j,k,u,v,p;
int mat[405][405];
int q[100005],ql,qr;
bool inq[405];
int dist[405];
int main()
{
	scanf("%d%d",&n,&m);
	for (i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		mat[u][v]=mat[v][u]=1;
	}
	p=mat[1][n]^1;
	for (i=1;i<=n;i++)
		dist[i]=2333;
	ql=1;
	qr=1;
	q[1]=1;
	inq[1]=1;
	dist[1]=0;
	while (ql<=qr)
	{
		for (i=1;i<=n;i++)
			if (mat[q[ql]][i]==p)
				if (dist[q[ql]]+1<=dist[i])
				{
					dist[i]=dist[q[ql]]+1;
					if (!inq[i])
					{
						inq[i]=1;
						qr++;
						q[qr]=i;
					}
				}
		inq[q[ql]]=0;
		ql++;
	}
	if (dist[n]==2333)
		printf("-1\n");
	else
		printf("%d\n",dist[n]);
	return 0;
}