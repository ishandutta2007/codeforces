//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 3e5+5, mod = 998244353;

int T, n, m, col[N], sz[N][2], isrt[N];
vector<int> e[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
bool dfs(int u, int c, int rt) {
	col[u] = c;
	++sz[rt][c];
	isrt[rt] = 1;
	for(int v : e[u]) {
		if(col[v] == -1) {
			if(!dfs(v, c^1, rt)) return 0;
		}
		else if(col[v] == col[u]) return 0;
	}
	return 1;
}
int qpow(int x, int y) {
	int ans = 1;
	for(;y;y>>=1,x=1LL*x*x%mod) if(y & 1) ans = 1LL * ans * x % mod;
	return ans;
}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d%d", &n, &m);
		rep(i, 1, m) {
			int u, v;
			scanf("%d%d", &u, &v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		rep(i, 1, n) col[i] = -1;
		int ok = 1;
		rep(i, 1, n) if(col[i] == -1) ok &= dfs(i, 0, i);
		if(!ok) puts("0");
		else {
			int ans = 1;
			rep(i, 1, n) if(isrt[i]) ans = 1LL * (qpow(2, sz[i][0]) + qpow(2, sz[i][1])) % mod * ans % mod;
			printf("%d\n", ans);
		}
		rep(i, 1, n) {
			isrt[i] = sz[i][0] = sz[i][1] = 0;
			e[i].clear();
		}
	}
	return 0;
}