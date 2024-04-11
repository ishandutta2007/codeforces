#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 1020000,inf=0x3f3f3f3f;
int n,m,a[N],f[N][3][3],g[N][9];
int main() {
	read(n);read(m);m+=3;
	rep(i,1,n){int x;read(x);a[x]++;}n=m;
	//a[1..n]
	rep(i,1,n)rep(j,0,8)
		g[i][j]=j>a[i]?-inf:(a[i]-j)/3;
	rep(i,0,n)rep(j,0,2)rep(k,0,2)f[i][j][k]=-inf;
	f[2][0][0]=0;
	rep(i,3,n)rep(x,0,2)rep(y,0,2)rep(z,0,2){
		umax(f[i][x][y],f[i-1][y][z]+x+g[i-2][x+y+z]);
	}
	cout<<f[n][0][0];
	return 0;
}