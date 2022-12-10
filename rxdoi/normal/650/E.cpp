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
#define fir first
#define sec second

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;

const int N=500000+19,M=N,oo=(1<<30)-1;

map<pii,int> Map;
struct Edge{
	int x,y,w;
} e1[M],e2[M];
int n,res,x,y;

struct node *null;
struct node{
	node *L,*R,*Fa;
	int rev,ID,Pos;
	
	bool Top() {return Fa==null||Fa->L!=this&&Fa->R!=this;}
	void Setrev() {rev^=1,swap(L,R);}
	void Down(){
		if (rev) L->Setrev(),R->Setrev(),rev=0;
	}
	void Update(){
		if (this==null) return;
		Pos=ID;
		if (e1[L->Pos].w) Pos=L->Pos;
		if (e1[R->Pos].w) Pos=R->Pos;
	}
	
	void Zig(){
		node *y=Fa,*z=y->Fa;
		if (y==z->L) z->L=this;else if (y==z->R) z->R=this;Fa=z;
		y->L=R;if (R!=null) R->Fa=y;
		R=y,y->Fa=this;y->Update();
	}
	void Zag(){
		node *y=Fa,*z=y->Fa;
		if (y==z->L) z->L=this;else if (y==z->R) z->R=this;Fa=z;
		y->R=L;if (L!=null) L->Fa=y;
		L=y,y->Fa=this;y->Update();
	}
} Nd[N+M],*cur=Nd+1,*P1[N],*E1[M];

node *New(int ID){
	return *cur=(node){null,null,null,0,ID,ID},cur++;
}
void Splay(node *x){
	static node *S[N+M];node *tmp=x;int k=0;
	while (!tmp->Top()) S[++k]=tmp,tmp=tmp->Fa;S[++k]=tmp;
	while (k) S[k--]->Down();
	while (!x->Top()){
		node *y=x->Fa,*z=y->Fa;
		if (!y->Top())
			if (x==y->L) if (y==z->L) y->Zig(),x->Zig();else x->Zig(),x->Zag();
				else if (y==z->L) x->Zag(),x->Zig();else y->Zag(),x->Zag();
		else if (x==y->L) x->Zig();else x->Zag();
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
void Evert(node *x) {Access(x)->Setrev();}
void Link(node *x,node *y) {Evert(x),Splay(x),x->Fa=y;}
void Cut(node *x,node *y){
	Access(x),Splay(y);
	if (y->Fa==x) y->Fa=null;else Access(y),Splay(x),x->Fa=null;
}

int main(){
	null=Nd;
	*null=(node){null,null,null,0,0,0};
	n=IN();
	res=n-1;
	For(i,1,n+1) P1[i]=New(0);
	For(i,1,n) E1[i]=New(i);
	For(i,1,n){
		x=IN(),y=IN();
		if (x>y) swap(x,y);
		e1[i]=(Edge){x,y,1};
		Map[mp(x,y)]=i;
	}
	For(i,1,n){
		x=IN(),y=IN();
		if (x>y) swap(x,y);
		e2[i]=(Edge){x,y,1};
		if (Map.count(mp(x,y))){
			e2[i].w=0;
			e1[Map[mp(x,y)]].w=0;
			res--;
		}
	}
	For(i,1,n){
		int x=e1[i].x,y=e1[i].y;
		Link(P1[x],E1[i]);
		Link(P1[y],E1[i]);
	}
	printf("%d\n",res);
	For(i,1,n)
		if (e2[i].w){
			x=e2[i].x,y=e2[i].y;
			Evert(P1[x]);
			node *t=Access(P1[y]);
			int c=t->Pos;
			printf("%d %d %d %d\n",e1[c].x,e1[c].y,e2[i].x,e2[i].y);
			e1[c].w=0;
			//E1[c]->ID=0;
			Cut(P1[e1[c].x],E1[c]);
			Cut(P1[e1[c].y],E1[c]);
			Link(P1[e2[i].x],E1[c]);
			Link(P1[e2[i].y],E1[c]);
		}
}