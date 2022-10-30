#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <map>
using namespace std;

map <int,int> Hash;

int n,m,i,j,k,l,ll,rr,lll,rrr,tot,cnt,col;
int val[1000005],a[1000005],f[100005],change[5000005],cover[5000005];
int done[100005],T;

struct node
{
	int l,r,h;
}t[100005];
inline bool cmp(const node &a,const node &b){return a.h>b.h;}

void downdata(int p)
{
	if(change[p])
	{
		change[p<<1]=change[p];cover[p<<1]=change[p];
		change[p<<1|1]=change[p];cover[p<<1|1]=change[p];
		change[p]=0;
	}
}

void update(int p)
{
	cover[p]=0;
	if(cover[p<<1])cover[p]=cover[p<<1];
	if(cover[p<<1|1])
	{
		if(cover[p])
		{
			if(cover[p<<1|1]!=cover[p])
			cover[p]=-1;
		}
		else cover[p]=cover[p<<1|1];
	}
}

bool check(int p,int l,int r)
{
	if(l>=lll&&r<=rrr)return cover[p]==col;
	int mid=l+r>>1;
	downdata(p);
	if(rrr<=mid)return check(p<<1,l,mid);
	else if(lll>mid)return check(p<<1|1,mid+1,r);
		else return check(p<<1,l,mid)&&check(p<<1|1,mid+1,r);
}

void work(int c)
{
	col=c;done[c]=T;
	lll=t[c].l;rrr=t[c].r;
	if(t[i].l>lll)lll=t[i].l;
	if(t[i].r<rrr)rrr=t[i].r;
	int tmp=min(f[c],val[rrr]-val[lll]+1);
	if(tmp<=f[i])return;
	if(check(1,1,l))f[i]=tmp;
}

void Q(int p,int l,int r)
{
	if(!cover[p])return;
	if(l>=ll&&r<=rr)
	{
		if(cover[p]>0)
		{
			if(done[cover[p]]==T)return;
			work(cover[p]);
			return;
		}
		int mid=l+r>>1;
		Q(p<<1,l,mid);
		Q(p<<1|1,mid+1,r);
		return;
	}
	int mid=l+r>>1;
	downdata(p);
	if(rr<=mid)Q(p<<1,l,mid);
	else if(ll>mid)Q(p<<1|1,mid+1,r);
		else Q(p<<1,l,mid),Q(p<<1|1,mid+1,r);
	update(p);
}

void C(int p,int l,int r)
{
	if(l>=ll&&r<=rr)
	{
		change[p]=cover[p]=col;
		return;
	}
	int mid=l+r>>1;
	downdata(p);
	if(rr<=mid)C(p<<1,l,mid);
	else if(ll>mid)C(p<<1|1,mid+1,r);
		else C(p<<1,l,mid),C(p<<1|1,mid+1,r);
	update(p);
}

int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)scanf("%d%d%d",&t[i].h,&t[i].l,&t[i].r),++t[i].l;
	++n;t[n].l=-1000000000;t[n].r=1000000000;t[n].h=m;
	++n;t[n].l=-1000000000;t[n].r=1000000000;t[n].h=0;
	for(i=1;i<=n;++i)a[++tot]=t[i].l,a[++tot]=t[i].r;
	sort(a+1,a+tot+1);
	for(i=1;i<=tot;++i)if(i==1||a[i]!=a[i-1])val[Hash[a[i]]=++cnt]=a[i];
	for(i=1;i<=n;++i)t[i].l=Hash[t[i].l],t[i].r=Hash[t[i].r];
	sort(t+1,t+n+1,cmp);
	f[1]=2000000000;
	for(l=1;l<cnt;l*=2);
	for(i=1;i<=n;++i)
	{
		++T;ll=t[i].l;rr=t[i].r;
		Q(1,1,l);
		col=i;
		C(1,1,l);
	}
	printf("%d\n",f[n]);
}