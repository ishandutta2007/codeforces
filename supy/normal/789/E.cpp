#include<cstdio>
#include<cstring>
#include<iostream>
#include<bitset>
#include<algorithm>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
typedef long long ll;
using namespace std;
#define N 1005
#define M 4000400
int n,k,mx;
int a[M],q[M],dis[2005];
bool vis[2005];
int head[2005],edgenum;
struct Edge {
	int to,nxt;
} edge[M];
inline void add(int u, int v) {
	edge[++edgenum].to=v;
	edge[edgenum].nxt=head[u];
	head[u]=edgenum;
}

inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
bitset <2004> dp[2];
inline int solve() {
	int t=1;
	dp[0][1000]=1;
	rep(i,1,1000) {
		dp[t].reset();
		rep(j,1,k)
			if (a[j]>0) dp[t]|=dp[t^1]<<a[j];
			else dp[t]|=dp[t^1]>>(-a[j]);
		if (dp[t][1000]==1) return i;
		t^=1;
	}
	return -1;
}
int main() {
//	freopen("1.in","r",stdin);
	read(n); read(k);
	rep(i,1,k) read(a[i]); //a[i]-=n;
	rep(i,1,k) vis[a[i]]=1;
	int l=0; rep(i,0,1000) if (vis[i]) a[++l]=i;
	rep(i,1,l) a[i]-=n; k=l;
	printf("%d",solve());
	return 0;
}