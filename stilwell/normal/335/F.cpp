#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,i,j,k,tot,cnt,rest;
int a[500005],b[500005];
int heap[1000005],len,tmp;
long long ans;

void heap_up(int k)
{
	while((k!=1)&&(heap[k]<heap[k>>1]))
	tmp=heap[k],heap[k]=heap[k>>1],heap[k>>1]=tmp,k=k>>1;
}
void heap_insert(int num)
{
	++len;heap[len]=num;
	heap_up(len);
}
void heap_down(int k)
{
	while((k<<1<=len)&&((heap[k<<1]<heap[k])||(heap[(k<<1)+1]<heap[k])))
	{
		k=k<<1;
		if((k+1<=len)&&(heap[k+1]<heap[k]))++k;
		tmp=heap[k];heap[k]=heap[k>>1];heap[k>>1]=tmp;
	}
}
void heap_delete()
{
	heap[1]=heap[len];--len;heap_down(1);
}

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",&a[i]),ans+=a[i];
	sort(a+1,a+n+1);a[0]=-1;
	for(i=n;i>=1;--i)
	{
		for(tot=1;a[i]==a[i-1];--i)++tot;
		for(;rest&&tot;--rest,--tot)b[++cnt]=a[i];
		for(;tot>=2&&len;tot-=2)
		{
			if(heap[1]>a[i])b[++cnt]=heap[1],b[++cnt]=2*a[i]-heap[1];
			else b[++cnt]=a[i],b[++cnt]=a[i];
			heap_delete();
		}
		if(tot&&len&&heap[1]<a[i])
		{
			heap_delete();
			b[++cnt]=a[i];
		}
		rest+=tot;
		for(;cnt;--cnt)heap_insert(b[cnt]);
	}
	while(len)
	{
		if(heap[1]>0)ans-=heap[1];
		heap_delete();
	}
	printf("%I64d\n",ans);
}