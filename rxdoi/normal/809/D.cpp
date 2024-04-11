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

const int N=300000+19;
const int oo=(1<<30)-1;

int R(int l,int r){
	return rand()%(r-l+1)+l;
}

struct node *null;
struct node{
	node *L,*R;
	int key,plu,sz;
	void Plus(int v){
		if (this==null) return;
		key+=v;plu+=v;
	}
	void Down(){
		if (this==null) return;
		if (plu){
			L->Plus(plu);
			R->Plus(plu);
			plu=0;
		}
	}
	void Update(){
		if (this==null) return;
		sz=L->sz+R->sz+1;
	}
} Nd[N],*rt;
typedef pair<node*,node*> pnn;

node *Merge(node *A,node *B){
	if (A==null) return B;
	if (B==null) return A;
	if (R(1,A->sz+B->sz)<=A->sz){
		A->Down();
		A->R=Merge(A->R,B);
		A->Update();
		return A;
	} else{
		B->Down();
		B->L=Merge(A,B->L);
		B->Update();
		return B;
	}
}
pnn Split(node *A,int k){
	if (A==null) return mp(null,null);
	A->Down();
	pnn res;
	if (k<=A->L->sz){
		res=Split(A->L,k);
		A->L=res.se;
		res.se=A;
		A->Update();
	} else{
		res=Split(A->R,k-A->L->sz-1);
		A->R=res.fi;
		res.fi=A;
		A->Update();
	}
	return res;
}
int getrank(node *x,int val){
	int res=0;
	while (x!=null){
		x->Down();
		if (x->key<=val){
			res+=x->L->sz+1;
			x=x->R;
		} else{
			x=x->L;
		}
	}
	return res;
}
node *Build(int l,int r){
	if (l>r) return null;
	int mid=(l+r)/2;
	node *x=Nd+mid+1;
	x->L=Build(l,mid-1);
	x->R=Build(mid+1,r);
	x->key=(mid==0?0:oo);
	x->plu=0;
	x->Update();
	return x;
}
void dfs(node *x){
	if (x==null) return;
	x->Down();
	dfs(x->L);
	printf("%d ",x->key);
	dfs(x->R);
}

int n,l,r;

int main(){
//	freopen("D.in","r",stdin);
	null=Nd;
	*null=(node){null,null,0,0,0};
	n=IN();
	rt=Build(0,n+1);
	For(T,0,n){
		l=IN(),r=IN();
		pnn A=Split(rt,getrank(rt,r-1));
		pnn B=Split(A.se,1);
		pnn C=Split(A.fi,getrank(A.fi,l-1));
		*B.fi=(node){null,null,l,0,1};
		C.se->Plus(1);
		rt=Merge(Merge(C.fi,B.fi),Merge(C.se,B.se));
//		dfs(rt);
//		puts("");
	}
	printf("%d\n",getrank(rt,oo-1)-1);
}