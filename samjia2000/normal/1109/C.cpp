#include<bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second

using namespace std;

typedef long long LL;
typedef double db;
typedef pair<int,int> pir;

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

const LL INF = 1.1e18;

typedef unsigned int ui;

ui seed;
ui getrand(){seed^=seed<<13;seed^=seed>>17;seed^=seed<<5;return seed;}

const int N = 1e5+5;

int q;
int n;
struct node{
	ui key;
	LL val;
	LL mi,sum,v,s;
	int l,r;
}tree[N];
int rt;

void update(int now){
	int ls=tree[now].l,rs=tree[now].r;
	tree[now].sum=tree[ls].sum+tree[rs].sum+tree[now].v;
	tree[now].mi=min(tree[ls].mi,min(tree[ls].sum+min(0ll,tree[now].v),tree[ls].sum+tree[now].v+tree[rs].mi));
}

pir split(int now,int x){
	if (!now)return make_pair(0,0);
	if (tree[now].val<=x){
		pir u=split(tree[now].r,x);
		tree[now].r=u.fi;
		update(now);
		return make_pair(now,u.se);
	}
	pir u=split(tree[now].l,x);
	tree[now].l=u.se;
	update(now);
	return make_pair(u.fi,now);
}

void change_last(int now,LL p){
	if (!now)return;
	if (!tree[now].r){
		tree[now].v=(p-tree[now].val)*tree[now].s;
		tree[now].v=min(tree[now].v,INF);
		tree[now].v=max(tree[now].v,-INF);
		update(now);
		return;
	}
	change_last(tree[now].r,p);
	update(now);
}

pir cut(int now,int x){
	pir u=split(now,x);
	change_last(u.fi,1e9+5);
	return u;
}

int merge(int x,int y){
	if (!x||!y)return x^y;
	if (tree[x].key<tree[y].key){
		tree[x].r=merge(tree[x].r,y);
		update(x);
		return x;
	}
	tree[y].l=merge(x,tree[y].l);
	update(y);
	return y;
}

int getfir(int x){
	if (!x)return 0;
	if (!tree[x].l)return x;
	return getfir(tree[x].l);
}

int combine(int x,int y){
	if (!x||!y)return x^y;
	change_last(x,tree[getfir(y)].val);
	return merge(x,y);
}

void add(int t,int s){
	tree[++n].key=getrand();
	tree[n].val=t;
	tree[n].s=s;
	if (s>0)tree[n].v=tree[n].sum=INF;
	if (s==0)tree[n].v=tree[n].sum=0;
	if (s<0)tree[n].v=tree[n].sum=-INF;
	tree[n].mi=min(0ll,tree[n].v);
	pir u=cut(rt,t);
	u.fi=combine(u.fi,n);
	rt=combine(u.fi,u.se);
}

void del(int t){
	pir u=cut(rt,t);
	u.fi=cut(u.fi,t-1).fi;
	rt=combine(u.fi,u.se);
}

db getans(int now,LL v){
	if (!now)return -1;
	if (v+tree[tree[now].l].mi>0&&v+tree[tree[now].l].sum+min(0ll,tree[now].v)>0)return getans(tree[now].r,v+tree[tree[now].l].sum+tree[now].v);
	if (v+tree[tree[now].l].mi<=0)return getans(tree[now].l,v);
	v+=tree[tree[now].l].sum;
	return (db)tree[now].val+db(v)/(-tree[now].s);
}

db solve(LL l,LL r,LL v){
	if(v==0)return l;
	pir a=cut(rt,l-1);
	pir b=cut(a.se,r);
	db ret=getans(b.fi,v);
	if (ret>r)ret=-1;
	rt=combine(a.fi,combine(b.fi,b.se));
	return ret;
}

int main(){
	seed=857392738;
	q=get();
	tree[0].mi=INF;
	fo(cas,1,q){
		int op=get();
		if (op==1){
			int t=get(),s=get();
			add(t,s);
		}
		if (op==2){
			int t=get();
			del(t);
		}
		if (op==3){
			int l=get(),r=get(),v=get();
			db ans=solve(l,r,v);
			if (ans<-1e-6)printf("-1\n");
			else printf("%.9lf\n",ans);
		}
		change_last(rt,1e9+5);
	}
	return 0;
}