//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 5e3+5;

int n, m, n1, n2, n3, col[N], sz[N], prt[N], dp[N][N], ans[N];
vector<int> e[N], rts;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
bool dfs1(int u, int c, int rt) {
	col[u] = c;
	++sz[rt];
	prt[rt] += c;
	for(auto v : e[u]) {
		if(~col[v]) {
			if(col[v] != (c ^ 1)) return 0;
		}
		else {
			if(!dfs1(v, c^1, rt)) return 0;
		}
	}
	return 1;
}
void dfs2(int u, int c) {
	if(col[u] == c) ans[u] = 2, --n2;
	else if(n1) ans[u] = 1, --n1;
	else ans[u] = 3, --n3;
	for(auto v : e[u]) if(!ans[v]) dfs2(v, c);
}

int main() {
	memset(col, -1, sizeof(col));
	scanf("%d%d%d%d%d", &n, &m, &n1, &n2, &n3);
	rep(i, 1, m) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	rep(i, 1, n) {
		if(!~col[i]) {
			if(!dfs1(i, 0, i)) return puts("NO")&0;
			rts.push_back(i);
		}
	}
	int tot = rts.size();
	dp[0][0] = 1;
	rep(i, 0, tot-1) {
		int u = rts[i];
//		printf("%d : %d %d\n", u, prt[u], sz[u]);
		rep(j, 0, n) {
			dp[i+1][j+prt[u]] |= dp[i][j];
			dp[i+1][j+sz[u]-prt[u]] |= dp[i][j];
		}
	}
	if(!dp[tot][n2]) return puts("NO")&0;
	puts("YES");
	per(i, tot, 1) {
		int u = rts[i-1];
		if(dp[i-1][n2-prt[u]]) dfs2(u, 1);
		else dfs2(u, 0);
	}
	rep(i, 1, n) printf("%d", ans[i]);
	return 0;
}