#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> V[300000];
int c[300000],d[300000],ex[300000],ey[300000],r[300000];
int i,j,k,m,n,s,t;

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	if (n==1)
	{
		if ((! m) && (! k))
			puts("1");
		else
			puts("-1");
		return 0;
	}
	d[0]=1;
	for (i=1;i<=m;i++)
		scanf("%d",&d[i]),c[i]=d[i];
	for (i=2;i<=m+1;i++)
		if (d[i-1]>d[i])
			t=t+d[i-1]-d[i],c[i-1]=d[i];
	if ((k<t) || (k>n-m))
		return puts("-1"),0;
	k=k-t;
	for (i=1;i<=m;i++)
		if (k>=c[i])
			r[i]=c[i]-1,k=k-c[i]+1;
		else
			if (k>0)
				r[i]=k,k=0;
	t=1,V[0].push_back(t);
	for (i=1;i<=m;i++)
		for (j=1;j<=d[i];j++)
			t++,V[i].push_back(t);
	for (i=1;i<=m;i++)
	{
		for (j=0;j<c[i-1]-r[i-1];j++)
			s++,ex[s]=V[i][j],ey[s]=V[i-1][j];
		for (j=c[i-1]-r[i-1];j<d[i];j++)
			s++,ex[s]=V[i][j],ey[s]=V[i-1][0];
	}
	printf("%d\n",n);
	for (i=1;i<=s;i++)
		printf("%d %d\n",ex[i],ey[i]);
	return 0;
}