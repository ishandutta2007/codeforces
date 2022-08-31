#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<assert.h>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
#define VI vector<int>
#define S(x) x.size()
using namespace std;
typedef long long LL;
typedef double db;
const int P=998244353;
const int G=3;
const int MAXN=(1<<18)+5;
int w[2][MAXN],rev[MAXN];
inline int Pow(int a,int b){
	int c=1;
	for(;b;b>>=1,a=a*1ll*a%P)if(b&1)c=c*1ll*a%P;
	return c;
}
inline void FFT(int *a,int f,int N){
	rep(i,0,N-1){
		int y=rev[i];
		if(i<y){int pa=a[i];a[i]=a[y];a[y]=pa;}
	}
	for(int i=1;i<N;i<<=1){
		for(int j=0;j<N;j+=(i<<1)){
			for(int k=0,l=0;k<i;k++,l+=(N/(i<<1))){
				int y=a[j+k];int x=a[j+k+i]*1ll*w[f][l]%P;
				a[j+k]=(x+y)%P;
				a[j+k+i]=(y-x+P)%P;
			}
		}
	}
	if(f){
		int dao=Pow(N,P-2);
		rep(i,0,N-1)a[i]=a[i]*1ll*dao%P;
	}
}
inline void prepare(int N){
	rep(i,0,N-1){
		int y=0;int x=i;
		for(int k=1;k<N;k<<=1,x>>=1)(y<<=1)|=(x&1);
		rev[i]=y;
	}
	w[0][0]=w[1][0]=1;
	int v=Pow(G,(P-1)/N);int inv=Pow(v,P-2);
	rep(i,1,N-1){
		w[0][i]=w[0][i-1]*1ll*v%P;
		w[1][i]=w[1][i-1]*1ll*inv%P;
	}
}
inline void Juan(int *a,int *b,int *c,int n){
	int N=1;
	while(N<=n)N*=2;N*=2;
	rep(i,n+1,N-1)a[i]=b[i]=c[i]=0;
	prepare(N);
	FFT(a,0,N);FFT(b,0,N);FFT(c,0,N);
	rep(i,0,N-1){
		c[i]=c[i]*1ll*a[i]%P;
		c[i]=c[i]*1ll*b[i]%P;
	}
	FFT(c,1,N);
}
int a[MAXN],b[MAXN],c[MAXN],f[MAXN];int n,m;int is[MAXN];
void work(int l,int r){
	if(l==r)return;
	int mid=(l+r)>>1;
	work(l,mid);
	rep(i,0,r-l)a[i]=b[i]=c[i]=0;
	rep(i,0,r-l)c[i]=is[i];
	rep(i,0,r-l){
		if(i>mid)break;
		if(i<l)a[i]=f[i]*2ll%P;
		else a[i]=f[i];
	}
	rep(i,l,mid)b[i-l]=f[i];
	Juan(a,b,c,r-l);
	rep(i,mid+1,r)f[i]=(f[i]+c[i-l])%P;
	work(mid+1,r);
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n){
		int v;scanf("%d",&v);is[v]=1;
	}
	f[0]=1;
	work(0,m);
	rep(i,1,m)printf("%d\n",f[i]);
	return 0;
}