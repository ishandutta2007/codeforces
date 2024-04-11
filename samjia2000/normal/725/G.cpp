#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<set>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef double db;
typedef long long LL;

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 2e5+5;
const int INF = 1e9;

int n,m;
int fa[N];
int lef[N],rig[N];
int dep[N];
struct initiator{
	int x,tim,val,id;
	initiator(const int x_=0,const int tim_=0,const int val_=0,const int id_=0){x=x_;tim=tim_;val=val_;id=id_;}
}key[N];

int siz[N],mx[N];
int dfn[N],k,R[N];
int d[N];
int be[N],u,tp[N];

void dfs1(int x){
	siz[x]=1;
	for(int y=lef[x];y;y=rig[y]){
		dep[y]=dep[x]+1;
		dfs1(y);
		siz[x]+=siz[y];
		if(!mx[x]||siz[y]>siz[mx[x]])mx[x]=y;
	}
}

void dfs2(int x){
	d[dfn[x]=++k]=x;
	if(!mx[x]){
		R[x]=k;
		tp[be[x]=++u]=x;
		return;
	}
	dfs2(mx[x]);
	tp[be[x]=be[mx[x]]]=x;
	for(int y=lef[x];y;y=rig[y])
	if (y!=mx[x])dfs2(y);
	R[x]=k;
}

int ans[N];

bool cmp(initiator a,initiator b){
	if (a.val!=b.val)return a.val<b.val;
	return a.id<b.id;
}

struct node{
	int l,r,val;
	int ad;
}tree[N*2];
int rt,tot;

void build(int &now,int l,int r){
	tree[now=++tot].val=-INF;
	tree[now].ad=-INF;
	if (l==r){
		if (l==1)tree[now].val=INF*2;
		return;
		
	}
	int mid=(l+r)/2;
	build(tree[now].l,l,mid);
	build(tree[now].r,mid+1,r);
	tree[now].val=max(tree[tree[now].l].val,tree[tree[now].r].val);
}

void down(int now,int l,int r){
	int mid=(l+r)/2;
	if (tree[now].ad!=-INF){
		tree[tree[now].l].ad=tree[tree[now].r].ad=tree[now].ad;
		tree[tree[now].l].val=tree[now].ad+dep[d[mid]]*2;
		tree[tree[now].r].val=tree[now].ad+dep[d[r]]*2;
		tree[now].ad=-INF;
	}
}

void change(int now,int l,int r,int x,int y,int v){
	if (x<=l&&r<=y){
		tree[now].ad=v;
		tree[now].val=v+dep[d[r]]*2;
		return;
	}
	down(now,l,r);
	int mid=(l+r)/2;
	if (x<=mid)change(tree[now].l,l,mid,x,y,v);
	if (y>mid)change(tree[now].r,mid+1,r,x,y,v);
	tree[now].val=max(tree[tree[now].l].val,tree[tree[now].r].val);
}

int getw(int now,int l,int r,int x,int y,int v){
	if (tree[now].val<=v)return -1;
	if (x<=l&&r<=y){
		if (l==r)return l;
		int mid=(l+r)/2;
		down(now,l,r);
		if (tree[tree[now].r].val>v)return getw(tree[now].r,mid+1,r,x,y,v);
		return getw(tree[now].l,l,mid,x,y,v);
	}
	int mid=(l+r)/2,ret=-1;
	down(now,l,r);
	if (y>mid)ret=getw(tree[now].r,mid+1,r,x,y,v);
	if (ret==-1&x<=mid)ret=getw(tree[now].l,l,mid,x,y,v);
	return ret;
}

int add(int x,int t){
	t+=dep[x];
	int now=x,px=x;
	while(now){
		int w=getw(1,1,n,dfn[tp[be[now]]],dfn[now],t);
		if (w!=-1){
			now=d[w];
			break;
		}
		now=fa[tp[be[now]]];
	}
	int ret=t-dep[now]+dep[x]-dep[now];
	int val=t-dep[now]*2;
	int to=now;
	now=x;
	while(now!=to){
		if (be[now]!=be[to]){
			change(1,1,n,dfn[tp[be[now]]],dfn[now],val);
			now=fa[tp[be[now]]];
		}
		else{
			change(1,1,n,dfn[to]+1,dfn[now],val);
			now=to;
		}
	}
	return ret;
}

int kth[N],tim[N],que[N],ul;
struct edge{
	int x,nxt;
}e[N];
int h[N],et;
int tmp[N],tl;

void inse(int x,int y){e[++et].x=y;e[et].nxt=h[x];h[x]=et;}

bool cmp2(int x,int y){return kth[x]<kth[y];}

int rearrange(int st,int l,int r){
	for(;l<=r&&dfn[que[l]]<=R[st];){
		inse(st,que[l]);
		l=rearrange(que[l],l+1,r);
	}
	tl=0;
	for(int p=h[st];p;p=e[p].nxt)tmp[++tl]=e[p].x;
	sort(tmp+1,tmp+1+tl);
	for(int p=h[st],t=1;p;p=e[p].nxt,t++)e[p].x=tmp[t];
	return l;
}

void rg(int x){
	if (x<=n)que[++ul]=x;
	for(int p=h[x];p;p=e[p].nxt)rg(e[p].x);
}

bool cmp1(int x,int y){return dfn[x]<dfn[y];}

int main(){
	n=get()+1;m=get();
	fo(i,2,n){
		fa[i]=get()+1;
		rig[i]=lef[fa[i]];
		lef[fa[i]]=i;
	}
	dep[1]=1;
	dfs1(1);
	dfs2(1);
	build(rt,1,n);
	fo(i,1,m){
		int x=get()+1,t=get();
		key[i]=initiator(x,t,dep[x]+t,i);
	}
	sort(key+1,key+1+m,cmp);
	int last=0;
	fo(i,1,m)
	if (i==m||key[i].val!=key[i+1].val){
		ul=et=0;
		fo(j,last+1,i){
			int x=key[j].x,t=key[j].tim;
			kth[x]=key[j].id,tim[x]=t;
			que[++ul]=x;
			h[x]=0;
		}
		sort(que+1,que+1+ul,cmp1);
		h[n+1]=0;
		R[n+1]=n+1;
		rearrange(n+1,1,ul);
		ul=0;
		rg(n+1);
		fo(j,1,ul){
			int x=que[j];
			ans[kth[x]]=add(x,tim[x]);
		}
		last=i;
	}
	fo(i,1,m)printf("%d%c",ans[i],i==m?'\n':' ');
	return 0;
}