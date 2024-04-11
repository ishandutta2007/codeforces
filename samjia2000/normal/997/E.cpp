#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#include<bitset>
#include<map>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

typedef long long LL;
typedef double db;

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

const int N = 1.2e5+5;
const int INF = 1e9;

int n,q;
int a[N];
LL ans[N];
struct QUERY{
	int l,r,id;
	QUERY(const int l_=0,const int r_=0,const int id_=0){l=l_;r=r_;id=id_;}
	friend bool operator <(QUERY a,QUERY b){return a.id<b.id;}
};
set<QUERY>s[N];
struct node{
	int l,r;
	int mv,tot,tim,ad;
	LL sum;
}tree[N*2];
int rt,tot;

void build(int &now,int l,int r){
	tree[now=++tot].mv=INF;
	tree[now].tot=r-l+1;
	tree[now].sum=tree[now].tim=tree[now].ad=0;
	if (l==r)return;
	int mid=(l+r)/2;
	build(tree[now].l,l,mid);
	build(tree[now].r,mid+1,r);
}

void down(int now){
	int l=tree[now].l,r=tree[now].r;
	if (tree[now].ad!=0){
		int ad=tree[now].ad;
		tree[l].ad=tree[l].ad+ad;
		tree[l].mv=tree[l].mv+ad;
		tree[r].ad=tree[r].ad+ad;
		tree[r].mv=tree[r].mv+ad;
		tree[now].ad=0;
	}
	if (tree[now].tim){
		int tim=tree[now].tim;
		if (tree[l].mv==tree[now].mv){
			tree[l].sum=tree[l].sum+1ll*tim*tree[l].tot;
			tree[l].tim=tree[l].tim+tim;
		}
		if (tree[r].mv==tree[now].mv){
			tree[r].sum=tree[r].sum+1ll*tim*tree[r].tot;
			tree[r].tim=tree[r].tim+tim;
		}
		tree[now].tim=0;
	}
}

void update(int now){
	int l=tree[now].l,r=tree[now].r;
	tree[now].mv=tree[l].mv;tree[now].tot=tree[l].tot;
	if (tree[now].mv>tree[r].mv)tree[now].mv=tree[r].mv,tree[now].tot=0;
	if (tree[now].mv==tree[r].mv)tree[now].tot=tree[now].tot+tree[r].tot;
	tree[now].sum=tree[l].sum+tree[r].sum;
}

void add(int now,int l,int r,int x,int y,int v){
	if (x<=l&&r<=y){
		tree[now].mv=tree[now].mv+v;
		tree[now].ad=tree[now].ad+v;
		return;
	}
	down(now);
	int mid=(l+r)/2;
	if (x<=mid)add(tree[now].l,l,mid,x,y,v);
	if (y>mid)add(tree[now].r,mid+1,r,x,y,v);
	update(now);
}

void change(int now,int l,int r,int x,int v){
	if (l==r){tree[now].tot=1;tree[now].mv=v;return;}
	down(now);
	int mid=(l+r)/2;
	if (x<=mid)change(tree[now].l,l,mid,x,v);
	else change(tree[now].r,mid+1,r,x,v);
	update(now);
}

void update(){
	tree[rt].sum=tree[rt].sum+tree[rt].tot;
	tree[rt].tim++;
}

LL query(int now,int l,int r,int x,int y){
	if (x<=l&&r<=y)return tree[now].sum;
	down(now);
	int mid=(l+r)/2;
	LL ret=0;
	if (x<=mid)ret=query(tree[now].l,l,mid,x,y);
	if (y>mid)ret=ret+query(tree[now].r,mid+1,r,x,y);
	return ret;
}

struct Decreasing_Stack{
	int len,a[N],w[N];
	
	void init(){len=0;}
	
	void pushback(int x,int p){
		while(len&&a[len]<x){
			add(rt,1,n,w[len-1]+1,w[len],-a[len]);
			len--;
		}
		add(rt,1,n,w[len]+1,p,x);
		a[++len]=x;
		w[len]=p;
	}
}Max,Min;

int main(){
	n=get();
	fo(i,1,n)a[i]=get();
	q=get();
	fo(i,1,q){
		int l=get(),r=get();
		s[r].insert(QUERY(l,r,i));
	}
	Max.init();Min.init();
	build(rt,1,n);
	fo(i,1,n){
		Max.pushback(a[i],i);
		Min.pushback(-a[i],i);
		add(rt,1,n,1,i,-1);
		change(rt,1,n,i,0);
		update();
		for(set<QUERY>::iterator h=s[i].begin();h!=s[i].end();h++)ans[(*h).id]=query(rt,1,n,(*h).l,(*h).r);
	}
	fo(i,1,q)printf("%I64d\n",ans[i]);
	return 0;
}