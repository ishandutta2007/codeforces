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

const int N=100000+19;
const int Top=10000000;
const int p=1e9+7;

int A[N],B[N],fa[N],fb[N],sz[N],C[N];
int n,res,x;
Vi V[N];

struct node{
	node *L,*R;
	int sum,plu,coef;
} Nd[Top],*cur=Nd,*rtA[N],*rtB[N];
int Ql,Qr,Qv;

void Plus(node *x,int v){
	x->sum=(x->sum+1ll*x->coef*v)%p;
	x->plu=(x->plu+v)%p;
}
void Down(node *x){
	if (x->plu){
		Plus(x->L,x->plu);
		Plus(x->R,x->plu);
		x->plu=0;
	}
}
node *Build(int L,int R){
	node *x=cur++;
	x->coef=R-L+1;
	if (L==R) return x;
	x->L=Build(L,Mid);
	x->R=Build(Mid+1,R);
	return x;
}
void Modify(node *x,int L,int R){
	if (Ql<=L&&R<=Qr){
		Plus(x,Qv);
		return;
	}
	Down(x);
	if (Ql<=Mid) Modify(x->L,L,Mid);
	if (Qr>Mid) Modify(x->R,Mid+1,R);
	x->sum=(x->L->sum+x->R->sum)%p;
}
void Work(node *x,int L,int R){
	if (L==R){
		x->coef+=Qv;
		x->sum=(x->coef?x->plu:0);
		return;
	}
	Down(x);
	Ql<=Mid?Work(x->L,L,Mid):Work(x->R,Mid+1,R);
	x->coef=(x->L->coef+x->R->coef)%p;
	x->sum=(x->L->sum+x->R->sum)%p;
}
int Query(node *x,int L,int R){
	if (Ql<=L&&R<=Qr) return x->sum;
	Down(x);
	int res=0;
	if (Ql<=Mid) res=(res+Query(x->L,L,Mid))%p;
	if (Qr>Mid) res=(res+Query(x->R,Mid+1,R))%p;
	return res;
}
void Modify1(int i,int val,int f){
	int x=A[i];
	int pos=lower_bound(V[x].begin(),V[x].end(),i)-V[x].begin();
	if (f==1){
		Ql=pos+1;
		Qr=sz[x]-1;
		Qv=val;
		if (Ql<=Qr) Modify(rtA[x],0,sz[x]-1);
	} else{
		Ql=0;
		Qr=pos-1;
		Qv=val;
		if (Ql<=Qr) Modify(rtB[x],0,sz[x]-1);
	}
}
void Modify2(int i,int val,int f){
	int x=A[i];
	int pos=lower_bound(V[x].begin(),V[x].end(),i)-V[x].begin();
	Ql=Qr=pos;
	Qv=val;
	Work(f==1?rtA[x]:rtB[x],0,sz[x]-1);
}
int Query1(int i,int f){
	int x=A[i];
	int pos=lower_bound(V[x].begin(),V[x].end(),i)-V[x].begin();
	if (f==1){
		Ql=0;
		Qr=pos-1;
		return Ql<=Qr?Query(rtA[x],0,sz[x]-1):0;
	} else{
		Ql=pos+1;
		Qr=sz[x]-1;
		return Ql<=Qr?Query(rtB[x],0,sz[x]-1):0;
	}
}
int Query2(int i,int f){
	int x=A[i];
	int pos=lower_bound(V[x].begin(),V[x].end(),i)-V[x].begin();
	Ql=Qr=pos;
	return Query(f==1?rtA[x]:rtB[x],0,sz[x]-1);
}

void Add(int x){
	for (;x<=n;x+=x&-x) C[x]++;
}
int Qry(int x){
	int res=0;
	for (;x;x-=x&-x) res+=C[x];
	return res;
}

int main(){
	n=IN();
	For(i,1,n+1) A[i]=B[i]=IN();
	sort(B+1,B+n+1);
	*B=unique(B+1,B+n+1)-B-1;
	For(i,1,n+1) A[i]=lower_bound(B+1,B+n+1,A[i])-B;
	For(i,1,n+1) V[A[i]].pb(i);
	For(i,1,n+1){
		sort(V[i].begin(),V[i].end());
		sz[i]=V[i].size();
		if (sz[i]){
			rtA[i]=Build(0,sz[i]-1);
			rtB[i]=Build(0,sz[i]-1);
		}
	}
	for (int i=1;i<=n;i++){
		fa[i]=Qry(A[i]);
		Add(A[i]);
	}
	memset(C,0,sizeof(C));
	for (int i=n;i>=1;i--){
		fb[i]=Qry(A[i]);
		Add(A[i]);
	}
	For(i,1,n+1){
		Modify1(i,fa[i],1);
		Modify1(i,fb[i],2);
	}
	For(i,1,n+1){
		res=(res+1ll*Query2(i,1)*Query2(i,2))%p;
	}
	for (int q=IN();q--;){
		if (IN()==1){
			x=IN();
			res=(res-1ll*Query2(x,1)*Query2(x,2)%p+p)%p;
			res=(res-1ll*fa[x]*Query1(x,2)%p+p)%p;
			res=(res-1ll*fb[x]*Query1(x,1)%p+p)%p;
			Modify1(x,p-fa[x],1);
			Modify1(x,p-fb[x],2);
			Modify2(x,-1,1);
			Modify2(x,-1,2);
		} else{
			x=IN();
			Modify2(x,1,1);
			Modify2(x,1,2);
			Modify1(x,fa[x],1);
			Modify1(x,fb[x],2);
			res=(res+1ll*fa[x]*Query1(x,2))%p;
			res=(res+1ll*fb[x]*Query1(x,1))%p;
			res=(res+1ll*Query2(x,1)*Query2(x,2))%p;
		}
		printf("%d\n",res);
	}
}