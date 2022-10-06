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
//udpsum 
const int N = 100005;
int n,a[N],num[N][2];
int head[N],edgenum;
struct Edge {
	int to,nxt;
} edge[N<<1];
ll ans,tot;
inline void addedge(int u, int v) {
	edge[++edgenum]=(Edge){v,head[u]};
	head[u]=edgenum;
}
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
inline void dfs(int u, int fa, int Bit) {
	int tmp=(a[u]>>Bit)&1;
	num[u][tmp]=1; num[u][tmp^1]=0;
	L(i,u) if (edge[i].to!=fa) {
		int v=edge[i].to;
		dfs(edge[i].to,u,Bit);
		tot+=(ll)num[u][1]*num[v][0]+(ll)num[u][0]*num[v][1];
		num[u][1^tmp]+=num[v][1];
		num[u][0^tmp]+=num[v][0];
	}
}
int main() {
//	freopen("1.in","r",stdin);
	read(n);rep(i,1,n)read(a[i]);
	rep(i,1,n-1) {
		int a,b;read(a);read(b);
		addedge(a,b);addedge(b,a);
	}
	rep(i,0,19)	{tot=0;dfs(1,0,i);ans+=(tot<<i);}
	rep(i,1,n) ans+=a[i];
	printf("%lld\n",ans);
	return 0;
}