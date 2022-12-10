#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<bitset>
#include<string>
#include<cstdio>
#include<cctype>
#include<cassert>
#include<cstdlib>
#include<cstring>
#include<sstream>
#include<iostream>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define Mid (L+R>>1)

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=1e5+19;

typedef int one[N];
struct Edge{
	int y,nxt;
} E[N*2];
one las,sz,dep,top,id,son,fa;
int n,m,Qc,cnt,num,x,y,z,tot;
Vi V[N],res;

const int Top=5000000;
struct node *null;
struct node{
	node *L,*R;
	int val;
} Nd[Top],*cur=Nd,*rt[N];
int Qx;

node *New(node *L,node *R,int v){
	return *cur=(node){L,R,v},cur++;
}
node *Modify(node *x,int L,int R){
	if (L==R) return New(0x0,0x0,x->val+1);
	if (Qx<=Mid){
		return New(Modify(x->L,L,Mid),x->R,x->val+1);
	} else{
		return New(x->L,Modify(x->R,Mid+1,R),x->val+1);
	}
}

void Link(int x,int y){
	E[cnt]=(Edge){y,las[x]};las[x]=cnt++;
	E[cnt]=(Edge){x,las[y]};las[y]=cnt++;
}
void dfs(int x){
	sz[x]=1;
	rt[x]=rt[fa[x]];
	For(i,0,V[x].size()){
		Qx=V[x][i];
		rt[x]=Modify(rt[x],1,m);
	}
	for (int i=las[x],y;~i;i=E[i].nxt)
		if ((y=E[i].y)!=fa[x]){
			dep[y]=dep[x]+1;
			fa[y]=x;
			dfs(y);
			sz[x]+=sz[y];
			if (sz[y]>sz[son[x]]) son[x]=y;
		}
}
void dfs(int x,int Anc){
	id[x]=++num;
	top[x]=Anc;
	if (son[x]) dfs(son[x],Anc);
	for (int i=las[x],y;~i;i=E[i].nxt)
		if ((y=E[i].y)!=fa[x]&&y!=son[x]) dfs(y,y);
}
int LCA(int x,int y){
	int a=top[x],b=top[y];
	while (a!=b){
		if (dep[a]>dep[b]) swap(a,b),swap(x,y);
		y=fa[b],b=top[y];
	}
	return dep[x]<dep[y]?x:y;
}
void Work(node *a,node *b,node *c,node *d,int L,int R){
	if (tot==0||!(a->val+b->val-c->val-d->val)) return;
	if (L==R){
		res.pb(L);tot--;
		return;
	}
	Work(a->L,b->L,c->L,d->L,L,Mid);
	Work(a->R,b->R,c->R,d->R,Mid+1,R);
}

int main(){
	rt[0]=New(Nd,Nd,0);
	memset(las,-1,sizeof(las));
	n=IN(),m=IN(),Qc=IN();
	For(i,1,n) Link(IN(),IN());
	For(i,1,m+1) V[IN()].pb(i);
	dfs(1);
	dfs(1,1);
	while (Qc--){
		x=IN(),y=IN(),tot=IN();
		z=LCA(x,y);
		res.clear();
		Work(rt[x],rt[y],rt[z],rt[fa[z]],1,m);
		printf("%d ",res.size());
		For(i,0,res.size()) printf("%d ",res[i]);puts("");
	}
}