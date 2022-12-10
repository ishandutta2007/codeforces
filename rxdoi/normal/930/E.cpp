#include<bits/stdc++.h>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lf else if

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

const int N=4e5+19;
const int p=1e9+7;

int Pow(int a,int b){
	int res=1;
	for (;b;b>>=1,a=1ll*a*a%p) if (b&1) res=1ll*res*a%p;
	return res;
}

struct seg{
	int l,r;
} A[N],B[N];
int v0[N],v1[N],F[N],G[N],sumF[N],sumG[N],C[N];
int n,a,b,x,y;

int main(){
	n=IN(),a=IN(),b=IN();
	For(i,1,a+1){
		A[i]=(seg){IN(),IN()};
		C[++*C]=A[i].l;
		C[++*C]=A[i].r;
	}
	For(i,1,b+1){
		B[i]=(seg){IN(),IN()};
		C[++*C]=B[i].l;
		C[++*C]=B[i].r;
	}
	C[++*C]=1;
	C[++*C]=n;
	C[++*C]=n+1;
	sort(C+1,C+*C+1);
	*C=unique(C+1,C+*C+1)-C-1;
	For(i,1,a+1){
		A[i].l=lower_bound(C+1,C+*C+1,A[i].l)-C;
		A[i].r=lower_bound(C+1,C+*C+1,A[i].r)-C;
	}
	For(i,1,b+1){
		B[i].l=lower_bound(C+1,C+*C+1,B[i].l)-C;
		B[i].r=lower_bound(C+1,C+*C+1,B[i].r)-C;
	}
	For(i,1,a+1){
		v0[A[i].r]=max(v0[A[i].r],A[i].l);
	}
	For(i,1,b+1){
		v1[B[i].r]=max(v1[B[i].r],B[i].l);
	}
	For(i,1,*C+1){
		v0[i]=max(v0[i],v0[i-1]);
		v1[i]=max(v1[i],v1[i-1]);
	}
	F[0]=G[0]=1;
	sumF[0]=sumG[0]=1;
	For(i,1,*C){
		int f=(sumF[i-1]-(v0[i]?sumF[v0[i]-1]:0)+p)%p;
		int g=(sumG[i-1]-(v1[i]?sumG[v1[i]-1]:0)+p)%p;
		int len=C[i+1]-C[i];
		F[i]=(1ll*g*Pow(2,len-1)+1ll*f*(Pow(2,len-1)-1+p))%p;
		G[i]=(1ll*f*Pow(2,len-1)+1ll*g*(Pow(2,len-1)-1+p))%p;
		sumF[i]=(sumF[i-1]+F[i])%p;
		sumG[i]=(sumG[i-1]+G[i])%p;
	}
	printf("%d\n",(F[*C-1]+G[*C-1])%p);
}