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
const int N = 35;
int n,mtr[N][7],x[N],y[N];

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
inline void dfs(int u, int dir, int fa, int len) {
	int P=0;
//	printf("%d %d %d %d\n",u,dir,fa,len);
	rep(i,1,mtr[u][0]) if (mtr[u][i]!=fa) {
		int v=mtr[u][i];
		if (P==dir) P++;
		x[v]=x[u]+dx[P]*len; y[v]=y[u]+dy[P]*len;
		dfs(v,P^1,u,len>>1);
		P++;
	}
}
bool ok() {
	rep(i,1,n-1) {
		int a,b; read(a);read(b);
		mtr[a][++mtr[a][0]]=b;
		mtr[b][++mtr[b][0]]=a;
		if (mtr[a][0]>4||mtr[b][0]>4) return 0;
	}
	x[1]=y[1]=0; dfs(1,-1,-1,1<<(n-2));
	puts("YES"); return 1;
}
int main() {
//	freopen("1.in","r",stdin);
	read(n);
	if (!ok()) puts("NO");
	else rep(i,1,n) printf("%d %d\n",x[i],y[i]);
	return 0;
}