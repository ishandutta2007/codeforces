#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,m,i,j,k,l,opt,u,v,ll,rr,tmp;
int Max1[800005],Max2[800005],id[400005],h[400005],ans[100005];
int heap[400005],len,st[15],top;

void heap_up(int k)
{
	while((k!=1)&&(heap[k]<heap[k>>1]))
	swap(heap[k],heap[k>>1]),k>>=1;
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
		swap(heap[k],heap[k>>1]);
	}
}
void heap_delete()
{
	heap[1]=heap[len];--len;heap_down(1);
}

int Q(int *Max,int x)
{
	int ans=0;x+=l-1;
	for(;x;x>>=1)if(!(x&1)&&Max[x+1]>ans)ans=Max[x+1];
	return ans+1;
}

void C(int *Max,int x,int y)
{
	Max[x+=l-1]=y;
	for(x>>=1;x;x>>=1)Max[x]=max(Max[x<<1],Max[x<<1|1]);
}

int main()
{
	scanf("%d%d",&n,&m);
	for(l=1;l<200000;l*=2);
	for(;m;--m)
	{
		scanf("%d",&opt);
		if(opt==1)
		{
			scanf("%d%d",&u,&v);
			id[v+=m]=u;h[u]=v;
			heap_insert(u);
			for(i=m;i<v;++i)if(id[i])C(Max1,id[i],0);
			for(i=v;i>=m;--i)
			if(id[i])
			{
				ans[id[i]]=Q(Max1,id[i]);
				C(Max1,id[i],ans[id[i]]);
				C(Max2,i,ans[id[i]]);
			}
		}
		else
		{
			scanf("%d",&u);
			for(;u;--u)
			{
				st[++top]=heap[1];
				heap_delete();
				C(Max2,h[st[top]],0);
			}
			C(Max1,st[top],0);ans[st[top]]=0;id[h[st[top]]]=0;
			for(--top;top;--top)
			{
				ans[st[top]]=Q(Max2,h[st[top]]);
				C(Max1,st[top],ans[st[top]]);
				C(Max2,h[st[top]],ans[st[top]]);
				heap_insert(st[top]);
			}
		}
		printf("%d\n",Max1[1]);
	}
}