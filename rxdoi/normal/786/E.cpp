#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<bitset>
#include<string>
#include<cstdio>
#include<cctype>
#include<cstdlib>
#include<cstring>
#include<cassert>
#include<sstream>
#include<numeric>
#include<iostream>
#include<algorithm>
#include<functional>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define Lsn (x<<1)
#define Rsn (x<<1|1)
#define Mid ((L+R)>>1)

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

typedef long long ll;
typedef double db;
typedef vector<int> Vi;
typedef pair<int,int> pii;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=2000000;
const int M=5000000;
const int oo=(1<<30)-1;

struct Edge{
	int y,f,nxt;
} E[M];
int las[N],dis[N],Q[N],son[N],top[N],sz[N],fa[N],id[N],dep[N],A[N],B[N],cal[N],vis[N];
int cnt,n,m,tot,S,T,num,res;
Vi V[N],V1,V2;
map<pii,int> P;

void Add_Edge(int x,int y,int f){
	E[cnt]=(Edge){y,f,las[x]};las[x]=cnt++;
	E[cnt]=(Edge){x,0,las[y]};las[y]=cnt++;
}
bool bfs(){
	For(i,1,tot+1) dis[i]=-1;
	dis[S]=1;
	int f=1,w=0;
	Q[1]=S;
	while (f>w){
		int x=Q[++w];
		for (int i=las[x],y;~i;i=E[i].nxt)
			if (E[i].f&&dis[y=E[i].y]==-1){
				dis[y]=dis[x]+1;
				Q[++f]=y;
				if (y==T) return 1;
			}
	}
	return 0;
}
int dinic(int x,int flow){
	if (x==T||!flow) return flow;
	int res=0;
	for (int i=las[x],y;~i;i=E[i].nxt)
		if (E[i].f&&dis[y=E[i].y]==dis[x]+1){
			int tmp=dinic(y,min(flow,E[i].f));
			res+=tmp,flow-=tmp,E[i].f-=tmp,E[i^1].f+=tmp;
		}
	if (!res) dis[x]=-1;
	return res;
}
void Dfs(int x){
	if (vis[x]) return;
	vis[x]=1;
	for (int i=las[x];~i;i=E[i].nxt)
		if (E[i].f){
			Dfs(E[i].y);
		}
}

void dfs(int x){
	sz[x]=1;
	for (int y:V[x])
		if (y!=fa[x]){
			fa[y]=x;
			dep[y]=dep[x]+1;
			dfs(y);
			sz[x]+=sz[y];
			if (sz[y]>sz[son[x]]) son[x]=y;
		}
}
void dfs(int x,int Anc){
	id[x]=++num;
	if (x>1){
		cal[id[x]]=P[mp(x,fa[x])];
	}
	top[x]=Anc;
	if (son[x]) dfs(son[x],Anc);
	for (int y:V[x])
		if (y!=fa[x]&&y!=son[x]){
			dfs(y,y);
		}
}

int pt[N],Ql,Qr;

void Build(int x,int L,int R){
	pt[x]=++tot;
	if (L==R){
		B[cal[L]]=pt[x];
		Add_Edge(pt[x],T,1);
		return;
	}
	Build(Lsn,L,Mid);
	Build(Rsn,Mid+1,R);
	Add_Edge(pt[x],pt[Lsn],oo);
	Add_Edge(pt[x],pt[Rsn],oo);
}
void Query(int x,int L,int R){
	if (Ql<=L&&R<=Qr){
		Add_Edge(tot,pt[x],oo);
		return;
	}
	if (Ql<=Mid) Query(Lsn,L,Mid);
	if (Qr>Mid) Query(Rsn,Mid+1,R);
}
void Query(int x,int y){
	int a=top[x],b=top[y];
	while (a!=b){
		if (dep[a]>dep[b]) swap(a,b),swap(x,y);
		Ql=id[b],Qr=id[y];
		Query(1,1,n);
		y=fa[b],b=top[y];
	}
	if (id[x]>id[y]) swap(x,y);
	Ql=id[x]+1,Qr=id[y];
	if (Ql<=Qr) Query(1,1,n);
}

int main(){
	memset(las,-1,sizeof(las));
	n=IN(),m=IN();
	For(i,1,n){
		int x=IN(),y=IN();
		V[x].pb(y);
		V[y].pb(x);
		P[mp(x,y)]=P[mp(y,x)]=i;
	}
	dfs(1);
	dfs(1,1);
	S=++tot,T=++tot;
	Build(1,1,n);
	For(i,1,m+1){
		int x=IN(),y=IN();
		tot++;
		A[i]=tot;
		Add_Edge(S,tot,1);
		Query(x,y);
	}
	while (bfs()) res+=dinic(S,oo);
	Dfs(S);
	For(i,1,m+1) if (!vis[A[i]]) V1.pb(i);
	For(i,1,n) if (vis[B[i]]) V2.pb(i);
	printf("%d\n",res);
	printf("%d ",V1.size());
	For(i,0,V1.size()) printf("%d ",V1[i]);
	puts("");
	printf("%d ",V2.size());
	For(i,0,V2.size()) printf("%d ",V2[i]);
	puts("");
}