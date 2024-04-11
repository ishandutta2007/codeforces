#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<deque>
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
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rrep(i,n) for(int i = 1; i <= n; ++i)
#define drep(i,n) for(int i = n-1; i >= 0; --i)
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

const int MX = 100005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1}; //<^>v

int n; ll ans;
vi to[MX], co[MX];
int s[MX], sol[MX];
vector<P> cens;
int cen, cen2;

int dfs(int v, int p=-1){
	s[v] = 1;
	int mx = 0;
	rep(i,sz(to[v])) {
		int u = to[v][i];
		if (u == p) continue;
		s[v] += dfs(u,v);
		mx = max(mx,s[u]);
	}
	mx = max(mx,n-s[v]);
	cens.pb(P(mx,v));
	return s[v];
}
int cfs(int v, int p=-1){
	int x = 1;
	rep(i,sz(to[v])) {
		int u = to[v][i];
		if (u == p) continue;
		int r = cfs(u,v);
		ans += (ll)co[v][i]*r;
		x += r;
	}
	return x;
}

int g[MX];
vector<vi> d;
void rfs(int v, int p=-1){
	d.back().pb(v);
	rep(i,sz(to[v])) {
		int u = to[v][i];
		if (u == p) continue;
		rfs(u,v);
	}
}

void calc(){
	rep(i,sz(d))rep(j,sz(d[i])) g[d[i][j]] = i;
	priority_queue<P> qt;
	priority_queue<P,vector<P>,greater<P> > q;
	int rest = n;
	vi xs, xt;
	rep(i,sz(d)) {
		qt.push(P(sz(d[i])*2,i));
		q.push(P(d[i][0],i));
		xs.pb(sz(d[i]));
		xt.pb(sz(d[i]));
	}
	//if (ans > 100000) printf("%d %d\n",q.top().fi,q.top().se);
	rrep(i,n) {
		int gi = g[i];
		while (1) {
			int ni = qt.top().se;
			if (xt[ni]+xs[ni] == qt.top().fi) break;
			qt.pop();
			qt.push(P(xt[ni]+xs[ni],ni));
		}
		while (1) {
			int ni = q.top().se;
			if (xt[ni] && d[ni][sz(d[ni])-xt[ni]] == q.top().fi) break;
			q.pop();
			if (!xt[ni]) continue;
			q.push(P(d[ni][sz(d[ni])-xt[ni]],ni));
		}
		int ti = qt.top().se;
		int qi = q.top().se;
		if (gi == qi && gi) {
			P np = q.top(); q.pop();
			while (1) {
				int ni = q.top().se;
				if (xt[ni] && d[ni][sz(d[ni])-xt[ni]] == q.top().fi) break;
				q.pop();
				if (!xt[ni]) continue;
				q.push(P(d[ni][sz(d[ni])-xt[ni]],ni));
			}
			qi = q.top().se;
			q.push(np);
		}
		int j = qi;
		if (ti != qi && ti && ti != gi) {
			if (rest-1 < xt[ti]+xs[ti]) j = ti;
		}
		sol[i] = d[j][sz(d[j])-xt[j]];
		xs[gi]--; xt[j]--;
		rest--;
		//rep(j,sz(d)) printf("%d : %d %d\n",j,xs[j],xt[j]);puts("");
	}
}

int main(){
	scanf("%d",&n);
	if (n == 1) {
		puts("0\n1");
		return 0;
	}
	rep(i,n-1) {
		int a, b, c;
		scanf("%d%d%d",&a,&b,&c);
		to[a].pb(b); co[a].pb(c);
		to[b].pb(a); co[b].pb(c);
	}
	dfs(1);
	sort(rng(cens));
	cen = cens[0].se;
	if (cens[0].fi == cens[1].fi) cen2 = cens[1].se; else cen2 = -1;
	cfs(cen,cen2);
	if (cen2 != -1) {
		cfs(cen2,cen);
		int cost = 0;
		rep(i,sz(to[cen])){
			if (to[cen][i] == cen2) cost = co[cen][i];
		}
		ans += (ll)cost*n/2;
	}
	ans *= 2;
	//cout << cen << " " << cen2 << endl;
	if (cen2 == -1) {
		d.pb(vi(1,cen));
		rep(i,sz(to[cen])) {
			d.pb(vi());
			rfs(to[cen][i],cen);
		}
		rep(i,sz(d)) sort(rng(d[i]));
		calc();
	} else {
		d.pb(vi());
		rfs(cen,cen2);
		d.pb(vi());
		rfs(cen2,cen);
		sort(rng(d[0]));
		sort(rng(d[1]));
		rep(i,2)rep(j,sz(d[i])) g[d[i][j]] = i;
		int di[2];
		di[0] = 0; di[1] = 0;
		rrep(i,n) {
			int gi = g[i]^1;
			sol[i] = d[gi][di[gi]++];
		}
	}
	//if (ans > 10000) printf("%d %d : %d %d %d\n",cen,cen2,g[1],g[108],g[2]);
	//if (ans > 10000) printf(" : %d %d %d\n",sz(d[g[1]]),sz(d[g[108]]),sz(d[g[2]]));
	cout << ans << endl;
	rrep(i,n) printf("%d%c",sol[i],i==n?'\n':' ');
	
	return 0;
}