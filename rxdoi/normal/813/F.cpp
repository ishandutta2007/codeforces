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
#define lf else if

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

const int N=200000+19;
const int oo=(1<<30)-1;

map<pii,int> M;
int vis[N],Q[N],las[N],nxt[N],inT[N];
int n,m,q,c,x,y;
set<int> S;

struct Edge{
	int x,y,T;
} e[N];

struct node *null;
struct node{
	node *L,*R,*Fa;
	int mn,id,rev,sz;
	bool Top(){
		return Fa==null||Fa->L!=this&&Fa->R!=this;
	}
	void Update(){
		if (this==null) return;
		sz=L->sz+R->sz+(id!=0);
		mn=id;
		if (e[L->mn].T<e[mn].T) mn=L->mn;
		if (e[R->mn].T<e[mn].T) mn=R->mn;
	}
	void Reverse(){
		swap(L,R),rev^=1;
	}
	void Down(){
		if (this==null) return;
		if (rev){
			L->Reverse();
			R->Reverse();
			rev=0;
		}
	}
	void Zig(){
		node *y=Fa,*z=y->Fa;
		if (y==z->L) z->L=this;else if (y==z->R) z->R=this;Fa=z;
		y->L=R;if (R!=null) R->Fa=y;
		R=y;y->Fa=this;y->Update();
	}
	void Zag(){
		node *y=Fa,*z=y->Fa;
		if (y==z->L) z->L=this;else if (y==z->R) z->R=this;Fa=z;
		y->R=L;if (L!=null) L->Fa=y;
		L=y;y->Fa=this;y->Update();
	}
} Nd[N],*P[N],*E[N],*cur=Nd+1;

void Splay(node *x){
	static node *s[N];
	node *tmp=x;int k=0;
	while (!tmp->Top()) s[++k]=tmp,tmp=tmp->Fa;s[++k]=tmp;
	while (k) s[k--]->Down();
	while (!x->Top()){
		node *y=x->Fa,*z=y->Fa;
		if (!y->Top()){
			if (x==y->L) if (y==z->L) y->Zig(),x->Zig();else x->Zig(),x->Zag();
				else if (y==z->L) x->Zag(),x->Zig();else y->Zag(),x->Zag();
		} else{
			if (x==y->L) x->Zig();else x->Zag();
		}
	}
	x->Update();
}
node *Access(node *x){
	node *y;
	for (y=null;x!=null;y=x,x=x->Fa) Splay(x),x->R=y,x->Update();
	return y;
}
node *Root(node *x){
	Access(x),Splay(x);
	while (x->L!=null) x=x->L,x->Down();
	return x;
}
void Evert(node *x){
	Access(x)->Reverse();
}
void Link(node *x,node *y){
	Evert(x),Splay(x),x->Fa=y;
}
void Cut(node *x,node *y){
	Access(x),Splay(y);
	if (y->Fa==x){
		y->Fa=null;
	} else{
		Access(y),Splay(x),x->Fa=null;
	}
}

node *New(int id){
	return *cur=(node){null,null,null,id,id,0,0},cur++;
}

int main(){
	e[0].T=oo;
	null=Nd;
	*null=(node){null,null,null,0,0,0,0};
	n=IN(),q=IN();
	For(i,1,N) nxt[i]=q+1;
	For(i,1,q+1){
		x=IN(),y=IN();
		if (!M.count(mp(x,y))){
			M[mp(x,y)]=++m;
			e[m]=(Edge){x,y,0};
		}
		Q[i]=M[mp(x,y)];
		if (vis[Q[i]]){
			vis[Q[i]]=0;
			nxt[las[Q[i]]]=i;
		} else{
			vis[Q[i]]=1;
			las[Q[i]]=i;
		}
	}
	memset(vis,0,sizeof(vis));
	For(i,1,n+1) P[i]=New(0);
	For(i,1,m+1) E[i]=New(i);
	For(i,1,q+1){
		int id=Q[i];
		if (!vis[id]){
			vis[id]=1;
			e[id].T=nxt[i];
			node *x=P[e[id].x],*y=P[e[id].y],*z=E[id];
			if (Root(x)!=Root(y)){
				Link(x,z);
				Link(y,z);
				inT[id]=1;
			} else{
				Evert(x);
				int t=Access(y)->mn;
				if (e[t].T<e[id].T){
					Cut(P[e[t].x],E[t]);
					Cut(P[e[t].y],E[t]);
					Link(x,z);
					Link(y,z);
					inT[t]=0;
					inT[id]=1;
				} else{
					t=id;
				}
				Evert(P[e[t].x]);
				if (Access(P[e[t].y])->sz%2==0){
					S.insert(t);
				}
			}
		} else{
			vis[id]=0;
			if (!inT[id]){
				if (S.find(id)!=S.end()) S.erase(id);
			} else{
				Cut(P[e[id].x],E[id]);
				Cut(P[e[id].y],E[id]);
				inT[id]=0;
			}
		}
		puts(S.empty()?"YES":"NO");
	}
}