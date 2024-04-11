#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,m,h,i,j,k,ans;
int a[200005],b[200005];
int BST[200005],bst[200005],l[200005],r[200005],fa[200005],size[200005],st[200005],root,tot;
int add[200005],Min[200005];

void splay_updata(int x)
{
	Min[x]=bst[x];
	if(l[x]&&Min[l[x]]<Min[x])Min[x]=Min[l[x]];
	if(r[x]&&Min[r[x]]<Min[x])Min[x]=Min[r[x]];
	size[x]=size[l[x]]+size[r[x]]+1;
}

void zig(int x)
{
	int y=fa[x],z=fa[y];
	if(l[z]==y)l[z]=x;else r[z]=x;
	fa[x]=z,fa[y]=x,fa[r[x]]=y;
	l[y]=r[x],r[x]=y;
	splay_updata(y);
}

void zag(int x)
{
	int y=fa[x],z=fa[y];
	if(l[z]==y)l[z]=x;else r[z]=x;
	fa[x]=z,fa[y]=x,fa[l[x]]=y;
	r[y]=l[x];l[x]=y;
	splay_updata(y);
}

void Add(int x,int y)
{
	bst[x]+=y;
	Min[x]+=y;
	add[x]+=y;
}

void splay_down(int x)
{
	if(add[x])
	{
		if(l[x])Add(l[x],add[x]);
		if(r[x])Add(r[x],add[x]);
		add[x]=0;
	}
}

void splay(int x)
{
	int y,z;
	y=x;z=1;st[1]=x;
	while(fa[y])
	{
		++z;
		y=fa[y];
		st[z]=y;
	}
	for(y=z;y>=1;--y)splay_down(st[y]);
	while(fa[x])
	{
		y=fa[x],z=fa[y];
		if((z)&&(y!=root))
		{
			if(l[z]==y){if(l[y]==x)zig(y),zig(x);else zag(x),zig(x);}
			else{if(l[y]==x)zig(x),zag(x);else zag(y),zag(x);}
		}
		else{if(l[y]==x)zig(x);else zag(x);}
	}
	root=x;
	splay_updata(root);
}

void splay_delete(int x)
{
	int y;
	splay(x);
	if(r[x]==0)
	{
		if(l[x]==0){root=0;return;}
		else root=l[x],fa[root]=0;
	}
	else
	{
		if(l[x]==0)root=r[x],fa[root]=0;
		else
		{
			y=r[x];r[x]=0;fa[y]=0;
			while(l[y])y=l[y];
			splay(y);
			l[y]=l[x];fa[l[y]]=y;
			splay_updata(root);
		}
	}
}

void BST_insert(int num)
{
	int x;
	if(!root){++tot;BST[tot]=num,root=tot;size[tot]=1;return;}
	x=root;
	while(true)
	{
		splay_down(x);
		++size[x];
		if(num>BST[x])
		{
			if(r[x]==0){++tot;BST[tot]=num;fa[tot]=x;r[x]=tot;size[tot]=1;break;}
			else x=r[x];
		}
		else
		{
			if(l[x]==0){++tot;BST[tot]=num;fa[tot]=x;l[x]=tot;size[tot]=1;break;}
			else x=l[x];
		}
	}
}

int calc(int x)
{
	int l=1,r=m,mid,ans=0;
	while(l<=r)
	{
		mid=l+r>>1;
		if(x+b[mid]>=h)ans=mid,l=mid+1;
		else r=mid-1;
	}
	return ans;
}

void Ins(int x)
{
	bst[x]=Min[x]=n+1;
	BST_insert(a[x]);
	splay(x);
	bst[x]=calc(a[x]);
	bst[x]-=size[l[x]]+1;
	if(r[x])Add(r[x],-1);
	splay_updata(x);
}

void Del(int x)
{
	if(!x)return;
	splay(x);
	if(r[x])Add(r[x],1);
	splay_delete(x);
}

int main()
{
	scanf("%d%d%d",&n,&m,&h);
	for(i=1;i<=m;++i)scanf("%d",&b[i]);
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	for(i=1;i<=m;++i)b[i]=-b[i];
	sort(b+1,b+m+1);
	for(i=1;i<=m;++i)b[i]=-b[i];
	for(i=1;i<m;++i)Ins(i);
	for(i=m;i<=n;++i)
	{
		Del(i-m);
		Ins(i);
		if(Min[root]>=0)++ans;
	}
	printf("%d\n",ans);
}