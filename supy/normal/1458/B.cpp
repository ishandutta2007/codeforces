#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> T gcd(T a, T b){return !b?a:gcd(b,a%b);}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
mt19937 R(chrono::system_clock().now().time_since_epoch().count());

const int N = 103,inf=0x3f3f3f3f;
int n,a[N],b[N],tot;
int f[2][N][N*N];
int main() {
	read(n);rep(i,1,n)read(a[i]),read(b[i]),tot+=b[i];
	rep(i,0,n)rep(j,0,N*N-1)f[0][i][j]=f[1][i][j]=-inf;
	f[0][0][0]=0;
	rep(i,0,n-1){
		int p=i&1,q=p^1;//p-->q
		rep(x,0,i)rep(j,0,i*100)if(f[p][x][j]>-inf)
			umax(f[q][x][j],f[p][x][j]),
			umax(f[q][x+1][j+b[i+1]],f[p][x][j]+a[i+1]);
	}
	rep(i,1,n){
		double res=0;
		rep(j,0,n*100)if(f[n&1][i][j]>-inf)umax(res,min(1.0*f[n&1][i][j],j+(tot-j)/2.0));
		printf("%.7lf ",res);
	}
	return 0;
}