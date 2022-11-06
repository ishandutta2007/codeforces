//By: Luogu@rui_er(122461).
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int n, a[N], lc[N], rc[N], isroot[N];
map<int, int> mp;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
void dfs(int u, int l, int r) {
	if(l <= a[u] && a[u] <= r) mp[a[u]] = 1;
	if(lc[u] > -1) dfs(lc[u], l, min(a[u], r));
	if(rc[u] > -1) dfs(rc[u], max(a[u], l), r);
}

int main() {
	scanf("%d", &n);
	rep(i, 1, n) isroot[i] = 1;
	rep(i, 1, n) {
		scanf("%d%d%d", &a[i], &lc[i], &rc[i]);
		if(lc[i] > -1) isroot[lc[i]] = 0;
		if(rc[i] > -1) isroot[rc[i]] = 0;
	}
	int rt = 0, ans = 0;
	rep(i, 1, n) if(isroot[i]) {rt = i; break;}
	dfs(rt, 0, 1000000000);
	rep(i, 1, n) if(!mp[a[i]]) ++ans;
	printf("%d\n", ans);
    return 0;
}