#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define per(i,j,k) for(int i=j;i>=k;i--)
#define lowbit(x) ((x)&(-(x)))
using namespace std;
#define MAXN 1048576*2
typedef double db;
db pi=acos(-1.0);
struct ww{
	db x,y;
	inline ww operator +(const ww &b){
		return (ww){x+b.x,y+b.y};
	}
	inline ww operator -(const ww &b){
		return (ww){x-b.x,y-b.y};
	}
	inline ww operator *(const ww &b){
		return (ww){x*b.x-y*b.y,x*b.y+y*b.x};
	}
}w[2][MAXN],a[MAXN];
int rev[MAXN];
bool have[MAXN];
int gc[MAXN];
int n,m;
void init(){
	rep(i,0,n-1){
		int y=0;
		for(int j=1,k=i;j<n;j<<=1,k>>=1)(y<<=1)|=(k&1);
		rev[i]=y;
	}
	rep(i,0,n-1){
		db s=2*pi*i/n;
		w[0][i]=w[1][i]=(ww){cos(s),sin(s)};
		w[1][i].y*=-1;
	}
}
void FFT(ww a[MAXN],int f){
	rep(i,0,n-1)if(i<rev[i])swap(a[i],a[rev[i]]);
	for(int i=1;i<n;i<<=1)
	for(int j=0,l=(i<<1),t=n/l;j<n;j+=l)
	for(int u=0,k=0;u<i;u++,k+=t){
		ww y=a[j+u];ww x=a[j+u+i];
		a[j+u]=y+w[f][k]*x;
		a[j+u+i]=y-w[f][k]*x;
	}
	if(f)rep(i,0,n-1)a[i].x/=n;
}
int main()
{
	scanf("%d%d",&n,&m);
	rep(i,1,n){int v;scanf("%d",&v);have[v]=1;a[v].x=1;}
	n=1;while(n<=m)n*=2;n*=2;
	init();FFT(a,0);
	rep(i,0,n-1)a[i]=a[i]*a[i];
	FFT(a,1);rep(i,0,n-1)gc[i]=(int)(a[i].x+0.001);
	rep(i,1,m)if(!have[i]&&gc[i]){printf("NO\n");return 0;}
	int ans=0;rep(i,1,m)if(have[i]&&!gc[i])ans++;
	printf("YES\n");printf("%d\n",ans);
	rep(i,1,m)if(have[i]&&!gc[i])printf("%d ",i);
}