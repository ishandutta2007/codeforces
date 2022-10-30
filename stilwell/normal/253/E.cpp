#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <algorithm>
using namespace std;

int n,m,i,j,k;
int pc[50005],tot,l,r,mid;
long long t0,t1,t2,now,ans,tmp;
long long anst[50005];

struct node
{
	int t,s,p,id;
}t[50005];
inline bool cmpt(const node &a,const node &b){return a.t<b.t;}
inline bool cmpp(const node &a,const node &b){return a.p<b.p;}

int heap[100005],len;

void heap_up(int k)
{
	while((k!=1)&&(t[heap[k]].p>t[heap[k>>1]].p))
	swap(heap[k],heap[k>>1]),k=k>>1;
}
void heap_insert(int num)
{
	++len;heap[len]=num;
	heap_up(len);
}
void heap_down(int k)
{
	while((k<<1<=len)&&((t[heap[k<<1]].p>t[heap[k]].p)||(t[heap[(k<<1)+1]].p>t[heap[k]].p)))
	{
		k=k<<1;
		if((k+1<=len)&&(t[heap[k+1]].p>t[heap[k]].p))++k;
		swap(heap[k],heap[k>>1]);
	}
}
void heap_delete()
{
	heap[1]=heap[len];--len;heap_down(1);
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d%d%d",&t[i].t,&t[i].s,&t[i].p),t[i].id=i;
	scanf("%I64d",&t0);
	sort(t+1,t+n+1,cmpp);
	if(t[2].p!=1)pc[++tot]=1;
	for(i=2;i<=n;++i)
	if(i==n||t[i+1].p!=t[i].p+1)
	pc[++tot]=t[i].p+1;
	if(pc[tot]>1000000000)--tot;
	sort(t+1,t+n+1,cmpt);
	for(i=1;i<=n;++i)if(t[i].p==-1)m=i;
	l=1;r=tot;
	while(l<=r)
	{
		mid=l+r>>1;
		now=0;t1=t2=0;
		for(i=1;i<=n;++i)
		{
			tmp=t[i].t-now;
			if(t1<=tmp)now+=t1,tmp-=t1,t1=0;
			else t1-=tmp,now+=tmp,tmp=0;
			if(i>m)
			{
				if(t2<=tmp){ans=now+tmp;break;}
				else t2-=tmp;
			}
			now=t[i].t;
			if(i==m)t2=t[m].s;
			else
			{
				if(t[i].p>pc[mid])t1+=t[i].s;
			}
		}
		if(i>n)ans=now+t1+t2;
		if(ans==t0)break;
		if(ans<t0)r=mid-1;
		else l=mid+1;
	}
	t[m].p=pc[mid];
	now=0;
	for(i=1;i<=n;++i)
	{
		tmp=t[i].t-now;
		for(;tmp&&len;)
		{
			k=heap[1];
			if(t[k].s<=tmp)
			{
				tmp-=t[k].s;
				now+=t[k].s;
				anst[t[k].id]=now;
				heap_delete();
			}else t[k].s-=tmp,tmp=0,now+=tmp;
		}
		now=t[i].t;
		heap_insert(i);
	}
	for(;len;)
	{
		k=heap[1];
		now+=t[k].s;
		anst[t[k].id]=now;
		heap_delete();
	}
	printf("%d\n",pc[mid]);
	for(i=1;i<=n;++i)printf("%I64d ",anst[i]);
	printf("\n");
}