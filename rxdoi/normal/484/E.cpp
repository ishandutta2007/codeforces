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

const int N=100000+19;

struct QType{
	int l,r,w,id;
};vector<QType> Q;

int A[N],id[N],ans[N];
int n,q;

bool cmp(int x,int y){
	return A[x]<A[y];
}

struct node{
	int mx,len,lmx,rmx;
} S[N*4];
int Ql,Qr,Qx,Qv;

node operator + (const node &A,const node &B){
	static node tmp;
	tmp.mx=max(max(A.mx,B.mx),A.rmx+B.lmx);
	tmp.len=A.len+B.len;
	tmp.lmx=A.lmx+(A.lmx==A.len?B.lmx:0);
	tmp.rmx=B.rmx+(B.rmx==B.len?A.rmx:0);
	return tmp;
}
void Modify(int x,int L,int R){
	if (L==R){
		S[x]=(node){Qv,1,Qv,Qv};
		return;
	}
	Qx<=Mid?Modify(Lsn,L,Mid):Modify(Rsn,Mid+1,R);
	S[x]=S[Lsn]+S[Rsn];
}
void Build(int x,int L,int R){
	if (L==R){
		S[x]=(node){0,1,0,0};
		return;
	}
	Build(Lsn,L,Mid);
	Build(Rsn,Mid+1,R);
	S[x]=S[Lsn]+S[Rsn];
}
node Query(int x,int L,int R){
	if (Ql<=L&&R<=Qr) return S[x];
	if (Qr<=Mid) return Query(Lsn,L,Mid);
	if (Ql>Mid) return Query(Rsn,Mid+1,R);
	return Query(Lsn,L,Mid)+Query(Rsn,Mid+1,R);
}

void solve(int L,int R,vector<QType> Q){
	if (L==R){
		for (QType B:Q) ans[B.id]=A[id[L]];
		Qx=id[L];
		Qv=1;
		Modify(1,1,n);
		return;
	}
	For(i,Mid+1,R+1){
		Qx=id[i];
		Qv=1;
		Modify(1,1,n);
	}
	vector<QType> Q1,Q2;
	for (QType B:Q){
		Ql=B.l;
		Qr=B.r;
		if (Query(1,1,n).mx>=B.w) Q2.pb(B);else Q1.pb(B);
	}
	For(i,Mid+1,R+1){
		Qx=id[i];
		Qv=0;
		Modify(1,1,n);
	}
	solve(Mid+1,R,Q2);
	solve(L,Mid,Q1);
}

int main(){
	n=IN();
	For(i,1,n+1) A[i]=IN();
	For(i,1,n+1) id[i]=i;
	sort(id+1,id+n+1,cmp);
	q=IN();
	For(i,1,q+1) Q.pb((QType){IN(),IN(),IN(),i});
	Build(1,1,n);
	solve(1,n,Q);
	For(i,1,q+1) printf("%d\n",ans[i]);
}