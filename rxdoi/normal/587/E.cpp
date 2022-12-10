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

int B[N*4][32],res[32];
int A[N],C[N];
int n,Ql,Qr,Qx,Qv,Qc,tmp;

void Upd(int x,int v){
	for (;x<=n;x+=x&-x) C[x]^=v;
}
int Qry(int x){
	int res=0;
	for (;x;x-=x&-x) res^=C[x];
	return res;
}

void Ins(int *B,int x){
	for (int i=31;~i;i--)
		if (x>>i&1){
			if (!B[i]){
				B[i]=x;break;
			} else{
				x^=B[i];
			}
		}
}
void Build(int x,int L,int R){
	if (L==R){
		Ins(B[x],A[L]);
		return;
	}
	Build(Lsn,L,Mid);
	Build(Rsn,Mid+1,R);
	memcpy(B[x],B[Lsn],sizeof(B[Lsn]));
	For(i,0,32){
		if (B[Rsn][i]) Ins(B[x],B[Rsn][i]);
	}
}
void Modify(int x,int L,int R){
	if (L==R){
		memset(B[x],0,sizeof(B[x]));
		Ins(B[x],Qv);
		return;
	}
	Qx<=Mid?Modify(Lsn,L,Mid):Modify(Rsn,Mid+1,R);
	memcpy(B[x],B[Lsn],sizeof(B[Lsn]));
	For(i,0,32){
		if (B[Rsn][i]) Ins(B[x],B[Rsn][i]);
	}
}
void Query(int x,int L,int R){
	if (Ql<=L&&R<=Qr){
		For(i,0,32){
			if (B[x][i]) Ins(res,B[x][i]);
		}
		return;
	}
	if (Ql<=Mid) Query(Lsn,L,Mid);
	if (Qr>Mid) Query(Rsn,Mid+1,R);
}

int main(){
	n=IN(),Qc=IN();
	For(i,1,n+1) A[i]=IN();
	for (int i=n;i;i--){
		A[i]^=A[i-1];
		Upd(i,A[i]);
	}
	Build(1,1,n);
	while (Qc--){
		if (IN()==1){
			Ql=IN(),Qr=IN(),Qv=IN();
			Upd(Ql,Qv);
			Upd(Qr+1,Qv);
			Qx=Ql;{
				Qv=Qry(Qx)^Qry(Qx-1);
				Modify(1,1,n);
			}
			Qx=Qr+1;
			if (Qx<=n){
				Qv=Qry(Qx)^Qry(Qx-1);
				Modify(1,1,n);
			}
		} else{
			Ql=IN()+1,Qr=IN();
			memset(res,0,sizeof(res));
			if (Ql<=Qr) Query(1,1,n);
			Ins(res,Qry(Qr));
			tmp=0;
			For(i,0,32) tmp+=(res[i]>0);
			printf("%I64d\n",1ll<<tmp);
		}
	}
}