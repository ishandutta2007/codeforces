#include<bits/stdc++.h>
using namespace std;

#define N 50505
#define M 505

int n, k;
vector<int>g[N];

int d[N][M];
#define ll long long
ll ans;

void dfs(int u, int pa) {
	for (auto v : g[u]) {
		if (v == pa) continue;
		dfs(v, u);
		for (int i = 0; i < k; i ++) d[u][i+1] += d[v][i];
	}
	d[u][0] = 1;
	int up = (k - 1) / 2;
	ans += d[u][k];
	for (int i = 1; i <= up; i ++) {
		for (auto v : g[u]) {
			if (v == pa) continue;
			ans += 1ll * d[v][k-i-1] * (d[u][i] - d[v][i-1]);
		}
	}
	if (k % 2 == 0) {
		ll tmp = 0;
		for (auto v : g[u]) {
			if (v == pa) continue;
			tmp += 1ll * d[v][k/2-1] * (d[u][k/2] - d[v][k/2-1]);
		}
		ans += tmp / 2;
	}

}

int main() {
	scanf("%d%d", &n, &k);
	int m = n - 1;
    int u, v;
    while (m --) {
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
    }
    dfs(1, 0);
    cout<<ans<<endl;
}