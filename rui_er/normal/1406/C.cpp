//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int T, n, fa[N], sz[N], maxpart[N];
vector<int> e[N], centroids;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
void dfs(int u, int f) {
	fa[u] = f;
	sz[u] = 1;
	for(int v : e[u]) {
		if(v == f) continue;
		dfs(v, u);
		sz[u] += sz[v];
		chkmax(maxpart[u], sz[v]);
	}
	chkmax(maxpart[u], n-sz[u]);
	if(maxpart[u] <= n / 2) centroids.push_back(u);
}
int findLeaf(int u, int f) {
	for(int v : e[u]) {
		if(v == f) continue;
		return findLeaf(v, u);
	}
	return u;
}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d", &n);
		rep(i, 1, n-1) {
			int u, v;
			scanf("%d%d", &u, &v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfs(1, 0);
		if(centroids.size() == 1) {
			printf("%d %d\n", 1, e[1][0]);
			printf("%d %d\n", 1, e[1][0]);
		}
		else {
			int leaf = findLeaf(centroids[0], centroids[1]);
			printf("%d %d\n", fa[leaf], leaf);
			printf("%d %d\n", centroids[1], leaf);
		}
		rep(i, 1, n) {
			e[i].clear();
			fa[i] = sz[i] = maxpart[i] = 0;
		}
		centroids.clear();
	}
	return 0;
}