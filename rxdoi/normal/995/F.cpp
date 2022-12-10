#include<bits/stdc++.h>

#define For(i,x,y) for (int i=x;i<y;i++)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
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

const int N=3000+19;
const int p=1e9+7;

int Pow(int a,int b){
	int res=1;
	for (;b;b>>=1,a=1ll*a*a%p) if (b&1) res=1ll*res*a%p;
	return res;
}

Vi E[N];
int f[N][N],fac[N],inv[N],Inv[N],val[N];
int n,D,top;

int calc(int x,int n){
	static int pre[N],suf[N];
	pre[0]=suf[n+1]=1;
	for (int i=1;i<=n;i++) pre[i]=1ll*pre[i-1]*(x-i+p)%p;
	for (int i=n;i>=1;i--) suf[i]=1ll*suf[i+1]*(x-i+p)%p;
	int res=0;
	For(i,1,n+1){
		res=(res+1ll*pre[i-1]*suf[i+1]%p*inv[i-1]%p*Inv[n-i]%p*val[i])%p;
	}
	return res;
}
void dp(int x){
	For(i,1,N) f[x][i]=1;
	for (int y:E[x]){
		dp(y);
		int tmp=0;
		For(i,1,N){
			tmp=(tmp+f[y][i])%p;
			f[x][i]=1ll*f[x][i]*tmp%p;
		}
	}
}

int main(){
	fac[0]=1;
	For(i,1,N) fac[i]=1ll*fac[i-1]*i%p;
	inv[N-1]=Pow(fac[N-1],p-2);
	for (int i=N-1;i;i--) inv[i-1]=1ll*inv[i]*i%p;
	For(i,0,N) Inv[i]=(i&1?p-inv[i]:inv[i]);
	n=IN(),D=IN();
	For(i,2,n+1) E[IN()].pb(i);
	top=n+2;
	dp(1);
	For(i,1,top+1) val[i]=(val[i-1]+f[1][i])%p;
	printf("%d\n",calc(D,top));
}