#include<bits/stdc++.h>

#define For(i,x,y) for (int i=x;i<y;i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
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

const int N=5000+19;
const int p=1e9+7;

int Pow(int a,int b){
	int res=1;
	for (;b;b>>=1,a=1ll*a*a%p) if (b&1) res=1ll*res*a%p;
	return res;
}

int F[N][N];
int fac[N],inv[N],A[N];
int n,k,tmp,res;

int main(){
	fac[0]=1;
	For(i,1,N) fac[i]=1ll*fac[i-1]*i%p;
	inv[N-1]=Pow(fac[N-1],p-2);
	for (int i=N-1;i;i--) inv[i-1]=1ll*inv[i]*i%p;
	n=IN(),k=IN();
	For(i,1,n+1) A[i]=IN();	
	For(i,0,n+1){
		F[i][0]=1;
		For(j,1,i+1) F[i][j]=(F[i-1][j]+1ll*A[i]*F[i-1][j-1])%p;
	}
	tmp=1;
	For(i,0,n+1){
		res=(res+1ll*tmp*fac[i]%p*F[n][n-i])%p;
		tmp=1ll*tmp*Pow(i+1,p-2)%p*(k-i)%p;
		tmp=1ll*tmp*(p-Pow(n,p-2))%p;
	}
	printf("%d\n",(F[n][n]-res+p)%p);
}