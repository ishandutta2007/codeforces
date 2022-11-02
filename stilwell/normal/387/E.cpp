#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,i,j,k;
int a[1000005],b[1000005],l[1000005],r[1000005];
int L[1000005],R[1000005],sum[1000005];
long long ans;
bool del[1000005];

int getl(int x){return l[x]==x?x:l[x]=getl(l[x]);}
int getr(int x){return r[x]==x?x:r[x]=getr(r[x]);}

int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)scanf("%d",&a[i]),b[a[i]]=i;
	for(i=1;i<=n;++i)del[i]=true;
	for(i=1;i<=m;++i)scanf("%d",&k),del[k]=false;
	for(i=0;i<=n+1;++i)l[i]=r[i]=i;
	for(i=1;i<=n;++i)
	if(del[i])
	{
		k=b[i];
		l[k]=k-1;
		r[k]=k+1;
	}
	for(i=n;i>=1;--i)
	{
		k=b[i];
		L[i]=getl(k);
		R[i]=getr(k);
		if(!del[i])
		{
			l[k]=k-1;
			r[k]=k+1;
		}
	}
	++n;
	for(i=1;i<n;++i)
	for(j=i;j<=n;j+=j&-j)
	++sum[j];
	for(i=1;i<n;++i)
	if(del[i])
	{
		for(j=R[i]-1;j>=1;j-=j&-j)ans+=sum[j];
		for(j=L[i];j>=1;j-=j&-j)ans-=sum[j];
		for(j=b[i];j<=n;j+=j&-j)--sum[j];
	}
	printf("%I64d\n",ans);
}