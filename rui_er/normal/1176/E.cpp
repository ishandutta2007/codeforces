//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int T, n, m, cnt[2], dis[N];
vector<int> e[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
void dfs(int u, int f) {
	dis[u] = dis[f] + 1;
	++cnt[dis[u] & 1];
	for(int v : e[u]) if(!dis[v]) dfs(v, u);
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
		dfs(1, 0);
		int c = cnt[1] <= n / 2;
		printf("%d\n", cnt[c]);
		rep(i, 1, n) if((dis[i] & 1) == c) printf("%d ", i);
		puts("");
		rep(i, 1, n) {
			e[i].clear();
			dis[i] = 0;
		}
		cnt[0] = cnt[1] = 0;
	}
	return 0;
}