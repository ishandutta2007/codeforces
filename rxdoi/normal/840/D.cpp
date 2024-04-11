#include<set>
#include<map>
#include<ctime>
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
#include<functional>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define Lsn (x<<1)
#define Rsn (x<<1|1)
#define Mid (L+R>>1)

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
typedef vector<int> Vi;

const int N=300000+19;
const int Top=10000000;
const int oo=(1<<30)-1;

struct Info{
	int val,cnt;
	bool operator < (const Info &B) const {return cnt>B.cnt;}
};

struct node{
	Info I[7];
	int sz;
} S[N*4],res;

struct info{
	int l,r,k,v,id;
};vector<info> Q;
int ans[N],A[N];
int n,m,p,K,Ql,Qr,Qv,k;

struct nd{
	nd *L,*R;
	int sum;
} Nd[Top],*cur=Nd,*rt[N];

nd *New(nd *L,nd *R,int s){
	return *cur=(nd){L,R,s},cur++;
}
nd *Modify(nd *x,int L,int R,int Qx){
	if (L==R) return New(0x0,0x0,x->sum+1);
	if (Qx<=Mid){
		return New(Modify(x->L,L,Mid,Qx),x->R,x->sum+1);
	} else{
		return New(x->L,Modify(x->R,Mid+1,R,Qx),x->sum+1);
	}
}
int Query(nd *x,int L,int R,int Qx){
	if (L==R) return x->sum;
	return Qx<=Mid?Query(x->L,L,Mid,Qx):Query(x->R,Mid+1,R,Qx);
}

void Ins(node &A,node &B){
	For(i,0,B.sz){
		int mn=oo,b=0;
		For(j,0,A.sz)
			if (A.I[j].val==B.I[i].val){
				A.I[j].cnt+=B.I[i].cnt;
				b=1;break;
			}
		if (b) continue;
		A.I[A.sz++]=B.I[i];
		if (A.sz<=K) continue;
		For(i,0,A.sz) mn=min(mn,A.I[i].cnt);
		For(i,0,A.sz) A.I[i].cnt-=mn;
		sort(A.I,A.I+A.sz);
		while (A.sz&&A.I[A.sz-1].cnt==0) A.sz--;
	}
}
void Build(int x,int L,int R){
	if (L==R){
		S[x].sz=1;
		S[x].I[0]=(Info){A[L]=IN(),1};
		return;
	}
	Build(Lsn,L,Mid);
	Build(Rsn,Mid+1,R);
	S[x].sz=0;
	Ins(S[x],S[Lsn]);
	Ins(S[x],S[Rsn]);
}
void Query(int x,int L,int R){
	if (Ql<=L&&R<=Qr){
		Ins(res,S[x]);
		return;
	}
	if (Ql<=Mid) Query(Lsn,L,Mid);
	if (Qr>Mid) Query(Rsn,Mid+1,R);
}

int main(){
	//freopen("D.in","r",stdin);
	rt[0]=New(Nd,Nd,0);
	n=IN(),m=IN(),K=5;
	Build(1,1,n);
	//dprintf("fuck");
	For(i,1,n+1) rt[i]=Modify(rt[i-1],1,n,A[i]);
	//dprintf("fuck");
	For(i,1,m+1){
		Ql=IN(),Qr=IN();k=IN();
		res.sz=0;
		Query(1,1,n);
		For(j,0,res.sz){
			Q.pb((info){Ql,Qr,k,res.I[j].val,i});
		}
		//dprintf("%d\n",i);
	}
	For(i,1,m+1) ans[i]=oo;
	for (info A:Q){
		int tmp=Query(rt[A.r],1,n,A.v)-Query(rt[A.l-1],1,n,A.v);
		if (tmp*A.k<=A.r-A.l+1) continue;
		ans[A.id]=min(ans[A.id],A.v);
	}
	For(i,1,m+1) printf("%d\n",ans[i]==oo?-1:ans[i]);
}