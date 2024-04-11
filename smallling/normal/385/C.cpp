#include<cstdio>

#define maxn 10000001

using namespace std;

int i,j,k,l,m,n,o,p,a[maxn],b[maxn],c[maxn],r;

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&o);
		a[o]++;
	}
	for(i=2;i<maxn;i++)
	if(!b[i])
	{
		for(j=i;j<maxn;j+=i)
		{
			b[j]=1;
			c[i]+=a[j];
		}
	}
	for(i=2;i<maxn;i++)
	c[i]+=c[i-1];
	scanf("%d",&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&l,&r);
		if(l>=maxn){printf("0\n");continue;}
		if(r>=maxn)r=maxn-1;
		printf("%d\n",c[r]-c[l-1]);
	}
}