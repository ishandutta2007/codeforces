//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int n, dp[N], fa[N], dfn[N], id[N], tms, ans[N];
vector<int> e[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
void dfs(int u, int f) {
	fa[u] = f;
	dfn[u] = ++tms;
	id[tms] = u;
	for(auto v : e[u]) {
		if(v == f) continue;
		dfs(v, u);
	}
}
int calc(int k) {
	if(k == 1) return n;
	fill(dp+1, dp+1+n, 1);
	int ans = 0;
	per(i, n, 1) {
		int u = id[i];
		if(dp[u] && dp[fa[u]]) {
			if(dp[u] + dp[fa[u]] >= k) ++ans, dp[fa[u]] = 0;
			else chkmax(dp[fa[u]], dp[u]+1);
		}
	}
	return ans;
}

int main() {
	//ll tm = clock();
	memset(ans, -1, sizeof(ans));
	scanf("%d", &n);
	rep(i, 1, n-1) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1, 0);
	
//	int k = sqrt(n*log2(n));
//	rep(i, 1, k) ans[i] = calc(i);

//	int k = sqrt(n);
//	rep(i, 1, k) ans[i] = calc(i);

	int k = 1, lim = n / sqrt(n);
	for(;k<=n;k++) {
		ans[k] = calc(k);
		if(ans[k] < lim) break;
	}

// 	int k = 1, lim = n / sqrt(n*log2(n));
// 	for(;k<=n;k++) {
// 		ans[k] = calc(k);
// 		if(ans[k] < lim) break;
// 	}

	//fprintf(stderr, "Time used: %.2lfs (%d)\n", (1.0*clock()-tm)/CLOCKS_PER_SEC, k);
	for(int l=k+1,r=0;l<=n;l=r+1) {
		if(!~ans[l]) ans[l] = calc(l);
		int L = l, R = n;
		while(R - L >= 5) {
			int M = (L + R) >> 1;
			if(!~ans[M]) ans[M] = calc(M);
			if(ans[l] == ans[M]) r = M, L = M + 1;
			else R = M - 1;
		}
		rep(i, L, R) {
			if(!~ans[i]) ans[i] = calc(i);
			if(ans[i] == ans[l]) r = i;
		}
		fill(ans+l, ans+1+r, ans[l]);
	}
	rep(i, 1, n) printf("%d%c", ans[i], " \n"[i==n]);
	//fprintf(stderr, "Time used: %.2lfs\n", (1.0*clock()-tm)/CLOCKS_PER_SEC);
	return 0;
}