#include <bits/stdc++.h>
using namespace std;

#define pb push_back
const int N = 2e5L + 11;
int c[N];
vector <int> e[N];

vector <int> ans;
void dfs(int x, int p) {
	ans.pb(x);
	for(int i : e[x]) if(i != p) {
		dfs(i, x);
		ans.pb(x);
		if(c[i] == -1) {
			ans.pb(i);
			ans.pb(x);
			c[i] = -c[i];
			c[x] = -c[x];
		}
	}
}

int main() {
	int n; cin >> n;
	for(int i = 1; i <= n; i ++)
		scanf("%d", c + i);
	for(int i = 1; i < n; i ++) {
		int u, v; scanf("%d%d", &u, &v);
		e[u].pb(v); e[v].pb(u);
		c[u] = -c[u]; c[v] = -c[v];
	}
	dfs(1, 0);
	if(c[1] == -1) {
		ans.pb(e[1][0]);
		ans.pb(1);
		ans.pb(e[1][0]);
	}
	for(int x : ans)
		printf("%d ", x);
	puts("");
}