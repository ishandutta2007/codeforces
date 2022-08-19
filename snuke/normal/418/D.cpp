#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<string>
#include<string.h>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<map>
#include<set>
#include<iostream>
#include<sstream>
#include<cctype>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; i++)
#define rrep(i,n) for(int i = 1; i <= n; i++)
#define drep(i,n) for(int i = n-1; i >= 0; i--)
#define gep(i,g,j) for(int i = g.head[j]; i != -1; i = g.e[i].next)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y)
#define mins(x,y) x = min(x,y)
#define pb push_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcount
#define snuke srand((unsigned)clock()+(unsigned)time(NULL))
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;

const int MX = 200005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1}; //<^>v

/* debug output
#define pri(...) fprintf(stderr,"Debug: " __VA_ARGS__)
//*/#define pri(...)

vi to[MX];
vector<P> l[MX];
int dep[MX], tp[MX];
int pa[18][MX];
int dp[18][MX];
int pd[18][MX];

int dfs(int v, int nd=0, int p=0) {
	dep[v] = nd;
	pa[0][v] = p;
	l[v].pb(P(0,-1));
	for (int u : to[v]) {
		if (u == p) continue;
		l[v].pb(P(dfs(u,nd+1,v),u));
	}
	sort(rng(l[v]));
	reverse(rng(l[v]));
	return l[v][0].fi+1;
}
void rfs(int v, int mx=0, int p=0) {
	tp[v] = mx;
	for(int u : to[v]) {
		if (u == p) continue;
		int nx = 0;
		if (l[v][0].se != u) nx = l[v][0].fi;
		else nx = l[v][1].fi;
		nx = max(nx,mx);
		rfs(u,nx+1,v);
	}
}

int main(){
	int n;
	scanf("%d",&n);
	rep(i,n-1){
		int a, b;
		scanf("%d%d",&a,&b);
		to[a].pb(b);
		to[b].pb(a);
	}
	dfs(1); rfs(1);
	l[0].pb(P(0,-1));
	rrep(i,n) {
		{
			int p = pa[0][i];
			int x = l[p][0].fi;
			if (l[p][0].se == i) x = l[p][1].fi;
			dp[0][i] = pd[0][i] = x;
		}
		{
			pa[0][n+i] = i;
			dep[n+i] = dep[i]+1;
			dp[0][n+i] = pd[0][n+i] = l[i][0].fi;
		}
	}
	rep(i,18) dp[i][0] = pd[i][0] = -INF;
	rep(i,17)rrep(j,n*2) {
		int p = pa[i][j];
		pa[i+1][j] = pa[i][p];
		dp[i+1][j] = max(dp[i][j],dp[i][p]+(1<<i));
		pd[i+1][j] = max(pd[i][j],pd[i][p]-(1<<i));
	}

	int q;
	scanf("%d",&q);
	rep(qi,q) {
		int a, b, c;
		scanf("%d%d",&a,&b);
		if (dep[a] < dep[b]) swap(a,b);
		{
			int d = dep[a]-dep[b], na = a;
			drep(i,18) {
				if (d >= 1<<i) {
					d -= 1<<i;
					na = pa[i][na];
				}
			}
			int nb = b;
			drep(i,18) {
				if (pa[i][na] != pa[i][nb]) {
					na = pa[i][na];
					nb = pa[i][nb];
				}
			}
			c = na==nb?na:pa[0][na];
		}
		int la = dep[a]-dep[c];
		int lb = dep[b]-dep[c];
		int len = la+lb;
		int lena = (len+1)/2, lenb = len-lena;
		int ans = 0;
		pri("%d %d %d %d\n",la,lb,c,lena);
		int v0, v1, v2;
		{
			int d = lena, v = n+a, nd = 0, r = -INF;
			drep(i,18) {
				if (d >= 1<<i) {
					r = max(r, dp[i][v]+nd);
					d -= 1<<i; nd += 1<<i;
					v = pa[i][v];
				}
			}
			pri("%d\n", r);
			ans = max(ans, r);
			v0 = v;
		}
		{
			int d = lb, v = n+b, nd = 0, r = -INF;
			drep(i,18) {
				if (d >= 1<<i) {
					r = max(r, dp[i][v]+nd);
					d -= 1<<i; nd += 1<<i;
					v = pa[i][v];
				}
			}
			pri("%d\n", r);
			ans = max(ans, r);
			v1 = v;
		}
		{
			int d = lenb-lb, v = v0, nd = 0, r = -INF;
			drep(i,18) {
				if (d >= 1<<i) {
					r = max(r, pd[i][v]-nd);
					d -= 1<<i; nd += 1<<i;
					v = pa[i][v];
				}
			}
			pri("%d %d\n", r, r+lb+(dep[v0]-dep[v]));
			ans = max(ans, r+lb+(dep[v0]-dep[v]));
			v2 = v;
		}
		{
			ans = max(ans, lb+tp[c]);
			pri("%d %d\n",lb,tp[c]);
			int i = 0;
			while (l[c][i].se == v1 || l[c][i].se == v2) ++i;
			pri("%d %d %d\n", v1, v2, i);
			ans = max(ans, lb+l[c][i].fi);
		}
		printf("%d\n",ans);
	}
	
	return 0;
}