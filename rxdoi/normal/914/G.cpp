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

const int N=1<<17;
const int p=1e9+7;
const int I2=(p+1)/2;

int Pow(int a,int b){
	int res=1;
	for (;b;b>>=1,a=1ll*a*a%p) if (b&1) res=1ll*res*a%p;
	return res;
}

int A[N],fib[N],F[N],G[N],H[N],ans[N];
int n,res;

void calc1(int *A,int *B,int *C){
	static int F[18][N],G[18][N],H[18][N];
	memset(F,0,sizeof(F));
	memset(G,0,sizeof(G));
	memset(H,0,sizeof(H));
	For(i,0,N){
		F[__builtin_popcount(i)][i]=A[i];
		G[__builtin_popcount(i)][i]=B[i];
	}
	For(w,0,18) For(i,0,17) For(t,0,N) if (t>>i&1){
		F[w][t]=(F[w][t]+F[w][t^(1<<i)])%p;
		G[w][t]=(G[w][t]+G[w][t^(1<<i)])%p;
	}
	For(x,0,18) For(y,0,18-x){
		int w=x+y;
		For(t,0,N) H[w][t]=(H[w][t]+1ll*F[x][t]*G[y][t])%p;
	}
	For(w,0,18) For(i,0,17) For(t,0,N) if (t>>i&1){
		H[w][t]=(H[w][t]-H[w][t^(1<<i)]+p)%p;
	}
	For(i,0,N) C[i]=H[__builtin_popcount(i)][i];
}
void FWT(int *A){
	for (int i=1;i<N;i<<=1)
		for (int j=0;j<N;j+=i<<1)
			For(k,j,j+i){
				int x=A[k],y=A[k+i];
				A[k]=(x+y)%p;
				A[k+i]=(x-y+p)%p;
			}
}
void calc2(int *A,int *B,int *C){
	static int F[N],G[N];
	For(i,0,N) F[i]=A[i],G[i]=B[i];
	FWT(F);
	FWT(G);
	For(i,0,N) C[i]=1ll*F[i]*G[i]%p;
	FWT(C);
	int tmp=Pow(N,p-2);
	For(i,0,N) C[i]=1ll*C[i]*tmp%p;
}
void calc3(int *A,int *B,int *C){
	static int F[N],G[N];
	For(i,0,N) F[i]=A[i],G[i]=B[i];
	For(i,0,17) For(t,0,N) if (!(t>>i&1)){
		F[t]=(F[t]+F[t|1<<i])%p;
		G[t]=(G[t]+G[t|1<<i])%p;
	}
	For(i,0,N){
		F[i]=1ll*F[i]*G[i]%p;
	}
	For(i,0,17) For(t,0,N) if (!(t>>i&1)){
		F[t]=(F[t]-F[t|1<<i]+p)%p;
	}
	For(i,0,N) C[i]=F[i];
}

int main(){
	fib[0]=0;
	fib[1]=1;
	For(i,2,N) fib[i]=(fib[i-1]+fib[i-2])%p;
	n=IN();
	For(i,1,n+1) A[IN()]++;
	calc1(A,A,F);
	calc2(A,A,G);
	For(i,0,N){
		A[i]=1ll*A[i]*fib[i]%p;
		F[i]=1ll*F[i]*fib[i]%p;
		G[i]=1ll*G[i]*fib[i]%p;
	}
	calc3(A,F,H);
	calc3(H,G,ans);
	For(w,0,17) res=(res+ans[1<<w])%p;
	printf("%d\n",res);
}