// Problem: CF721C Journey
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF721C
// Memory Limit: 250 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 5e3+5, inf = 0x3f3f3f3f;

int n, m, k, dp[N][N], deg[N];
vector<tuple<int, int> > e[N], et[N];
stack<int> ans;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
void toposort() {
	memset(dp, 0x3f, sizeof(dp));
	dp[1][1] = 0;
	queue<int> q;
	rep(i, 1, n) if(!deg[i]) q.push(i);
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(auto _ : e[u]) {
			int v = get<0>(_), w = get<1>(_);
			rep(i, 1, n) chkmin(dp[v][i], dp[u][i-1] + w);
			if(!--deg[v]) q.push(v);
		}
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	rep(i, 1, m) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		e[u].emplace_back(v, w);
		et[v].emplace_back(u, w);
		++deg[v];
	}
	toposort();
	int t = 0;
	per(i, n, 2) {
		if(dp[n][i] <= k) {
			t = i;
			break;
		}
	}
	printf("%d\n", t);
	int u = n;
	ans.push(u);
	while(u != 1) {
		for(auto _ : et[u]) {
			int v = get<0>(_), w = get<1>(_);
			if(dp[v][t-1] + w == dp[u][t]) {
				u = v;
				break;
			}
		}
		ans.push(u);
		--t;
	}
	while(!ans.empty()) {
		printf("%d ", ans.top());
		ans.pop();
	}
	return 0;
}