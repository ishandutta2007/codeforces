#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,i,j,k,l,q;
int p[15][15],mid[15];
bool e[1005][1005];

int d[1005],f[1005];
int que[1005],r;

int main()
{
	scanf("%d",&m);
	n=2;
	for(i=1;i<=15;++i)mid[i]=++n;
	for(i=2;i<=15;++i)e[mid[i]][mid[i-1]]=true;
	e[mid[1]][2]=true;
	while(m)
	{
		
		j=m%10;
		++k;
		m/=10;
		if(!j)continue;
		for(i=1;i<=k;++i)
		for(l=1;l<=10;++l)
		p[i][l]=++n;
		for(i=1;i<k;++i)
		for(l=1;l<=10;++l)
		for(q=1;q<=10;++q)
		e[p[i][l]][p[i+1][q]]=true;
		for(i=1;i<=10;++i)e[1][p[1][i]]=true;
		for(i=1;i<=j;++i)e[p[k][i]][mid[15-k]]=true;
	}
	for(i=1;i<=n;++i)
	for(j=1;j<=n;++j)
	if(e[i][j])e[j][i]=true;
	printf("%d\n",n);
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)
		if(e[i][j])putchar('Y');else putchar('N');
		printf("\n");
	}
	
	/*que[1]=1;l=0;r=1;d[1]=1;
	while(l<r)
	{
		j=que[++l];
		for(i=1;i<=n;++i)
		if(e[j][i]&&!d[i])
		{
			d[i]=d[j]+1;
			que[++r]=i;
		}
	}
	f[1]=1;
	for(l=1;l<=r;++l)
	{
		i=que[l];
		for(j=1;j<=n;++j)
		if(e[i][j]&&d[i]+1==d[j])
		f[j]+=f[i];
	}
	printf("%d\n",f[2]);*/
	
}