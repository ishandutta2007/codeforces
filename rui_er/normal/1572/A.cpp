//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int T, n, deg[N], dp[N];
vector<int> e[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
int toposort() {
	queue<int> q;
	int tot = 0;
	rep(i, 1, n) {
		if(!deg[i]) {
			q.push(i);
			dp[i] = 1;
			++tot;
		}
	}
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(auto v : e[u]) {
			chkmax(dp[v], dp[u]+(v<u));
			if(!--deg[v]) {
				q.push(v);
				++tot;
			}
		}
	}
	if(tot < n) return -1;
	int ans = 0;
	rep(i, 1, n) chkmax(ans, dp[i]);
	return ans;
}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d", &n);
		rep(i, 1, n) {
			int k;
			scanf("%d", &k);
			rep(j, 1, k) {
				int t;
				scanf("%d", &t);
				e[t].push_back(i);
				++deg[i];
			}
		}
		printf("%d\n", toposort());
		rep(i, 1, n) {
			e[i].clear();
			deg[i] = 0;
			dp[i] = 0;
		} 
	}
	return 0;
}