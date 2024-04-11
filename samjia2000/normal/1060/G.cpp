#include<bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second

using namespace std;

typedef long long LL;
typedef double db;
typedef unsigned int ui;
typedef pair<int,int> pir;

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

const int N = 1e5+5;

int n,m;
LL a[N],start;
LL st[N];
struct treap_node{
	ui key;
	int l,r,tot;
	
	void init(){
		key=getrand();
		tot=1;
		l=r=0;
	}
}treap[N];
int rt;

void update(int now){treap[now].tot=treap[treap[now].l].tot+treap[treap[now].r].tot+1;}

pir split(int now,int k){
	if (!k||!now)return make_pair(0,now);
	if (k>=treap[treap[now].l].tot+1){
		pir u=split(treap[now].r,k-treap[treap[now].l].tot-1);
		treap[now].r=u.fi;
		update(now);
		return make_pair(now,u.se);
	}
	pir u=split(treap[now].l,k);
	treap[now].l=u.se;
	update(now);
	return make_pair(u.fi,now);
}

int merge(int x,int y){
	if (!x||!y)return x|y;
	if (treap[x].key<treap[y].key){
		treap[x].r=merge(treap[x].r,y);
		update(x);
		return x;
	}
	treap[y].l=merge(x,treap[y].l);
	update(y);
	return y;
}

struct node{
	int l,r,tot;
}tree[N*20];
int Rt[N],tot;
int que[N],u;

void getque(int now){
	if (!now)return;
	getque(treap[now].l);
	que[++u]=now;
	getque(treap[now].r);
}

void add(int &now,int qf,int l,int r,int x){
	tree[now=++tot]=tree[qf];
	tree[now].tot++;
	if (l==r)return;
	int mid=(l+r)/2;
	if (x<=mid)add(tree[now].l,tree[qf].l,l,mid,x);
	else add(tree[now].r,tree[qf].r,mid+1,r,x);
}

int query(int now,int l,int r,int x,int y){
	if (x<=l&&r<=y)return tree[now].tot;
	int mid=(l+r)/2,ret=0;
	if (x<=mid)ret=query(tree[now].l,l,mid,x,y);
	if (y>mid)ret=ret+query(tree[now].r,mid+1,r,x,y);
	return ret;
}

LL times[N];
LL pre[N];

LL getans(int x,int k){
	//get block
	int blk=0;
	{
		int l=1,r=n;
		while(l<=r){
			int mid=(l+r)/2;
			int L=1,R=mid,kw=0;
			while(L<=R){
				int M=(L+R)/2;
				if (times[M]-times[mid+1]>=k)kw=M,L=M+1;
				else R=M-1;
			}
			LL all=pre[kw]-times[mid+1]*kw-1ll*k*kw;
			if (all>=x)blk=mid,r=mid-1;
			else l=mid+1;
		}
	}
	//get key
	int key=0;
	{
		int l=1,r=times[blk]-times[blk+1];
		while(l<=r){
			int mid=(l+r)/2;
			int L=1,R=blk,kw=0;
			while(L<=R){
				int M=(L+R)/2;
				if (times[M]-times[blk]+mid>=k)kw=M,L=M+1;
				else R=M-1;
			}
			LL all=pre[kw]-times[blk]*kw+1ll*mid*kw-1ll*k*kw;
			if (all>=x)key=mid,r=mid-1;
			else l=mid+1;
		}
	}
	//get ans
	int kw=0;
	{
		int L=1,R=blk;
		while(L<=R){
			int M=(L+R)/2;
			if (times[M]-times[blk]+key-1>=k)kw=M,L=M+1;
			else R=M-1;
		}
	}
	LL all=pre[kw]-times[blk]*kw+1ll*(key-1)*kw-1ll*k*kw;
	int ans=0;
	{
		int l=1,r=n;
		while(l<=r){
			int mid=(l+r)/2;
			if(all+query(Rt[mid],1,n,1,kw)>=x)ans=mid,r=mid-1;
			else l=mid+1;
		}
	}
	ans=query(Rt[ans],1,n,1,blk);
	return st[blk]-1+1ll*blk*(key-1)+ans;
}

int main(){
	seed=74851365;
	n=get();m=get();
	fo(i,1,n)a[i]=get();
	start=a[1];
	fo(i,1,n)a[i]-=start;
	st[1]=0;
	treap[rt=1].init();
	fo(i,2,n){
		int w=(a[i]-st[i-1])%(i-1);
		st[i]=a[i]-w;
		pir u=split(rt,w);
		treap[i].init();
		rt=merge(merge(u.fi,i),u.se);
	}
	getque(rt);
	fo(i,1,n)add(Rt[i],Rt[i-1],1,n,que[i]);
	fo(i,1,n-1)times[i]=(st[i+1]-st[i])/i;
	times[n]=1e9;
	fd(i,n,1)times[i]+=times[i+1];
	fo(i,1,n)pre[i]=pre[i-1]+times[i];
	fo(cas,1,m){
		int x=get(),k=get();
		if (x<start){
			printf("%d\n",x);
			continue;
		}
		x=x-start+1;
		printf("%I64d\n",getans(x,k)+start);
	}
	return 0;
}