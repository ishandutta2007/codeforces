//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e6+5;

int n, fa[N], val[N], sz[N], rt, nd;
vector<int> e[N], ans;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
void dfs(int u) {
	sz[u] = val[u];
	for(int v : e[u]) {
		dfs(v);
		sz[u] += sz[v];
	}
	if(sz[u] == nd) {
		ans.push_back(u);
		sz[u] = 0;
	}
}

int main() {
	scanf("%d", &n);
	rep(i, 1, n) {
		scanf("%d%d", &fa[i], &val[i]);
		if(fa[i]) e[fa[i]].push_back(i);
		else rt = i;
	}
	int sum = accumulate(val+1, val+1+n, 0);
	if(sum % 3) return puts("-1")&0;
	nd = sum / 3;
	dfs(rt);
	if((int)ans.size() <= 2) puts("-1");
	else printf("%d %d\n", ans[0], ans[1]);
	return 0;
}