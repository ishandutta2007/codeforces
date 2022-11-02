#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,m,K,i,j,k,u,v,c,cc,tot,S1,S2,T;
int son[10005],from[20005],next[20005],ed[20005],cost[20005],costt[20005];
bool inq[10005];

int root;
struct Heap
{
	long long key;
	int l,r,fa,p;
	bool visit,inheap;
}heap[10005];

int heap_merge(int A,int B)
{
	if(!A)return B;if(!B)return A;
    if(heap[A].key>heap[B].key)swap(A,B);
    heap[A].r=heap_merge(heap[A].r,B);
    heap[heap[A].r].fa=A;
    swap(heap[A].l,heap[A].r);
    return A;
}

inline void heap_delete(int A)
{
	int q=heap[A].fa,p=heap_merge(heap[A].l,heap[A].r);
	heap[p].fa=q;heap[A].l=heap[A].r=heap[A].fa=0;
	if(q==0){root=p;return;}
	if(heap[q].l==A)heap[q].l=p;else heap[q].r=p;
	swap(heap[q].l,heap[q].r);
}

void Dijkstra()
{
	int l,i,id;long long Dist,d;
	for(i=1;i<=n;++i)heap[i].key=100000000000000ll;
	heap[S1].inheap=true;heap[S1].key=0;heap[S1].p|=1;root=S1;
	heap[S2].inheap=true;heap[S2].key=0;heap[S2].p|=2;if(S2!=root)root=heap_merge(root,S2);
	while(!heap[T].visit)
	{
		Dist=heap[root].key;id=root;heap[id].visit=true;
		root=heap_merge(heap[root].l,heap[root].r);
		heap[root].fa=0;
		for(l=son[id];l;l=next[l])
		{
			if(l>m&&heap[id].p/2)d=Dist+costt[l];
			else d=Dist+cost[l];
			if(d<=heap[ed[l]].key)
			{
				if(d==heap[ed[l]].key)heap[ed[l]].p|=heap[id].p;
				else heap[ed[l]].p=heap[id].p;
				heap[ed[l]].key=d;
				if(!heap[ed[l]].inheap)
				{
					heap[ed[l]].inheap=true;
					root=heap_merge(root,ed[l]);
				}
				else
				{
					heap_delete(ed[l]);
					root=heap_merge(root,ed[l]);
				}
			}
		}
	}
}

int main()
{
	scanf("%d%d%d",&n,&m,&K);
	scanf("%d%d%d",&S1,&S2,&T);
	for(i=1;i<=m;++i)
	{
		scanf("%d%d%d",&u,&v,&c);
		++tot;from[tot]=u;next[tot]=son[u];son[u]=tot;ed[tot]=v;cost[tot]=c;
	}
	for(i=1;i<=K;++i)
	{
		scanf("%d%d%d%d",&u,&v,&c,&cc);
		++tot;from[tot]=u;next[tot]=son[u];son[u]=tot;ed[tot]=v;cost[tot]=c;costt[tot]=cc;
	}
	Dijkstra();
	if(heap[T].p==1)printf("WIN\n");
	if(heap[T].p==2)printf("LOSE\n");
	if(heap[T].p==3)printf("DRAW\n");
	if(heap[T].p!=2)
	{
		for(i=m+1;i<=m+K;++i)
		if(heap[from[i]].p/2)printf("%d ",costt[i]);
		else printf("%d ",cost[i]);
		printf("\n");
	}
}