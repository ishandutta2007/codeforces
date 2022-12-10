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

const int N=100000+19;

struct node{
	db p,q;
} S[N*4],res;

int A[N],B[N];
int n,Qc,Qx,Ql,Qr,vis;

node operator + (node A,node B){
	node C;
	C.p=A.p*B.p/(1-(1-B.p)*(1-A.q));
	C.q=A.q*B.q/(1-(1-B.p)*(1-A.q));
	return C;
}
void Build(int x,int L,int R){
	if (L==R){
		S[x].p=1.0*A[L]/B[L];
		S[x].q=1-S[x].p;
		return;
	}
	Build(Lsn,L,Mid);
	Build(Rsn,Mid+1,R);
	S[x]=S[Lsn]+S[Rsn];
}
void Modify(int x,int L,int R){
	if (L==R){
		S[x].p=1.0*A[L]/B[L];
		S[x].q=1-S[x].p;
		return;
	}
	Qx<=Mid?Modify(Lsn,L,Mid):Modify(Rsn,Mid+1,R);
	S[x]=S[Lsn]+S[Rsn];
}
void Query(int x,int L,int R){
	if (Ql<=L&&R<=Qr){
		if (!vis) vis=1,res=S[x];else res=res+S[x];
		return;
	}
	if (Ql<=Mid) Query(Lsn,L,Mid);
	if (Qr>Mid) Query(Rsn,Mid+1,R);
}

int main(){
	n=IN(),Qc=IN();
	For(i,1,n+1) A[i]=IN(),B[i]=IN();
	Build(1,1,n);
	while (Qc--){
		if (IN()==1){
			Qx=IN();
			A[Qx]=IN();B[Qx]=IN();
			Modify(1,1,n);
		} else{
			Ql=IN(),Qr=IN();
			vis=0;
			Query(1,1,n);
			printf("%.20lf\n",res.p);
		}
	}
}