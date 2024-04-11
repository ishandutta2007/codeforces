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
#define N 200005
int head[N],edgenum;
struct Edge {
	int to,nxt;
} edge[N<<1];
int n,c[N];
inline void addedge(int u, int v) {
	edge[++edgenum].to=v;
	edge[edgenum].nxt=head[u];
	head[u]=edgenum;
}


inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
int size[N],ok[N],ans;
void dfs(int u, int fa) {
	size[u]=1; bool flag=1;
	L(i,u) if (edge[i].to!=fa) {
		dfs(edge[i].to,u);
		size[u]+=size[edge[i].to];
		if (!ok[edge[i].to]||c[edge[i].to]!=c[u]) flag=0;
	}
	ok[u]=flag;
}
int buc[N],tot;
void dfs1(int u, int fa) {
//	printf("%d %d %d %d \n",u,buc[1],buc[2],buc[3]);
	bool flag=1; int tmp=tot;
	L(i,u) if (edge[i].to!=fa) {
		if (ok[edge[i].to]==0) {flag=0;break;}
	}
	if (flag) {
		L(i,u) if (edge[i].to!=fa) {
			buc[c[edge[i].to]]-=size[edge[i].to];
			if (!buc[c[edge[i].to]]) tmp--;
		}
		buc[c[u]]--; if (buc[c[u]]==0) tmp--;
	//	printf(" %d %d\n",tot,tmp);
		if (tmp<=1){ans=u; return;}
		L(i,u) if (edge[i].to!=fa) {
			buc[c[edge[i].to]]+=size[edge[i].to];
		}
		buc[c[u]]++;
	}
	L(i,u) if (edge[i].to!=fa) dfs1(edge[i].to,u);
}
int main() {
//	freopen("1.in","r",stdin);
	read(n);
	rep(i,1,n-1) {
		int a,b;read(a);read(b);
		addedge(a,b);addedge(b,a);
	}
	rep(i,1,n)read(c[i]);
	rep(i,1,n) {if (!buc[c[i]])tot++; buc[c[i]]++;}
	dfs(1,-1);
	dfs1(1,-1);
	if (ans)printf("YES\n%d",ans); else puts("NO");
	return 0;
}