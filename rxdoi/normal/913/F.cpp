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

const int N=2000+19;
const int p=998244353;

int Pow(int a,int b){
	int res=1;
	for (;b;b>>=1,a=1ll*a*a%p) if (b&1) res=1ll*res*a%p;
	return res;
}

int g[N][N],h[N],w[N],pw0[N],pw1[N];
int n,a,b,P;

void upd(int &x,ll y){
	x=(x+y)%p;
}

int main(){
	n=IN(),a=IN(),b=IN();
	P=1ll*a*Pow(b,p-2)%p;
	pw0[0]=pw1[0]=1;
	For(i,1,N){
		pw0[i]=1ll*pw0[i-1]*(1-P+p)%p;
		pw1[i]=1ll*pw1[i-1]*P%p;
	}
	g[0][0]=1;
	For(i,0,n+1) For(j,0,n+1){
		if (j>=1) upd(g[i][j],1ll*g[i][j-1]*pw0[i]);
		if (i>=1) upd(g[i][j],1ll*g[i-1][j]*pw1[j]);
	}
	w[1]=1;
	For(i,2,n+1){
		w[i]=1;
		For(j,1,i){
			upd(w[i],-1ll*w[j]*g[j][i-j]);
		}
		w[i]=(w[i]+p)%p;
	}
	h[1]=0;
	For(i,2,n+1){
		For(j,1,i){
			int tmp=1ll*g[j][i-j]*w[j]%p;
			upd(h[i],1ll*tmp*(h[j]+h[i-j]+j*(j-1)/2+j*(i-j)));
		}
		upd(h[i],1ll*w[i]*(i*(i-1)/2));
		h[i]=1ll*h[i]*Pow(1-w[i]+p,p-2)%p;
	}
	printf("%d\n",h[n]);
}