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

const int p=998244353;
const int N=1<<17;

int f[5][N],W[2][N],rev[N],A[N],B[N],C[N],T[50];
int c,n,K;

int Pow(int a,int b){
	int res=1;
	for (;b;b>>=1,a=1ll*a*a%p) if (b&1) res=1ll*res*a%p;
	return res;
}
void Prepare(int n){
	int w0=Pow(3,(p-1)/n),i0=Pow(w0,p-2),pw=1,pi=1;
	For(i,0,n){
		W[0][i]=pw;pw=1ll*pw*w0%p;
		W[1][i]=pi;pi=1ll*pi*i0%p;rev[i]=0;
		for (int &y=rev[i],x=i,k=1;k<n;k<<=1,x>>=1) y=(y<<1)|(x&1);
	}
}
void FFT(int *A,int n,int f){
	For(i,0,n) if (i<rev[i]) swap(A[i],A[rev[i]]);
	for (int i=1;i<n;i<<=1)
		for (int j=0,t=n/(i<<1);j<n;j+=i<<1)
			for (int k=j,l=0;k<j+i;k++,l+=t){
				int x=A[k],y=1ll*W[f][l]*A[k+i]%p;
				A[k]=(x+y)%p;A[k+i]=(x-y+p)%p;
			}
	if (f){
		int tmp=Pow(n,p-2);
		For(i,0,n) A[i]=1ll*A[i]*tmp%p;
	}
}
void Plus1(int *A,int *B,int *C){
	static int tmp[N];
	For(i,0,K){
		tmp[i]=A[i];
		if (i) tmp[i]=(0ll+tmp[i]+A[i-1]+B[i-1])%p;
	}
	For(i,0,K){
		C[i]=B[i];B[i]=A[i];A[i]=tmp[i];
	}
}
void Mul2(int *A,int *B,int *C){
	static int AA[N],BB[N],AB[N],BC[N],CC[N];
	FFT(A,c,0);
	FFT(B,c,0);
	FFT(C,c,0);
	For(i,0,c){
		AA[i]=1ll*A[i]*A[i]%p;
		BB[i]=1ll*B[i]*B[i]%p;
		AB[i]=1ll*A[i]*B[i]%p;
		BC[i]=1ll*B[i]*C[i]%p;
		CC[i]=1ll*C[i]*C[i]%p;
	}
	FFT(AA,c,1);
	FFT(BB,c,1);
	FFT(AB,c,1);
	FFT(BC,c,1);
	FFT(CC,c,1);
	For(i,0,K){
		A[i]=(AA[i]+(!i?0:BB[i-1]))%p;
		B[i]=(AB[i]+(!i?0:BC[i-1]))%p;
		C[i]=(BB[i]+(!i?0:CC[i-1]))%p;
	}
	For(i,K,c){
		A[i]=B[i]=C[i]=0;
	}
}

int main(){
	n=IN(),K=IN()+1;
	for (c=1;c<K;c<<=1);c<<=1;
	Prepare(c);
	f[0][0]=1;
	for (int i=1;i<=3;i++)
		For(j,0,K){
			f[i][j]=f[i-1][j];
			if (j>=1&&i>=1) f[i][j]=(f[i][j]+f[i-1][j-1])%p;
			if (j>=1&&i>=2) f[i][j]=(f[i][j]+f[i-2][j-1])%p;
		}
	if (n<=3){
		For(i,1,K) printf("%d ",f[n][i]);
		puts("");
		return 0;
	}
	for (;n>3;n/=2) T[++*T]=n%2;
	if (n==2){
		For(i,0,K){
			A[i]=f[2][i];
			B[i]=f[1][i];
			C[i]=f[0][i];
		}
	} else{
		For(i,0,K){
			A[i]=f[3][i];
			B[i]=f[2][i];
			C[i]=f[1][i];
		}
	}
	for (int i=*T;i;i--){
		Mul2(A,B,C);
		if (T[i]) Plus1(A,B,C);
	}
	For(i,1,K) printf("%d ",A[i]);
	puts("");
}