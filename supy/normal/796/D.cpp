#include<cstdio>
#include<cstring>
#include<iostream>
#include<utility>
#include<algorithm>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define fi first //Be careful
#define se second
using namespace std;
typedef pair<int,int> pr; //from,now
typedef long long ll;
#define N 300005
int n,k,d,size;
bool P[N],isans[N];
pr q[N<<1],u,v;
int head[N],edgenum,vis[N];
struct Edge
{
	int to,nxt;
} edge[N<<1];
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
inline void bfs() {
	int f=0,r=0;
	rep(i,1,n) if (P[i]) {
		u.fi=u.se=i; q[r++]=u; vis[i]=i;
	}
	while (f!=r) {
		u=q[f++];
		for (int i=head[u.se]; i!=0; i=edge[i].nxt)
			if (vis[edge[i].to]!=u.fi) { //detail
				if (!vis[edge[i].to]) {
					v.fi=u.fi; v.se=edge[i].to; 
					q[r++]=v; vis[edge[i].to]=v.fi;
				}
				else isans[(i+1)>>1]=1;
			}
	}
}
int main() {
	read(n); read(k); read(d);
	rep(i,1,k) {int x; read(x); P[x]=1;}
	rep(i,1,n-1) {
		int x,y; read(x); read(y);
		add(x,y); add(y,x);
	}
	bfs();
	rep(i,1,n) if (P[i]) size++; size--;
	printf("%d\n",size);
	rep(i,1,n) if (isans[i]) printf("%d ",i);
	return 0;
}