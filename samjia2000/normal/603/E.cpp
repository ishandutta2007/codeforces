#include<bits/stdc++.h>

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

const int N = 1e5+5;
const int INF = 2e9;

int n,m;
int be[N],siz[N];

int getbe(int x){return be[x]==x?x:be[x]=getbe(be[x]);}

struct edge{
	int x,y,v;
}ed[N*3];
bool bz[N*3];

struct node{
	int s[2];
	int sum,v;
	int val,mv,id;
	bool rev;
}tree[N*4];
int light[N*4];
int fa[N*4];

void update(int x){
	tree[x].sum=tree[x].v+light[x];
	tree[x].mv=tree[x].val;
	if (tree[x].s[0])tree[x].sum+=tree[tree[x].s[0]].sum,tree[x].mv=max(tree[x].mv,tree[tree[x].s[0]].mv);
	if (tree[x].s[1])tree[x].sum+=tree[tree[x].s[1]].sum,tree[x].mv=max(tree[x].mv,tree[tree[x].s[1]].mv);
}

int pd(int x){
	if (x==tree[fa[x]].s[0])return 0;
	if (x==tree[fa[x]].s[1])return 1;
	return -1;
}

void rotate(int x){
	int y=fa[x],z=fa[y];
	int tx=pd(x),ty=pd(y);
	if (ty!=-1)tree[z].s[ty]=x;
	fa[x]=z;
	if (tree[x].s[tx^1])fa[tree[x].s[tx^1]]=y;
	tree[y].s[tx]=tree[x].s[tx^1];
	tree[x].s[tx^1]=y;
	fa[y]=x;
	update(y);
	update(x);
	if(ty!=-1)update(z);
}

void down(int x){
	if (tree[x].rev){
		swap(tree[x].s[0],tree[x].s[1]);
		if (tree[x].s[0])tree[tree[x].s[0]].rev^=1;
		if (tree[x].s[1])tree[tree[x].s[1]].rev^=1;
		tree[x].rev=0;
	}
}

int key[N*4],k;

void clear(int x){
	k=0;
	for(;pd(x)!=-1;x=fa[x])key[++k]=x;
	key[++k]=x;
	fd(i,k,1)down(key[i]);
}

void splay(int x){
	clear(x);
	while(pd(x)!=-1){
		if (pd(fa[x])!=-1){
			if (pd(x)==pd(fa[x]))rotate(fa[x]);
			else rotate(x);
		}
		rotate(x);
	}
}

void access(int x){
	splay(x);
	if (tree[x].s[1]){
		light[x]+=tree[tree[x].s[1]].sum;
		tree[x].s[1]=0;
		update(x);
	}
	while(fa[x]){
		int y=fa[x];
		splay(y);
		if (tree[y].s[1]){
			light[y]+=tree[tree[y].s[1]].sum;
			tree[y].s[1]=0;
			update(y);
		}
		light[y]-=tree[x].sum;
		tree[y].s[1]=x;
		splay(x);
	}
}

void makeroot(int x){
	access(x);
	tree[x].rev^=1;
	splay(x);
}

struct keyedge{
	int id,v;
	keyedge(const int id_=0,const int v_=0){id=id_;v=v_;}
	friend bool operator <(keyedge a,keyedge b){return a.v!=b.v?a.v>b.v:a.id<b.id;}
};
set<keyedge>used;

void del_edge(int id,bool yes){
	int x=ed[id].x,y=ed[id].y,v=ed[id].v;
	makeroot(x);
	access(y);
	splay(x);
	splay(y);
	splay(n+id);
	fa[x]=fa[y]=fa[n+id]=0;
	if (yes){
		set<keyedge>::iterator h=used.find(keyedge(id,ed[id].v));
		if (h!=used.end())used.erase(h);
	}
}


void add_edge(int id,bool yes){
	int x=ed[id].x,y=ed[id].y,v=ed[id].v;
	makeroot(x);
	makeroot(y);
	tree[x].rev^=1;
	tree[n+id].id=id;
	tree[n+id].sum=tree[n+id].v=0;
	tree[n+id].val=tree[n+id].mv=v;
	tree[n+id].s[0]=x,tree[n+id].s[1]=y;
	fa[x]=fa[y]=n+id;
	update(n+id);
	if (yes){
		used.insert(keyedge(id,ed[id].v));
	}
}

int getmx(int now){
	down(now);
	if (tree[now].val==tree[now].mv)return tree[now].id;
	if (tree[now].s[0]&&tree[tree[now].s[0]].mv==tree[now].mv)return getmx(tree[now].s[0]);
	return getmx(tree[now].s[1]);
}

int main(){
//	freopen("s.in","r",stdin);
//	freopen("s.out","w",stdout);
	n=get();m=get();
	fo(i,1,n)be[i]=i,siz[i]=1;
	int odd=n;
	used.clear();
	fo(i,1,n)tree[i].sum=tree[i].v=1,tree[i].mv=tree[i].val=-INF;
	fo(i,1,m){
		int x=get(),y=get(),v=get();
		ed[i].x=x,ed[i].y=y,ed[i].v=v;
		//if (x==y)continue;
		bz[i]=0;
		int bx=getbe(x),by=getbe(y);
		int preodd=odd;
		if (bx==by){
			if (x!=y){
				makeroot(x);
				access(y);
				if (tree[y].mv>v){
					int id=getmx(y);
					splay(n+id);
					bz[id]=0,bz[i]=1;
					del_edge(id,preodd==0);
					add_edge(i,preodd==0);
				}
			}
		}
		else{
			add_edge(i,preodd==0);
			if (siz[bx]&1)odd--;
			if (siz[by]&1)odd--;
			siz[bx]+=siz[by];
			be[by]=bx;
			if (siz[bx]&1)odd++;
			bz[i]=1;
		}
		if (preodd&&!odd){
			fo(j,1,i)
			if (bz[j])used.insert(keyedge(j,ed[j].v));
		}
		if (odd)printf("-1\n");
		else{
			bool pd=1;
			while(pd){
				int id=(*used.begin()).id;
				int x=ed[id].x,y=ed[id].y,v=ed[id].v;
				makeroot(x);
				access(y);
				splay(x);splay(y);splay(n+id);
				if (tree[x].sum&1)pd=0;
				else{
					pd=1;
					used.erase(used.begin());
				}
			}
			printf("%d\n",(*used.begin()).v);
		}
	}
	return 0;
}