#include<bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second

using namespace std;

typedef double db;
typedef long long LL;
typedef pair<int,int> pir;

typedef unsigned int ui;

ui seed;
ui getrand(){seed^=seed<<13;seed^=seed>>17;seed^=seed<<5;return seed;}

LL get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		LL s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return -s;
	}
	LL s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 2e5+5;

int n,m;
LL C;
struct section{
	LL l,r;
	section(const LL l_=0,const LL r_=0){l=l_;r=r_;}
}sa[N],sb[N],s[N*4];
int k;
int ty[N*4];
struct node{
	 ui key;
	 int l,r;
	 LL x,y,adx,ady;
	 LL v0,v1;
	 LL L,R;
}tree[N*4];
int rt,tot;

void update(int now){
	tree[now].L=tree[now].R=tree[now].x;
	if (tree[now].l)tree[now].L=tree[tree[now].l].L;
	if (tree[now].r)tree[now].R=tree[tree[now].r].R;
	tree[now].v0=max(max(tree[tree[now].l].v0,tree[tree[now].r].v0),tree[now].y);
	tree[now].v1=max(max(tree[tree[now].l].v1,tree[tree[now].r].v1),tree[now].y-tree[now].x);
}

void add(int now,LL dx,LL dy){
	tree[now].x+=dx,tree[now].adx+=dx;
	tree[now].y+=dy,tree[now].ady+=dy;
	tree[now].v0+=dy;
	tree[now].v1+=dy-dx;
	tree[now].L+=dx,tree[now].R+=dx;
}

void down(int now){
	if (tree[now].adx!=0||tree[now].ady!=0){
		if (tree[now].l)add(tree[now].l,tree[now].adx,tree[now].ady);
		if (tree[now].r)add(tree[now].r,tree[now].adx,tree[now].ady);
		tree[now].adx=tree[now].ady=0;
	}
}

void insert(int &now,LL x,LL pl,LL pr){
	if (!now){
		tree[now=++tot].key=getrand();
		tree[now].x=x;
		tree[now].y=max(pl,pr+x);
		tree[now].L=tree[now].R=x;
		tree[now].v0=tree[now].y;
		tree[now].v1=tree[now].y-tree[now].x;
		return;
	}
	down(now);
	if(tree[now].x==x){
		pl=max(pl,tree[tree[now].l].v0);
		pr=max(pr,tree[tree[now].r].v1);
		tree[now].y=max(tree[now].y,max(pl,pr+x));
		update(now);
		return;
	}
	if (tree[now].x<x){
		insert(tree[now].r,x,max(pl,max(tree[tree[now].l].v0,tree[now].y)),pr);
		if (tree[tree[now].r].key<tree[now].key){
			int y=tree[now].r;
			tree[now].r=tree[y].l;
			tree[y].l=now;
			update(now);
			now=y;
		}
		update(now);
		return;
	}
	insert(tree[now].l,x,pl,max(pr,max(tree[tree[now].r].v1,tree[now].y-tree[now].x)));
	if (tree[tree[now].l].key<tree[now].key){
		int y=tree[now].l;
		tree[now].l=tree[y].r;
		tree[y].r=now;
		update(now);
		now=y;
	}
	update(now);
}

void mdf(int now,LL l,LL r,LL v){
	if(!now||r<tree[now].L||l>tree[now].R)return;
	if (l<=tree[now].L&&tree[now].R<=r){
		add(now,0,v);
		return;
	}
	if (l<=tree[now].x&&tree[now].x<=r)tree[now].y+=v;
	down(now);
	if (l<=tree[now].x)mdf(tree[now].l,l,r,v);
	if (r>=tree[now].x)mdf(tree[now].r,l,r,v);
	update(now);
}

int main(){
	seed=845159365;
	n=get();m=get();
	cin>>C;
	fo(i,1,n){
		sa[i].l=get()+1;sa[i].r=get();
	}
	fo(i,1,m){
		sb[i].l=get()+1;sb[i].r=get();
	}
	LL now=min(sa[1].l,sb[1].l);
	int ha=1,hb=1;
	for(;ha<=n||hb<=m;){
		LL p=1e18;
		int tp=0;
		if (ha<=n){if (now<sa[ha].l)p=sa[ha].l-1;else p=sa[ha].r,tp=1;}
		if (hb<=m){if (now<sb[hb].l)p=min(p,sb[hb].l-1);else p=min(p,sb[hb].r),tp|=2;}
		s[++k]=section(now,p);
		ty[k]=tp;
		if (ha<=n&&p==sa[ha].r)ha++;
		if (hb<=m&&p==sb[hb].r)hb++;
		now=p+1;
	}
	rt=tot=0;
	tree[++tot].key=getrand();
	rt=1;
	tree[0].v0=-1e18,tree[0].v1=-1e18;
	fo(i,1,k){
		if (!ty[i])continue;
		LL len=s[i].r-s[i].l+1;
		if (ty[i]==1){
			add(rt,len,len);
			continue;
		}
		if (ty[i]==2){
			add(rt,-len,0);
			continue;
		}
		LL lef=-1e18,rig=-1e18;
		insert(rt,-C,lef,rig);
		lef=rig=-1e18;
		insert(rt,C,lef,rig);
		mdf(rt,-C,C,len*2);
		mdf(rt,-1e18,-C-1,len);
		mdf(rt,C+1,1e18,len);
	}
	LL ans=tree[rt].v0;
	printf("%I64d\n",ans);
	return 0;
}