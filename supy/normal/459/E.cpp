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
const int N = 300400;
int n,m,ans[N],len;
struct Edge {
	int u,v,d;
} edge[N];
struct Que {
	int dot,val;
} q[N];


inline void LOCAL() {freopen("1.in","r",stdin);}
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (c<'0'||c>'9') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=10*x+c-'0'; c=getchar();} x*=f;
}
inline bool cmp(Edge a, Edge b) {return a.d<b.d;}
int main() {
	read(n); read(m);
	rep(i,1,m) {read(edge[i].u); read(edge[i].v); read(edge[i].d);}
	sort(edge+1,edge+m+1,cmp);
	rep(i,1,m) {
		len=0; int j;
		for (j=i; j<=m; j++)
			if (edge[j].d!=edge[i].d) break;
			else {
				q[++len].dot=edge[j].v;
				q[len].val=ans[edge[j].u]+1;
			}
		i=j-1;
		for (int k=1; k<=len; k++) //attention!!
			ans[q[k].dot]=max(ans[q[k].dot],q[k].val);
	}
//	rep(i,1,n) printf("%d\n",ans[i]);
	int res=0; rep(i,1,n) res=max(res,ans[i]); printf("%d",res);
	return 0;
}