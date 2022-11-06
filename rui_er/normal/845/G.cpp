//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int n, m, dis[N], vis[N];
vector<tuple<int, int> > e[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct LinearBasis {
	int p[31];
	LinearBasis() {memset(p, 0, sizeof(p));}
	~LinearBasis() {}
	void insert(int x) {
		per(i, 30, 0) {
			if(!((x >> i) & 1)) continue;
			if(!p[i]) {p[i] = x; return;}
			x ^= p[i];
		}
	}
	int qmin(int v=0) {
		int ans = v;
		per(i, 30, 0) chkmin(ans, ans^p[i]);
		return ans;
	}
}LB;
void dfs(int u, int now) {
	dis[u] = now;
	vis[u] = 1;
	for(auto i : e[u]) {
		int v = get<0>(i);
		int w = get<1>(i);
		if(!vis[v]) dfs(v, now^w);
		else LB.insert(dis[u]^dis[v]^w);
	}
}

int main() {
	scanf("%d%d", &n, &m);
	rep(i, 1, m) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		e[u].push_back(make_tuple(v, w));
		e[v].push_back(make_tuple(u, w));
	}
	dfs(1, 0);
	printf("%d\n", LB.qmin(dis[n]));
    return 0;
}