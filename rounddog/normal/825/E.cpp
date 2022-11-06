#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define maxn 400005

using namespace std;

int h[maxn],next[maxn],d[maxn],rd[maxn],heap[maxn];
int n,m,p,ans[maxn],q,ord[maxn],tmp;
bool visit[maxn];

void add_edge(int x,int y)
{
	p++;
	next[p]=h[x];
	h[x]=p;
	d[p]=y;
	rd[y]++;
}

void swap(int x,int y)
{
	int tmp=heap[x];
	heap[x]=heap[y];
	heap[y]=tmp;
}

void heap_in(int x)
{
	visit[x]=false;
	p++;
	heap[p]=x;
    int t=p;
    while (t>1&&heap[t/2]<heap[t]){
    	swap(t,t/2);
    	t/=2;
    }
}

void heap_out()
{
	int t=heap[1];
	ord[q]=t;q--;swap(1,p);
	p--;
	int tt=1;tmp=0;
	bool f=true;
	while (f&&tt*2<=p){
		tmp=tt;
		if (tt*2<=p&&heap[tt*2]>heap[tmp]) tmp=tt*2;
		if (tt*2+1<=p&&heap[tt*2+1]>heap[tmp]) tmp=tt*2+1;
		if (tt!=tmp){
		    swap(tt,tmp);tt=tmp; 
		}else f=false;
	}
	//printf("%d\n",t);
	for (int i=h[t];i!=0;i=next[i])
	{
		rd[d[i]]--;
		if (visit[d[i]]&&rd[d[i]]==0) heap_in(d[i]);
	}
	
}

int main()
{
	scanf("%d%d",&n,&m);
	memset(h,0,sizeof(h));p=0;
	memset(rd,0,sizeof(rd));
	for (int i=0;i<m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(v,u);
	}
	p=0;q=n;
	memset(visit,true,sizeof(visit));
	memset(heap,0,sizeof(heap));
	for (int i=1;i<=n;i++)
	    if (rd[i]==0) heap_in(i);
    while (p) heap_out();
    for (int i=1;i<=n;i++) ans[ord[i]]=i;
    for (int i=1;i<n;i++) printf("%d ",ans[i]);
    printf("%d\n",ans[n]);
    return 0;
}