#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
typedef long long ll;
using namespace std;
#define N 300005
int n,a[N],size;
int head[N],edgenum;
int vis[N];
struct Edge
{
	int to,nxt;
} edge[N<<1];
struct E {
	int v,p;
} s[N];
inline void add(int u, int v)
{
	edge[++edgenum].to=v;
	edge[edgenum].nxt=head[u];
	head[u]=edgenum;
}
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
int cmp(E x, E y) {
	return x.v>y.v;
}
int solve() {
	for (size=1; size<n; size++)
		if (s[size].v!=s[size+1].v) break;
	if (size==1) {
		int u=s[1].p;
		if (n==1||s[size+1].v<s[1].v-1) return s[1].v; //
		int s1;
		for (s1=size+1; s1<n; s1++)
			if (s[s1].v!=s[s1+1].v) break;
		for (int i=head[u]; i!=0; i=edge[i].nxt)
			vis[edge[i].to]=1;
		rep(i,size+1,s1) if (!vis[s[i].p]) return s[1].v+1;
		return s[1].v;
	}
//	rep(i,1,size) printf("%d ",s[i].p); puts("");
	rep(u,1,n) {
		vis[u]=u;
		for (int i=head[u]; i!=0; i=edge[i].nxt)
			vis[edge[i].to]=u;
	//	printf("%d:",u);
	//	rep(i,1,n) printf("%d ",vis[i]==u); puts("");
		bool flag=1;
		rep(i,1,size) if (vis[s[i].p]!=u) {flag=0; break;}
		if (flag) return s[1].v+1;
	}
	return s[1].v+2;
}
int main() {
	read(n);
	rep(i,1,n) read(s[i].v);
	rep(i,1,n) s[i].p=i;
	rep(i,1,n-1) {
		int x,y; read(x); read(y);
		add(x,y); add(y,x);
	}
	sort(s+1,s+n+1,cmp);
	printf("%d",solve());
	return 0;
}