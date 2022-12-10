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

const int N=100000+19;
const int p=1e9+7;

struct Matrix{
	int s[2][2];
} tmp,A,F,sum[N*4],tag[N*4],mul;
int val[N],hav[N*4];
int n,Qc,Ql,Qr,v;

Matrix operator * (Matrix A,Matrix B){
	For(i,0,2) For(j,0,2){
		tmp.s[i][j]=0;
		For(k,0,2) tmp.s[i][j]=(tmp.s[i][j]+1ll*A.s[i][k]*B.s[k][j])%p;
	}
	return tmp;
}
Matrix operator + (Matrix A,Matrix B){
	For(i,0,2) For(j,0,2){
		tmp.s[i][j]=(A.s[i][j]+B.s[i][j])%p;
	}
	return tmp;
}
Matrix Pow(Matrix A,int b){
	Matrix res;
	For(i,0,2) For(j,0,2) res.s[i][j]=(i==j);
	for (;b;b>>=1,A=A*A) if (b&1) res=res*A;
	return res;
}

void Build(int x,int L,int R){
	For(i,0,2) For(j,0,2) tag[x].s[i][j]=(i==j);
	if (L==R){
		sum[x]=A*Pow(F,val[L]-1);
		return;
	}
	Build(Lsn,L,Mid);
	Build(Rsn,Mid+1,R);
	sum[x]=sum[Lsn]+sum[Rsn];
}
void Mult(int x,Matrix A){
	sum[x]=sum[x]*A;
	tag[x]=tag[x]*A;
	hav[x]=1;
}
void Down(int x){
	if (hav[x]){
		hav[x]=0;
		Mult(Lsn,tag[x]);
		Mult(Rsn,tag[x]);
		For(i,0,2) For(j,0,2) tag[x].s[i][j]=(i==j);
	}
}
void Modify(int x,int L,int R){
	if (Ql<=L&&R<=Qr){
		Mult(x,mul);
		return;
	}
	Down(x);
	if (Ql<=Mid) Modify(Lsn,L,Mid);
	if (Qr>Mid) Modify(Rsn,Mid+1,R);
	sum[x]=sum[Lsn]+sum[Rsn];
}
int Query(int x,int L,int R){
	if (Ql<=L&&R<=Qr) return sum[x].s[0][1];
	Down(x);
	int res=0;
	if (Ql<=Mid) res=(res+Query(Lsn,L,Mid))%p;
	if (Qr>Mid) res=(res+Query(Rsn,Mid+1,R))%p;
	return res;
}

int main(){
	F.s[0][1]=F.s[1][0]=F.s[1][1]=1;
	A.s[0][1]=1;
	n=IN(),Qc=IN();
	For(i,1,n+1) val[i]=IN();
	Build(1,1,n);
	while (Qc--){
		if (IN()==1){
			Ql=IN(),Qr=IN();v=IN();
			mul=Pow(F,v);
			Modify(1,1,n);
		} else{
			Ql=IN(),Qr=IN();
			printf("%d\n",Query(1,1,n));
		}
	}
}