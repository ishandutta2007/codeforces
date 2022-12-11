#include<bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second

using namespace std;

typedef long long LL;
typedef double db;
typedef pair<int,int> pir;
typedef unsigned int ui;

ui seed;
ui getrand(){seed^=seed<<13;seed^=seed>>17;seed^=seed<<5;return seed;}

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

int n;
int fa[N*2];
struct node{
	int l,r,tot;
	LL sum,sumv;
	ui key;
	int val;
}tree[N];
int lef[N],rig[N];
int rt[N*2];
LL ans;
int tot;

int getfather(int x){return fa[x]==x?x:fa[x]=getfather(fa[x]);}

void update_ans(int x,LL v){
	ans=ans+v*(tree[rt[x]].sum+tree[rt[x]].sumv*(lef[x]-1));
}

void update(int now){
	int l=tree[now].l,r=tree[now].r;
	tree[now].tot=tree[l].tot+tree[r].tot+1;
	tree[now].sumv=tree[l].sumv+tree[r].sumv+tree[now].val;
	tree[now].sum=tree[l].sum+1ll*tree[now].val*(tree[l].tot+1)+tree[r].sum+tree[r].sumv*(tree[l].tot+1);
}

pir split(int now,int v){
	if (!now)return make_pair(0,0);
	if (tree[now].val>v){
		pir u=split(tree[now].r,v);
		tree[now].r=u.fi;
		update(now);
		return make_pair(now,u.se);
	}
	pir u=split(tree[now].l,v);
	tree[now].l=u.se;
	update(now);
	return make_pair(u.fi,now);
}

int merge(int x,int y){
	if (!x||!y)return x|y;
	if (tree[x].key<tree[y].key){
		tree[x].r=merge(tree[x].r,y);
		update(x);
		return x;
	}
	tree[y].l=merge(x,tree[y].l);
	update(y);
	return y;
}

void add(int x,int v,int id=0){
	if (!id)update_ans(x,-1);
	pir u=split(rt[x],v);
	int t=id;
	if(!id)t=++tot;
	tree[t].l=tree[t].r=0;
	tree[t].sum=tree[t].val=tree[t].sumv=v;
	tree[t].tot=1;
	tree[t].key=getrand();
	rt[x]=merge(u.fi,merge(t,u.se));
	if (!id)update_ans(x,1);
}

int que[N];
int id[N];
int k;

void getque(int now){
	if (!now)return;
	getque(tree[now].l);
	que[++k]=tree[now].val;
	id[k]=now;
	getque(tree[now].r);
}

void Merge(int x,int y){
	update_ans(x,-1);
	update_ans(y,-1);
	if (tree[rt[x]].tot<tree[rt[y]].tot){
		k=0;
		getque(rt[x]);
		fo(i,1,k)add(y,que[i],id[i]);
		lef[y]=lef[x];
		fa[x]=y;
		update_ans(y,1);
	}
	else{
		k=0;
		getque(rt[y]);
		fo(i,1,k)add(x,que[i],id[i]);
		rig[x]=rig[y];
		fa[y]=x;
		update_ans(x,1);
	}
}

int main(){
	seed=29382343;
	n=get();
	ans=0;
	fo(i,1,n){
		int x=get(),v=get();
		ans=ans-1ll*x*v;
		if(!fa[x]){
			fa[x]=x;
			lef[x]=rig[x]=x;
			add(x,v);
		}
		else{
			int y=getfather(x);
			fa[++rig[y]]=y;
			add(y,v);
		}
	//	printf("%d\n",tot);
		int y=getfather(x);
		if (fa[rig[y]+1])Merge(y,getfather(rig[y]+1));
		y=getfather(y);
		if (fa[lef[y]-1])Merge(getfather(lef[y]-1),y);
		printf("%I64d\n",ans);
	}
	return 0;
}