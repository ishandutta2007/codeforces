#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<set>
#include<map>
#define fi first
#define se second
#define pb push_back
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define abs(a) ((a)>0 ? (a) : -(a))
#define inf 0x3f3f3f3f
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
typedef long long ll;
typedef long double ld;
const int N = 4004, M = 91;
int n,a[N],f[N][183][91]; //pos1,delta_pos,k
int sum[N];

inline void LOCAL() {freopen("1.in","r",stdin);}
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
inline int* g(int a, int b, int c) {return f[a][b-a+M]+c;}
inline int dp(int dep, int pos1, int pos2, int k) {
	if (n-pos1-pos2<k) return 0;
	if (n-pos1-pos2==k) return sum[n-pos2]-sum[pos1];
	int *now=g(pos1,pos2,k); if ((*now)<inf) return *now;
	if (!(dep&1)) 
	{ //maximize
		int mx1=sum[pos1+k]-sum[pos1]-dp(dep+1,pos1+k,pos2,k);
		int mx2=sum[pos1+k+1]-sum[pos1]-dp(dep+1,pos1+k+1,pos2,k+1);
		*now = max(mx1,mx2);
	//	if (mx1<inf && mx2<inf) (*now)=max(mx1,mx2);
	//	else {if (mx1<inf) (*now)=mx1; else (*now)=mx2;}
	}
	else {
		int mx1=sum[n-pos2]-sum[n-pos2-k]-dp(dep+1,pos1,pos2+k,k);
		int mx2=sum[n-pos2]-sum[n-pos2-k-1]-dp(dep+1,pos1,pos2+k+1,k+1);
		*now = max(mx1,mx2);
	//	if (mn1<inf && mn2<inf) (*now)=min(mn1,mn2);
	//	else {if (mn1<inf) (*now)=mn1; else (*now)=mn2;}
	}
//	printf("%d %d %d %d\n",pos1,pos2,k,*now);
	return *now;
}
int main() {//LOCAL();
	read(n); rep(i,1,n) read(a[i]),sum[i]=sum[i-1]+a[i];
	memset(f,inf,sizeof(f));
	printf("%d\n",dp(0,0,0,1));
//	rep(i,0,3) rep(j,0,3) rep(k,0,3) if (*g(i,j,k) < inf)
//		printf("%d %d %d %d\n",i,j,k,*g(i,j,k));	
	/**g(1,1,1)=a[1]; *g(2,2,2)=a[1]+a[2];
	rep(i,1,n) rep(j,-90,90) rep(k,1,90) if (*g(i,j,k))<inf) {
	}*/
	return 0;
}