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

ll IN(){
	int c,f;ll x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=100000+19;
const int Top=30000000;
const int oo=(1<<30)-1;

struct node *null;
struct node{
	node *L,*R;
	int mn,cov;
} Nd[Top],*cur=Nd+1,*Rt,*rt[N],*rt2;
int Ql,Qr,Qv;
int n,k,res;
ll l,r;

void Renew(node *&x){
	node *y=cur++;*y=*x;x=y;
}
void Cover(node *&x,int v){
	Renew(x);
	x->mn=x->cov=v;
}
void Down(node *&x){
	Renew(x);
	if (x->cov){
		Cover(x->L,x->cov);
		Cover(x->R,x->cov);
		x->cov=0;
	}
}
void Modify(node *&x,int L,int R){
	if (Ql<=L&&R<=Qr){
		Cover(x,Qv);
		return;
	}
	Down(x);
	if (Ql<=Mid) Modify(x->L,L,Mid);
	if (Qr>Mid) Modify(x->R,Mid+1,R);
	x->mn=min(x->L->mn,x->R->mn);
}
int Query(node *&x,int L,int R){
	if (Ql<=L&&R<=Qr) return x->mn;
	Down(x);
	int res=oo;
	if (Ql<=Mid) res=min(res,Query(x->L,L,Mid));
	if (Qr>Mid) res=min(res,Query(x->R,Mid+1,R));
	return res;
}
void dfs(node *&x,int L,int R,int Qx){
	Renew(x);
	if (L==R){
		if (x->cov){
			Cover(rt[Qx],x->cov);
			x->cov=0;
		}
		return;
	}
	Down(x);
	Qx<=Mid?dfs(x->L,L,Mid,Qx):dfs(x->R,Mid+1,R,Qx);
}
void Work(node *&x,int L,int R,int Qx){
	Renew(x);
	if (L==R){
		x->mn=rt[Qx]->mn;
		return;
	}
	assert(!x->cov);
	Qx<=Mid?Work(x->L,L,Mid,Qx):Work(x->R,Mid+1,R,Qx);
	x->mn=min(x->L->mn,x->R->mn);
}
void Init(int x){
	dfs(rt2,0,k-1,x);
}
void After(int x){
	Work(rt2,0,k-1,x);
}
node *Build(int L,int R){
	node *x=cur++;
	if (L==R){
		x->mn=IN();
		return x;
	}
	x->L=Build(L,Mid);
	x->R=Build(Mid+1,R);
	x->mn=min(x->L->mn,x->R->mn);
	return x;
}
node *Build2(int L,int R){
	node *x=cur++;
	if (L==R){
		x->mn=rt[L]->mn;
		return x;
	}
	x->L=Build2(L,Mid);
	x->R=Build2(Mid+1,R);
	x->mn=min(x->L->mn,x->R->mn);
	return x;
}

int main(){
//	freopen("alb.in","r",stdin);
	null=Nd;
	*null=(node){null,null,oo,0};
	n=IN(),k=IN();
	Rt=Build(0,n-1);
	For(i,0,k) rt[i]=Rt;
	rt2=Build2(0,k-1);
	for (int q=IN();q--;)
		if (IN()==1){
			l=IN()-1,r=IN()-1,Qv=IN();
			if (l/n==r/n){
				Ql=l%n,Qr=r%n;
				Init(l/n);Modify(rt[l/n],0,n-1);After(l/n);
			} else{
				Ql=l/n+1,Qr=r/n-1;
				if (Ql<=Qr) Modify(rt2,0,k-1);
				Ql=l%n,Qr=n-1;
				Init(l/n);Modify(rt[l/n],0,n-1);After(l/n);
				Ql=0,Qr=r%n;
				Init(r/n);Modify(rt[r/n],0,n-1);After(r/n);
			}
		} else{
			l=IN()-1,r=IN()-1;
			if (l/n==r/n){
				Ql=l%n,Qr=r%n;
				Init(l/n);
				printf("%d\n",Query(rt[l/n],0,n-1));
			} else{
				res=oo;
				Ql=l/n+1,Qr=r/n-1;
				if (Ql<=Qr) res=min(res,Query(rt2,0,k-1));
				Ql=l%n,Qr=n-1;
				Init(l/n);
				res=min(res,Query(rt[l/n],0,n-1));
				Ql=0,Qr=r%n;
				Init(r/n);
				res=min(res,Query(rt[r/n],0,n-1));
				printf("%d\n",res);
			}
		}
}