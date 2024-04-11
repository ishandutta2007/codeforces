#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
typedef long long ll;
using namespace std;
#define N 1005

int n,p,k;
int a[N],b[N],l1,l2;
int f[2][N][52][52];

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
inline int D(int x) {return x>0 ? x-1 : 0;}
inline int dp() { //p<2*ceil(n/k)
	//init
	memset(f, 0xaf, sizeof(f));
	f[0][0][0][0] = 0;
	int res=0;
	rep(i,1,n) {
		int now=(i&1)^1;
		rep(j,0,p) rep(x,0,k-1) rep(y,0,k-1) { //rep(j,0,p-1)
			//is choose A&B : the start place is different, so needn'tr
			f[i&1][j+1][k-1][D(y)]=max(f[i&1][j+1][k-1][D(y)],f[now][j][x][y]+(a[i]||y>0&&b[i])); //Care
			f[i&1][j+1][D(x)][k-1]=max(f[i&1][j+1][D(x)][k-1],f[now][j][x][y]+(x>0&&a[i]||b[i]));		
			f[i&1][j][D(x)][D(y)]=max(f[i&1][j][D(x)][D(y)],f[now][j][x][y]+(x>0&&a[i]||y>0&&b[i]));
		}
		memset(f[now],0xaf,sizeof(f[now]));
	}
//	rep(i,0,1) rep(j,0,p) 
//	rep(x,0,k-1) rep(y,0,k-1) res=max(res,f[i][j][x][y]);
	rep(x,0,k-1) rep(y,0,k-1) res=max(res,f[n&1][p][x][y]);
	return res;
}
int main() {
//	freopen("1.in","r",stdin);
	read(n); read(p); read(k);
	read(l1); rep(i,1,l1) {int x; read(x); a[x]=1;}
	read(l2); rep(i,1,l2) {int x; read(x); b[x]=1;}
	if (p>=2*((n-1)/k+1)) {
		int cnt=0;
		rep(i,1,n) cnt+=a[i]|b[i]; printf("%d",cnt);
		return 0;
	}
	printf("%d",dp());
	return 0;
}