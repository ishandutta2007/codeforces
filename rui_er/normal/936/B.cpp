//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int n, m, s, vis[N][2], from[N][2], ok[N], ins[N];
vector<int> e[N];
stack<int> path;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
bool dfs(int u, int f, int k) {
	bool res = 0;
	vis[u][k] = 1;
	from[u][k] = f;
	ins[u] = 1;
	path.push(u);
	for(auto v : e[u]) {
		if(!vis[v][k^1]) {
			res |= dfs(v, u, k^1);
		}
		else if(ins[v]) res |= 1;
	}
	ins[u] = 0;
	path.pop();
	return res;
}
void find(int u, int k) {
	if(!u) return;
	find(from[u][k], k^1);
	printf("%d ", u);
}

int main() {
	scanf("%d%d", &n, &m);
	rep(i, 1, n) {
		int k, x;
		for(scanf("%d", &k);k;k--) {
			scanf("%d", &x);
			e[i].push_back(x);
		}
		if(e[i].empty()) ok[i] = 1;
	}
	scanf("%d", &s);
	bool qwq = dfs(s, 0, 0);
	rep(i, 1, n) {
		if(ok[i] && vis[i][1]) {
			puts("Win");
			find(i, 1);
			return 0;
		}
	}
	puts(qwq?"Draw":"Lose");
	return 0;
}