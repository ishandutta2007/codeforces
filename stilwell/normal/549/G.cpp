#include <stdio.h>
#include <stdlib.h>
using namespace std;

int BST[300005],l[300005],r[300005],fa[300005],size[300005],add[300005],st[300005],root,tot;

void splay_updata(int x)
{
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

void splay_down(int x)
{
	if(add[x])
	{
		if(l[x])BST[l[x]]+=add[x],add[l[x]]+=add[x];
		if(r[x])BST[r[x]]+=add[x],add[r[x]]+=add[x];
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

void BST_insert(int num)
{
	int x;
	if(!root){++tot;BST[tot]=num,root=tot;size[tot]=1;return;}
	x=root;
	while(true)
	{
		splay_down(x);
		++size[x];
		if(num-size[l[x]]>BST[x])
		{
			++BST[x];if(l[x])++BST[l[x]],++add[l[x]];
			num-=size[l[x]]+1;
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

int n,i,j,k;
int a[300005];

void dfs(int x)
{
	splay_down(x);
	if(l[x])dfs(l[x]);
	a[++tot]=BST[x];
	if(r[x])dfs(r[x]);
}

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	for(i=n;i>=1;--i)
	{
		BST_insert(a[i]);
		splay(tot);
		if(l[root])
		{
			for(j=l[root];r[j];j=r[j])splay_down(j);
			if(BST[j]>BST[root]){printf(":(\n");return 0;}
		}
		if(r[root])
		{
			for(j=r[root];l[j];j=l[j])splay_down(j);
			if(BST[j]<BST[root]){printf(":(\n");return 0;}
		}
	}
	tot=0;
	dfs(root);
	for(i=1;i<n;++i)if(a[i]>a[i+1]){printf(":(\n");return 0;}
	for(i=1;i<=n;++i)printf("%d ",a[i]);
	printf("\n");
}