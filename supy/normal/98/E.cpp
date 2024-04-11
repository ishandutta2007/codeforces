#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define pb push_back
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
#define L(i,u) for (int i=head[u]; i!=0; i=edge[i].nxt)
#define abs(a) ((a)>0 ? (a) : (-a))
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> Pii;
typedef long long ll;
typedef long double ld;
const ld EPS=1e-7;
int n,m;
ld g[1002][1002];
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
inline ld f(int n, int m) {
	if (g[n][m]>EPS) return g[n][m];	
	if (!n) {g[n][m]=1.0/(m+1); return g[n][m];}
	if (!m) {g[n][m]=1; return g[n][m];}
	ld a,b,c,d,p;
	a=(ld)m/(m+1)*(1-f(m-1,n));
	b=1.0/(m+1)+(ld)m/(m+1)*(1-f(m-1,n));
	c=1; d=1-f(m,n-1);
//	printf("%lf %lf %lf %lf\n",(double)a,(double)b,(double)c,(double)d);
	p=(c-d)/((b-d)-(a-c));
	if (p>1) p=1; if (p<0) p=0;
	g[n][m]=min(a*p+c*(1-p),b*p+d*(1-p));
	return g[n][m];
}
int main() {
	read(n); read(m);
	ld ans=f(n,m);
	printf("%.11lf %.11lf",(double)ans,(double)(1-ans));
	return 0;
}