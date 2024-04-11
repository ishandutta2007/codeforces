#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define fi first
#define se second
#define pb push_back
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
#define L(i,u) for (int i=head[u]; i!=0; i=edge[i].nxt)
#define abs(a) ((a)>0 ? (a) : -(a))
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
typedef long long ll;
typedef long double ld;
int n,buc[1005];
int a[6][105];

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}

int main() {
	read(n); rep(i,1,n) rep(j,1,6) read(a[i][j]);
	rep(i,1,n) rep(j,1,6) buc[a[i][j]]=1;
	rep(i,1,n) rep(j,1,n) if (i!=j)
		rep(k,1,6) rep(l,1,6) if (a[i][k])
			buc[a[i][k]*10+a[j][l]]=1;
	rep(i,1,n) rep(j,1,n) rep(k,1,n) if (i!=j&&i!=k&&j!=k)
		rep(x,1,6) rep(y,1,6) rep(z,1,6) if (a[i][x])
			buc[a[i][x]*100+a[j][y]*10+a[k][z]]=1;
	int ans=0;
	while (buc[ans+1]) ans++;
	printf("%d",ans);
	return 0;
}