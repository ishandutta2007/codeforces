#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second

using namespace std;

typedef long long LL;
typedef double db;

int get(){
	char ch;
	int s=0;
	while(ch=getchar(),ch<'0'||ch>'9');
	s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

typedef pair<int,int> P;

const int N = 2e+5+10;

struct T_shirts{
	int c,q;
}a[N];
struct point{
	int l,r,size,key,v,ad,num,ans,d;//ad for v;d for ans
}tree[N];
int n,k,root,tot;
int ans[N];

bool cmp(T_shirts a,T_shirts b){
	if (a.q!=b.q)return a.q>b.q;
	return	a.c<b.c;
}

void down(int now){
	int l=tree[now].l,r=tree[now].r;
	if (tree[now].ad){
		if (l){tree[l].ad+=tree[now].ad;tree[l].v-=tree[now].ad;}
		if (r){tree[r].ad+=tree[now].ad;tree[r].v-=tree[now].ad;}
		tree[now].ad=0;
	}
	if (tree[now].d){
		if (l){tree[l].ans+=tree[now].d;tree[l].d+=tree[now].d;}
		if (r){tree[r].ans+=tree[now].d;tree[r].d+=tree[now].d;}
		tree[now].d=0;
	}
}

void change(int now){
	tree[now].size=tree[tree[now].l].size+tree[tree[now].r].size+1;
}

int merge(int x,int y){
	if (!x||!y)return x^y;
	down(x);down(y);
	if (tree[x].key<tree[y].key){
		tree[x].r=merge(tree[x].r,y);
		change(x);
		return x;
	}
	else{
		tree[y].l=merge(x,tree[y].l);
		change(y);
		return y;
	}
}

P split(int now,int tot){
	if (!tot)return P(0,now);
	down(now);
	if (tree[tree[now].l].size>=tot){
		P f=split(tree[now].l,tot);
		tree[now].l=f.se;
		change(now);
		return P(f.fi,now);
	}
	P f=split(tree[now].r,tot-tree[tree[now].l].size-1);
	tree[now].r=f.fi;
	change(now);
	return P(now,f.se);
}

int gettot(int now,int v){
	down(now);
	if (!now)return 0;
	if (tree[now].v>=v)return gettot(tree[now].l,v);
	return gettot(tree[now].r,v)+tree[tree[now].l].size+1;
}

void insert(int &now,int v,int ans,int num,int w){
	int s=gettot(now,v);
	P f=split(now,s);
	int u=f.fi,e=f.se;
	tree[w].v=v;
	tree[w].ans=ans;
	tree[w].num=num;
	tree[w].key=rand();
	tree[w].size=1;
	u=merge(u,w);
	now=merge(u,e);
}

void del(int &now,int x){
	P f=split(now,1);
	now=f.se;
}

int kth(int now,int k){
	down(now);
	if (tree[tree[now].l].size+1==k)return now;
	if (k<=tree[tree[now].l].size)return kth(tree[now].l,k);
	return kth(tree[now].r,k-tree[tree[now].l].size-1);
}

void init(){
	n=get();
	srand(116786);
	fo(i,1,n){a[i].c=get();a[i].q=get();}
	sort(a+1,a+1+n,cmp);
	k=get();
	fo(i,1,k){
		if(i==1){
			tot=root=tree[1].size=tree[1].num=1;
			tree[1].v=get();
			tree[1].key=rand();
		}
		else{
			int x=get();
			insert(root,x,0,i,i);
		}
	}
}

void work(){
	fo(i,1,n){
		int s=gettot(root,a[i].c);
		P f=split(root,s);
		int u=f.fi,v=f.se;
		if (!v){root=u;continue;}
		tree[v].d++;
		tree[v].ans++;
		tree[v].ad+=a[i].c;
		tree[v].v-=a[i].c;
		if (!u){root=v;continue;}
		int mv=tree[kth(u,tree[u].size)].v;
		for(int x=kth(v,1);tree[x].v<mv&&v;x=kth(v,1)){
			del(v,x);
			insert(u,tree[x].v,tree[x].ans,tree[x].num,tree[x].num);
			if (!v)break;
		}
		if (!v){root=u;continue;}
		root=merge(u,v);
	}
}

void getans(int now){
	down(now);
	if (tree[now].l)getans(tree[now].l);
	if (tree[now].r)getans(tree[now].r);
	ans[tree[now].num]=tree[now].ans;
}

void putans(){
	getans(root);
	fo(i,1,k)printf("%d ",ans[i]);putchar('\n');
}

int main(){
	init();
	work();
	putans();
	return 0;
}