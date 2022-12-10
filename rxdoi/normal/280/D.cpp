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

const int N=100000+19;
const int oo=(1<<30)-1;

int A[N],L[N],R[N];
int n,l,r,K,res,top;

struct node{
	int sum,mx,mn,lmx,lmn,rmx,rmn,mxl,mxr,mnl,mnr,lmxf,lmnf,rmxf,rmnf,rev;
	void Reset(int val,int pos){
		sum=mx=mn=lmx=lmn=rmx=rmn=val;
		mxl=mxr=mnl=mnr=lmxf=lmnf=rmxf=rmnf=pos;
	}
	void Reverse(){
		sum*=-1;
		mx*=-1;mn*=-1;
		lmx*=-1;lmn*=-1;
		rmx*=-1;rmn*=-1;rev^=1;
		swap(mx,mn);
		swap(lmx,lmn);
		swap(rmx,rmn);
		swap(lmxf,lmnf);
		swap(rmxf,rmnf);
		swap(mxl,mnl);
		swap(mxr,mnr);
	}
} S[N*4],tmp;
int Ql,Qr,Qx;

node operator + (const node &A,const node &B){
	tmp.mx=-oo;
	if (A.mx>tmp.mx) tmp.mx=A.mx,tmp.mxl=A.mxl,tmp.mxr=A.mxr;
	if (B.mx>tmp.mx) tmp.mx=B.mx,tmp.mxl=B.mxl,tmp.mxr=B.mxr;
	if (A.rmx+B.lmx>tmp.mx) tmp.mx=A.rmx+B.lmx,tmp.mxl=A.rmxf,tmp.mxr=B.lmxf;
	tmp.lmx=-oo;
	if (A.lmx>tmp.lmx) tmp.lmx=A.lmx,tmp.lmxf=A.lmxf;
	if (A.sum+B.lmx>tmp.lmx) tmp.lmx=A.sum+B.lmx,tmp.lmxf=B.lmxf;
	tmp.rmx=-oo;
	if (B.rmx>tmp.rmx) tmp.rmx=B.rmx,tmp.rmxf=B.rmxf;
	if (B.sum+A.rmx>tmp.rmx) tmp.rmx=B.sum+A.rmx,tmp.rmxf=A.rmxf;

	tmp.mn=oo;
	if (A.mn<tmp.mn) tmp.mn=A.mn,tmp.mnl=A.mnl,tmp.mnr=A.mnr;
	if (B.mn<tmp.mn) tmp.mn=B.mn,tmp.mnl=B.mnl,tmp.mnr=B.mnr;
	if (A.rmn+B.lmn<tmp.mn) tmp.mn=A.rmn+B.lmn,tmp.mnl=A.rmnf,tmp.mnr=B.lmnf;
	tmp.lmn=oo;
	if (A.lmn<tmp.lmn) tmp.lmn=A.lmn,tmp.lmnf=A.lmnf;
	if (A.sum+B.lmn<tmp.lmn) tmp.lmn=A.sum+B.lmn,tmp.lmnf=B.lmnf;
	tmp.rmn=oo;
	if (B.rmn<tmp.rmn) tmp.rmn=B.rmn,tmp.rmnf=B.rmnf;
	if (B.sum+A.rmn<tmp.rmn) tmp.rmn=B.sum+A.rmn,tmp.rmnf=A.rmnf;

	tmp.sum=A.sum+B.sum;
	tmp.rev=0;
	return tmp;
}
void Down(int x){
	if (S[x].rev){
		S[Lsn].Reverse();
		S[Rsn].Reverse();
		S[x].rev=0;
	}
}
void Build(int x,int L,int R){
	if (L==R){
		S[x].Reset(A[L],L);
		return;
	}
	Build(Lsn,L,Mid);
	Build(Rsn,Mid+1,R);
	S[x]=S[Lsn]+S[Rsn];
}
void Change(int x,int L,int R){
	if (L==R){
		S[x].Reset(A[L],L);
		return;
	}
	Down(x);
	Qx<=Mid?Change(Lsn,L,Mid):Change(Rsn,Mid+1,R);
	S[x]=S[Lsn]+S[Rsn];
}
void Modify(int x,int L,int R){
	if (Ql<=L&&R<=Qr){
		S[x].Reverse();
		return;
	}
	Down(x);
	if (Ql<=Mid) Modify(Lsn,L,Mid);
	if (Qr>Mid) Modify(Rsn,Mid+1,R);
	S[x]=S[Lsn]+S[Rsn];
}
node Query(int x,int L,int R){
	if (Ql<=L&&R<=Qr) return S[x];
	Down(x);
	if (Qr<=Mid) return Query(Lsn,L,Mid);
	if (Ql>Mid) return Query(Rsn,Mid+1,R);
	return Query(Lsn,L,Mid)+Query(Rsn,Mid+1,R);
}

int main(){
	n=IN();
	For(i,1,n+1) A[i]=IN();
	Build(1,1,n);
	for (int Qc=IN();Qc--;)
		if (IN()){
			l=IN();r=IN();K=IN();
			res=0;
			while (K--){
				Ql=l,Qr=r;
				node tmp=Query(1,1,n);
				if (tmp.mx<0) break;
				res+=tmp.mx;
				Ql=tmp.mxl;Qr=tmp.mxr;
				Modify(1,1,n);
				top++;
				L[top]=Ql;R[top]=Qr;
			}
			for (;top;top--){
				Ql=L[top];Qr=R[top];
				Modify(1,1,n);
			}
			printf("%d\n",res);
		} else{
			Qx=IN();A[Qx]=IN();
			Change(1,1,n);
		}
}