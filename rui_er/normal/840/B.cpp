//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 3e5+5;

int n, m, d[N], vis[N], ok, sum, rt = 1;
vector<int> ans;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct Edge {
	int v, nxt, id;
	Edge(int a=0, int b=0, int c=0) : v(a), nxt(b), id(c) {}
	~Edge() {}
}e[N<<1];
int h[N], ne = 1;
void add(int u, int v, int id) {
	e[++ne] = Edge(v, h[u], id); h[u] = ne;
	e[++ne] = Edge(u, h[v], id); h[v] = ne;
}
int dfs(int u) {
	vis[u] = 1;
	int now = 0;
	for(int i=h[u];i;i=e[i].nxt) {
		int v = e[i].v, id = e[i].id;
		if(vis[v]) continue;
		if(dfs(v)) {
			ans.push_back(id);
			now ^= 1;
		}
	}
	if(!~d[u]) return 0;
	return now ^ d[u];
}

int main() {
	scanf("%d%d", &n, &m);
	rep(i, 1, n) {
		scanf("%d", &d[i]);
		if(!~d[i]) ok = 1, rt = i;
		else sum ^= d[i];
	}
	ok |= !sum;
	if(!ok) return puts("-1")&0;
	rep(i, 1, m) {
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, v, i);
	}
	dfs(rt);
	printf("%d\n", (int)ans.size());
	for(auto i : ans) printf("%d\n", i);
	return 0;
}