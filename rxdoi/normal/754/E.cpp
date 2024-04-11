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

const int N=400*4+19;
const int p=998244353;

int Pow(int a,int b){
	int res=1;
	for (;b;b>>=1,a=1ll*a*a%p) if (b&1) res=1ll*res*a%p;
	return res;
}

char s[N][N],t[N][N];
int res[N][N],A[N][N],A2[N][N],B[N][N],B2[N][N],C[N][N],D[N][N];
int n,m,r,c,sum;

int W2[2][N],rev2[N],c2;
int W1[2][N],rev1[N],c1;

void Prepare(int W[][N],int *rev,int n){
	int pw=1,pi=1,w0=Pow(3,(p-1)/n),i0=Pow(w0,p-2);
	For(i,0,n){
		W[0][i]=pw;pw=1ll*pw*w0%p;
		W[1][i]=pi;pi=1ll*pi*i0%p;rev[i]=0;
		for (int &y=rev[i],x=i,k=1;k<n;k<<=1,x>>=1) y=(y<<1)|(x&1);
	}
}
void FFT1D(int *A,int n,int f){
	For(i,0,n) if (i<rev1[i]) swap(A[i],A[rev1[i]]);
	for (int i=1;i<n;i<<=1)
		for (int j=0,t=n/(i<<1);j<n;j+=i<<1)
			for (int k=j,l=0;k<j+i;k++,l+=t){
				int x=A[k],y=1ll*W1[f][l]*A[k+i]%p;
				A[k]=(x+y)%p;A[k+i]=(x-y+p)%p;
			}
	if (f){
		int tmp=Pow(n,p-2);
		For(i,0,n) A[i]=1ll*A[i]*tmp%p;
	}
}
void FFT2D(int A[][N],int n,int m,int f){
	For(i,0,n) FFT1D(A[i],m,f);
	For(i,0,n) if (i<rev2[i]){
		For(u,0,m) swap(A[i][u],A[rev2[i]][u]);
	}
	for (int i=1;i<n;i<<=1)
		for (int j=0,t=n/(i<<1);j<n;j+=i<<1)
			for (int k=j,l=0;k<j+i;k++,l+=t){
				For(u,0,m){
					int x=A[k][u],y=1ll*W2[f][l]*A[k+i][u]%p;
					A[k][u]=(x+y)%p;A[k+i][u]=(x-y+p)%p;
				}
			}
	if (f){
		int tmp=Pow(n,p-2);
		For(i,0,n){
			For(u,0,m) A[i][u]=1ll*A[i][u]*tmp%p;
		}
	}
}

void Work(){
	sum=0;
	For(i,0,n) For(j,0,m){
		int tmp=s[i][j]-'a'+1;
		A[n-1-i][m-1-j]=tmp;
		A2[n-1-i][m-1-j]=tmp*tmp;
	}
	For(i,0,r) For(j,0,c){
		int tmp=(t[i][j]=='?'?0:t[i][j]-'a'+1);
		B[i%n][j%m]+=tmp;
		B2[i%n][j%m]+=tmp*tmp;
		sum+=tmp*tmp*tmp;
	}
	FFT2D(A,c2,c1,0);
	FFT2D(A2,c2,c1,0);
	FFT2D(B,c2,c1,0);
	FFT2D(B2,c2,c1,0);
	For(i,0,c2) For(j,0,c1){
		C[i][j]=(1ll*A2[i][j]*B[i][j]-2ll*A[i][j]*B2[i][j]%p+p)%p;
	}
	FFT2D(C,c2,c1,1);
	For(i,0,c2) For(j,0,c1) (D[i%n][j%m]+=C[i][j])%=p;
	For(i,0,n) For(j,0,m) res[i][j]=(D[n-1-i][m-1-j]+sum)%p;
}

int main(){
	n=IN(),m=IN();
	For(i,0,n) scanf("%s",s[i]);
	r=IN(),c=IN();
	For(i,0,r) scanf("%s",t[i]);
	for (c2=1;c2<n;c2<<=1);c2<<=1;
	for (c1=1;c1<m;c1<<=1);c1<<=1;
	Prepare(W2,rev2,c2);
	Prepare(W1,rev1,c1);
	Work();
	For(i,0,n){
		For(j,0,m) printf("%d",res[i][j]==0);
		puts("");
	}
}