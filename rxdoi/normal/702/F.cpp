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

const int N=2e5+19;
const int oo=(1<<30)-1;

struct Info{
	int x,y;
	bool operator < (const Info &B) const {return y>B.y||y==B.y&&x<B.x;}
} I[N];
struct QType{
	int val,id;
	bool operator < (const QType &B) const {return val<B.val;}
} Q[N];
int res[N],n,Qc;

int R(){
	return rand()<<15|rand();
}

//Treap
struct node *null;
struct node{
	node *L,*R;
	int fix,sz,key,plu,res,add,id;
	void Update(){
		if (this!=null){
			sz=L->sz+R->sz+1;
		}
	}
	void Plus(int p,int a){
		if (this!=null){
			key+=p;plu+=p;
			res+=a;add+=a;
		}
	}
	void Down(){
		if (this==null) return;
		if (plu||add){
			L->Plus(plu,add);
			R->Plus(plu,add);
			plu=0;add=0;
		}
	}
} Nd[N],*rt;
typedef pair<node*,node*> pnd;

node *Merge(node *A,node *B){
	if (A==null) return B;
	if (B==null) return A;
	if (A->fix<B->fix){
		A->Down();A->R=Merge(A->R,B);
		return A->Update(),A;
	} else{
		B->Down();B->L=Merge(A,B->L);
		return B->Update(),B;
	}
}
pnd Split(node *A,int k){
	if (A==null) return mp(null,null);
	pnd res;
	A->Down();
	if (k<=A->L->sz){
		res=Split(A->L,k);
		A->L=res.se;res.se=A;
		A->Update();
	} else{
		res=Split(A->R,k-A->L->sz-1);
		A->R=res.fi;res.fi=A;
		A->Update();
	}
	return res;
}
int Qmin(node *A){
	for (;A->L!=null;A=A->L) A->Down();
	return A->key;
}
int Qmax(node *A){
	for (;A->R!=null;A=A->R) A->Down();
	return A->key;
}
int getrank(node *x,int v){
	int res=0;
	while (x!=null){
		x->Down();
		if (v<x->key){
			x=x->L;
		} else{
			res+=x->L->sz+1;x=x->R;
		}
	}
	return res;
}
void Build(int n){
	static node *S[N],*las;
	int k=0;
	S[++k]=null;
	For(i,1,n+1){
		node *x=Nd+i;
		*x=(node){null,null,R(),0,Q[i].val,0,0,0,Q[i].id};
		las=null;
		while (x->fix<S[k]->fix) las=S[k--],las->Update();
		if (k>1) S[k]->R=x;
		S[++k]=x;
		x->L=las;
	}
	while (k>1) S[k--]->Update();
	rt=S[2];
}
void dfs(node *x){
	if (x==null) return;
	x->Down();
	dfs(x->L);
	res[x->id]=x->res;
	dfs(x->R);
}

int main(){
	null=Nd;
	*null=(node){null,null,-1,0,0,0,0,0,0};
	n=IN();
	For(i,1,n+1) I[i]=(Info){IN(),IN()};
	Qc=IN();
	For(i,1,Qc+1) Q[i]=(QType){IN(),i};
	sort(I+1,I+n+1);
	sort(Q+1,Q+Qc+1);
	Build(Qc);
	For(i,1,n+1){
		pnd A=Split(rt,getrank(rt,I[i].x-1)),B,C;
		if (A.se==null){
			rt=A.fi;continue;
		}
		A.se->Plus(-I[i].x,1);
		if (A.fi==null){
			rt=A.se;continue;
		}
		int mx=Qmax(A.fi);
		while (A.se!=null&&Qmin(A.se)<mx){
			B=Split(A.se,1);
			A.se=B.se;
			C=Split(A.fi,getrank(A.fi,B.fi->key));
			A.fi=Merge(C.fi,Merge(B.fi,C.se));
		}
		rt=Merge(A.fi,A.se);
	}
	dfs(rt);
	For(i,1,Qc+1) printf("%d ",res[i]);
	puts("");
}