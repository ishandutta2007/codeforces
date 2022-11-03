#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 1E6 + 10;

int n, m;
ll deg[MAXN];
int vis[MAXN], fa[MAXN];

int find(int x){
	return x == fa[x] ? x : (fa[x] = find(fa[x]));
}

int main(){
	scanf("%d%d", &n, &m);
	ll self = 0;
	for (int i = 1; i <= n; ++i)
		fa[i] = i;
	for (int u, v, i = 0; i < m; ++i){
		scanf("%d%d", &u, &v);
		vis[u] = vis[v] = true;
		if (u == v){
			++self;
			continue;
		}
		++deg[u], ++deg[v];
		u = find(u), v = find(v);
		if (u != v)
			fa[u] = v;
	}
	int rt = find(find(vis + 1, vis + n + 1, true) - vis);
	for (int i = 1; i <= n; ++i)
		if (vis[i] && find(rt) != find(i)){
			puts("0");
			return 0;
		}
	ll ans = self * (self - 1) / 2 + self * (m - self);
	for (int i = 1; i <= n; ++i)
		ans += deg[i] * (deg[i] - 1) / 2;
	printf("%lld\n", ans);
	return 0;
}