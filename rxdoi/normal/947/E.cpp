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
const int p=998244353;

int Pow(int a,ll b){
	int res=1;
	for (;b;b>>=1,a=1ll*a*a%p) if (b&1) res=1ll*res*a%p;
	return res;
}

int w[2][N],rev[N];
int A[N],B[N],fac[N],inv[N];
int n,c;
ll m;

void Prepare(int n){
	int w0=Pow(3,(p-1)/n),m;
	w[0][0]=w[1][0]=1;
	For(i,1,n){
		w[0][i]=w[1][n-i]=1ll*w[0][i-1]*w0%p;
	}
	for (m=0;(1<<m)!=n;m++);
	For(i,1,n) rev[i]=(rev[i>>1]>>1)|(i&1)<<m-1;
}
void FFT(int *A,int n,int f){
	For(i,0,n) if (i<rev[i]) swap(A[i],A[rev[i]]);
	for (int i=1;i<n;i<<=1)
		for (int j=0,t=n/(i<<1);j<n;j+=i<<1)
			for (int k=j,l=0;k<j+i;k++,l+=t){
				int x=A[k],y=1ll*w[f][l]*A[k+i]%p;
				A[k]=(x+y)%p;
				A[k+i]=(x-y+p)%p;
			}
	if (f){
		int tmp=Pow(n,p-2);
		For(i,0,n) A[i]=1ll*A[i]*tmp%p;
	}
}

int main(){
	fac[0]=1;
	For(i,1,N) fac[i]=1ll*fac[i-1]*i%p;
	inv[N-1]=Pow(fac[N-1],p-2);
	for (int i=N-1;i;i--) inv[i-1]=1ll*inv[i]*i%p;
	cin>>n>>m;
	n++;
	For(i,1,n+1) A[i]=IN();
	for (c=1;c<=n;c<<=1);c<<=1;
	Prepare(c);
	reverse(A+1,A+n+1);
	
	For(i,1,n+1) A[i]=1ll*A[i]*fac[n-i]%p;
	For(i,0,n+1) B[i]=inv[i];
	FFT(A,c,0);
	FFT(B,c,0);
	For(i,0,c) A[i]=1ll*A[i]*B[i]%p;
	FFT(A,c,1);
	For(i,1,n+1) A[i]=1ll*A[i]*inv[n-i]%p;
	For(i,n+1,c) A[i]=0;
	
	For(i,1,n+1) A[i]=1ll*A[i]*Pow(Pow(n-i+1,p-2),m)%p;
	memset(B,0,sizeof(B));
	For(i,1,n+1) A[i]=1ll*A[i]*fac[n-i]%p;
	For(i,0,n+1) B[i]=(i&1?p-inv[i]:inv[i]);
	FFT(A,c,0);
	FFT(B,c,0);
	For(i,0,c) A[i]=1ll*A[i]*B[i]%p;
	FFT(A,c,1);
	For(i,1,n+1) A[i]=1ll*A[i]*inv[n-i]%p;
	
	reverse(A+1,A+n+1);
	For(i,1,n+1) printf("%d ",A[i]);
	puts("");
}