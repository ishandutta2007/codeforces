#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int get(){
	char ch;
	int s=0;
	while(ch=getchar(),ch<'0'||ch>'9');
	s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 1e+5+10;

int dfn[N],low[N],sta[N],top,k,u;//k for u for dfn
bool istop[N];
int n,m,q;
int h[N],tot,st[N];
struct edge{
	int x,next,p;
}e[N*4];
int root[N],tt,size[N],be[N],v[N],num[N],son[N];
int w[N];
struct point{
	int v,l,r;
}tree[N*4];
int ma[N],bl[N],fa[N],d[N],l[N],dep[N],up[N],td[N];
bool pd[N];

void inse(int x,int y,int &st){
	e[++tot].x=y;
	e[tot].next=st;
	st=tot;
}

void inse1(int x,int y,int &st,int p){
	e[++tot].x=y;
	e[tot].next=st;
	e[tot].p=p;
	st=tot;	
}

void build1(int &now,int l,int r){
	now=++tt;
	if (l==r){
		tree[now].v=w[l];
		return;
	}
	int mid=(l+r)/2;
	build1(tree[now].l,l,mid);
	build1(tree[now].r,mid+1,r);
	tree[now].v=min(tree[tree[now].l].v,tree[tree[now].r].v);
}

void build2(int &now,int l,int r){
	now=++tt;
	if (l==r){
		tree[now].v=tree[root[d[l]]].v;
		return;
	}
	int mid=(l+r)/2;
	build2(tree[now].l,l,mid);
	build2(tree[now].r,mid+1,r);
	tree[now].v=min(tree[tree[now].l].v,tree[tree[now].r].v);
}

void change(int now,int l,int r,int x,int v){
	if (l==r){
		tree[now].v=v;
		return;
	}
	int mid=(l+r)/2;
	if (x<=mid)change(tree[now].l,l,mid,x,v);
	else change(tree[now].r,mid+1,r,x,v);
	tree[now].v=min(tree[tree[now].l].v,tree[tree[now].r].v);
}

int getv(int now,int l,int r,int x,int y){
	if (l>=x&&r<=y)return tree[now].v;
	int mid=(l+r)/2,ans=1e+9;
	if (x<=mid)ans=min(ans,getv(tree[now].l,l,mid,x,y));
	if (y>mid)ans=min(ans,getv(tree[now].r,mid+1,r,x,y));
	return ans;
}

void tarjan(int x,int fa){
	low[x]=dfn[x]=++u;
	sta[++top]=x;
	for(int p=h[x];p;p=e[p].next)
		if (e[p].x!=fa){
			if (!dfn[e[p].x]){
				tarjan(e[p].x,x);
				low[x]=min(low[x],low[e[p].x]);
			}
			else low[x]=min(low[x],dfn[e[p].x]);
		}
	if (low[x]==dfn[x]||low[x]==dfn[fa]||x==1){
		up[be[x]=++k]=fa;
		w[size[k]=1]=v[x];
		num[x]=1;
		while(sta[top]!=x){
			w[++size[k]]=v[sta[top]];
			num[sta[top]]=size[k];
			be[sta[top--]]=k;
		}
		build1(root[k],1,size[k]);//build--->tt
		top--;
	}
}

void dfs1(int x){
	pd[x]=1;
	son[x]=1;
	for(int p=st[x];p;p=e[p].next)
	if (!pd[e[p].x]){
		td[e[p].x]=e[p].p;
		dfs1(e[p].x);
		son[x]+=son[e[p].x];
		fa[e[p].x]=x;
		if (!ma[x]||son[e[p].x]>son[ma[x]])ma[x]=e[p].x;
	}
}

void dfs2(int x){
	d[dfn[x]=++k]=x;
	for(int p=st[x];p;p=e[p].next)
		if(fa[e[p].x]==x)dep[e[p].x]=dep[x]+1;
	if (ma[x]){
		dfs2(ma[x]);
		l[bl[x]=bl[ma[x]]]=x;
		for(int p=st[x];p;p=e[p].next)
			if (fa[e[p].x]==x&&e[p].x!=ma[x]&&!dfn[e[p].x])dfs2(e[p].x);
	}
	else l[bl[x]=++u]=x;
}

int rt;

int getfather(int x,int y){
	if (dep[x]<dep[y])swap(x,y);
	while(bl[x]!=bl[y]){
		if (dep[l[bl[x]]]>dep[l[bl[y]]])x=fa[l[bl[x]]];
		else y=fa[l[bl[y]]];
	}
	if (dep[x]>dep[y])swap(x,y);
	return x;
}

int getans(int x,int f){
	int ans=1e+9;
	while(dep[x]>dep[f]){
		if (dep[l[bl[x]]]>dep[f]){
			ans=min(ans,getv(rt,1,k,dfn[l[bl[x]]],dfn[x]));
			x=fa[l[bl[x]]];
		}
		else{
			ans=min(ans,getv(rt,1,k,dfn[f]+1,dfn[x]));
			x=fa[f];
		}
	}
	return ans;
}

int jump(int x,int f){
	while(dep[l[bl[x]]]>dep[f]+1)x=fa[l[bl[x]]];
	x=d[dfn[x]-(dep[x]-dep[f]-1)];
	return td[x];
}

void work(){
	fo(i,1,q){
		char ch;
		while(ch=getchar(),ch!='C'&&ch!='A');
		if (ch=='A'){
			int x=get(),y=get();
			if (x==y){
				printf("%d\n",v[x]);
				continue;
			}
			if (be[x]==be[y]){
				printf("%d\n",min(tree[root[be[x]]].v,v[up[be[x]]]));
				continue;
			}
			int tf=getfather(be[x],be[y]);
			int ans=0;
			if (be[y]==tf)swap(x,y);
			if (be[x]==tf){
				ans=getans(be[y],tf);
				if (x!=jump(be[y],tf))ans=min(ans,min(tree[root[tf]].v,v[up[tf]]));
				else ans=min(ans,v[x]);
				printf("%d\n",ans);
				continue;
			}
			ans=min(getans(be[x],tf),getans(be[y],tf));
			int tx=jump(be[x],tf),ty=jump(be[y],tf);
			if (tx==ty)ans=min(ans,v[tx]);
			else ans=min(ans,min(tree[root[tf]].v,v[up[tf]]));
			printf("%d\n",ans);
		}
		else{
			int x=get(),w=get();
			change(root[be[x]],1,size[be[x]],num[x],w);
			v[x]=w;
			change(rt,1,k,dfn[be[x]],tree[root[be[x]]].v);
		}
	}
}

int main(){
	n=get();m=get();q=get();
	fo(i,1,n)v[i]=get();
	fo(i,1,m){
		int x=get(),y=get();
		inse(x,y,h[x]);
		inse(y,x,h[y]);
	}
	tarjan(1,0);
	fo(i,1,n){
		for(int p=h[i];p;p=e[p].next)
			if (be[e[p].x]!=be[i])inse1(be[i],be[e[p].x],st[be[i]],i);
	}
	k=u=0;
	dfs1(be[1]);
	fo(i,1,n)dfn[i]=0;
	dfs2(be[1]);
	build2(rt,1,k);//tt for point
	work();
	return 0;
}