#include<cstdio>
#include<algorithm>

using namespace std;

int nowl,nowr;
int n,m,k,nowans,x;
int X[2020],Y[2020],D[2020][2020],ans[2020];
char s[2020][2020];

struct lhy{
	struct lnm{
		int min,max;
	}tree[8080];
	
	void build(int k,int l,int r)
	{
		if(l==r)
		{
			tree[k].min=2010;
			tree[k].max=0;
			return;
		}
		int mid=(l+r)>>1;
		build(k<<1,l,mid);
		build(k<<1|1,mid+1,r);
	}
	
	void add(int k,int l,int r,int ll,int o)
	{
		if(l==r)
		{
			tree[k].min=tree[k].max=o;
			return;
		}
		int mid=(l+r)>>1;
		if(mid>=ll)add(k<<1,l,mid,ll,o);
		else add(k<<1|1,mid+1,r,ll,o);
		tree[k].max=max(tree[k<<1].max,tree[k<<1|1].max);
		tree[k].min=min(tree[k<<1].min,tree[k<<1|1].min);
	}
	
	void getl(int k,int l,int r,int ll,int rr,int nowv)
	{
		if(nowl)return;
		if(tree[k].min>=nowv)return;
		if(l==r)
		{
			nowl=l;
			return;
		}
		int mid=(l+r)>>1;
		if(mid+1<=rr)getl(k<<1|1,mid+1,r,ll,rr,nowv);
		if(mid>=ll)getl(k<<1,l,mid,ll,rr,nowv);
	}
	
	void getr(int k,int l,int r,int ll,int rr,int nowv)
	{
		if(nowr)return;
		if(tree[k].min>=nowv)return;
		if(l==r)
		{
			nowr=r;
			return;
		}
		int mid=(l+r)>>1;
		if(mid>=ll)getr(k<<1,l,mid,ll,rr,nowv);
		if(mid+1<=rr)getr(k<<1|1,mid+1,r,ll,rr,nowv);
	}
}seg[2020];

int check(int now,int x,int nowAns)
{
	nowl=nowr=0;
	seg[now].getl(1,1,m,1,x,nowAns);
	if(!nowl)nowl=1;
	else nowl++;
	seg[now].getr(1,1,m,x+1,m,nowAns);
	if(!nowr)nowr=m;
	else nowr--;
	if(nowr-nowl+1>=nowAns)return 1;
	return 0;
}

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	for(int i=1;i<=k;i++)
	{
		scanf("%d%d",&X[i],&Y[i]);
		s[X[i]][Y[i]]='X';
	}
	for(int i=1;i<=n;i++)seg[i].build(1,1,m);
	for(int i=1;i<=m;i++)
		for(int j=n;j;j--)
			if(s[j][i]=='X')D[j][i]=0;
			else D[j][i]=D[j+1][i]+1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			seg[i].add(1,1,m,j,D[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			while(nowans<D[i][j]&&check(i,j,nowans+1))nowans++;
	for(int i=k;i;i--)
	{
		ans[i]=nowans;
		s[X[i]][Y[i]]='.';
		for(int j=X[i];j;j--)
		{
			if(s[j][Y[i]]=='X')D[j][Y[i]]=0;
			else D[j][Y[i]]=D[j+1][Y[i]]+1;
			seg[j].add(1,1,m,Y[i],D[j][Y[i]]);
			while(nowans<D[j][Y[i]]&&check(j,Y[i],nowans+1))nowans++;
		}
	}
	for(int i=1;i<=k;i++)printf("%d\n",ans[i]);
}