#include<bits/stdc++.h>
#define ls (rt<<1)
#define rs ((rt<<1)|1)
using namespace std;
const int N=2e5+50,m=2e5+5;
int n,Q;
int a[N];
set<int> st[N];
struct Segment_tree
{
	int vmi[N<<2],lmx[N<<2],rmx[N<<2],mx[N<<2],sum[N<<2],tag[N<<2];
	void cover(int rt,int w)
	{
		vmi[rt]+=w;tag[rt]+=w;
	}
	void mdown(int rt)
	{
		cover(ls,tag[rt]);cover(rs,tag[rt]);
		tag[rt]=0;
	}
	void mup(int rt)
	{
		if(vmi[ls]==vmi[rs])
		{
			lmx[rt]=lmx[ls];rmx[rt]=rmx[rs];
			sum[rt]=sum[ls]+sum[rs]+max(rmx[ls],lmx[rs]);
		}
		else if(vmi[ls]<vmi[rs])
		{
			lmx[rt]=lmx[ls];rmx[rt]=max(mx[rs],rmx[ls]);
			sum[rt]=sum[ls];
		}
		else
		{
			rmx[rt]=rmx[rs];lmx[rt]=max(mx[ls],lmx[rs]);
			sum[rt]=sum[rs];
		}
		mx[rt]=max(mx[ls],mx[rs]);vmi[rt]=min(vmi[ls],vmi[rs]);
	}
	void chg(int rt,int l,int r,int x,int w)
	{
		if(l==r)
		{
			lmx[rt]=mx[rt]=w;return ;
		}
		int mid=(l+r)>>1;
		mdown(rt);
		if(mid>=x) chg(ls,l,mid,x,w);
		else chg(rs,mid+1,r,x,w);
		mup(rt);
	}
	void update(int rt,int l,int r,int x,int y,int w)
	{
		if(l>=x&&r<=y)
		{
			cover(rt,w);
			return ;
		}
		int mid=(l+r)>>1;
		mdown(rt);
		if(mid>=x) update(ls,l,mid,x,y,w);
		if(mid<y) update(rs,mid+1,r,x,y,w);
		mup(rt);
	}
}sgt;
void update(int col,int typ)
{
	if(st[col].empty()) return ;
	int siz=st[col].size();
	if(siz>1) sgt.update(1,1,n,*st[col].begin(),*st[col].rbegin()-1,typ);
	if(typ==-1) sgt.chg(1,1,n,*st[col].begin(),0);
	else sgt.chg(1,1,n,*st[col].begin(),siz);
}
int main()
{
	int i,pos,c;
	scanf("%d%d",&n,&Q);
	for(i=1;i<=n;i++) 
	{
		scanf("%d",&a[i]);
		st[a[i]].insert(i);
	}
	for(i=1;i<=m;i++) update(i,1);
	printf("%d\n",n-sgt.sum[1]-sgt.lmx[1]-sgt.rmx[1]);
	while(Q--)
	{
		scanf("%d%d",&pos,&c);
		update(a[pos],-1);
		st[a[pos]].erase(pos);
		update(a[pos],1);
		a[pos]=c;
		update(a[pos],-1);
		st[a[pos]].insert(pos);
		update(a[pos],1);
		printf("%d\n",n-sgt.sum[1]-sgt.lmx[1]-sgt.rmx[1]);
	}
	return 0;
}