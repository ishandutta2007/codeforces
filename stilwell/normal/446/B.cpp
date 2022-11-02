#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,m,K,p,i,j,k;
int a[1005][1005];
long long A[1005],B[1005],f[1000005],g[1000005],ans,tmp,tmpp;
int len;
long long heap[2000005];

void heap_up(int k)
{
	while((k!=1)&&(heap[k]>heap[k>>1]))
	tmp=heap[k],heap[k]=heap[k>>1],heap[k>>1]=tmp,k=k>>1;
}
void heap_insert(long long num)
{
	++len;heap[len]=num;
	heap_up(len);
}
void heap_down(int k)
{
	while((k<<1<=len)&&((heap[k<<1]>heap[k])||(heap[(k<<1)+1]>heap[k])))
	{
		k=k<<1;
		if((k+1<=len)&&(heap[k+1]>heap[k]))++k;
		tmp=heap[k];heap[k]=heap[k>>1];heap[k>>1]=tmp;
	}
}
void heap_delete()
{
	heap[1]=heap[len];--len;heap_down(1);
}

int main()
{
	scanf("%d%d%d%d",&n,&m,&K,&p);
	for(i=1;i<=n;++i)
	for(j=1;j<=m;++j)
	{
		scanf("%d",&a[i][j]);
		A[i]+=a[i][j];
		B[j]+=a[i][j];
	}
	for(i=1;i<=n;++i)heap_insert(A[i]);
	for(i=1;i<=K;++i)
	{
		tmpp=heap[1];
		f[i]=f[i-1]+tmpp;
		tmpp-=p*m;
		heap_delete();
		heap_insert(tmpp);
	}
	while(len)heap_delete();
	for(i=1;i<=m;++i)heap_insert(B[i]);
	for(i=1;i<=K;++i)
	{
		tmpp=heap[1];
		g[i]=g[i-1]+tmpp;
		tmpp-=p*n;
		heap_delete();
		heap_insert(tmpp);
	}
	ans=f[K];
	for(i=0;i<=K;++i)
	{
		tmp=f[i]+g[K-i]-((long long)i)*(K-i)*p;
		if(tmp>ans)ans=tmp;
	}
	printf("%I64d\n",ans);
}