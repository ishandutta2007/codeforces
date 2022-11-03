#include <bits/stdc++.h>

#define debug(x) cout << #x" = " << x;

#define st first
#define nd second

using namespace std;
using namespace placeholders;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

const int MAXN = 4E5 + 10;

int n, n0;
vector<int> E[MAXN];

int size[MAXN];
int m[MAXN][2];
bool ans[MAXN];

void DFS1(int u, int pre){
	size[u] = 1;
	for (int v, i = 0; i < E[u].size(); ++i){
		if ((v = E[u][i]) == pre)
			continue;
		DFS1(v, u);

		size[u] += size[v];
		int t = size[v] <= n0 ? size[v] : m[v][0];
		if (m[u][0] < t)
			m[u][1] = m[u][0], m[u][0] = t;
		else if (m[u][1] < t)
			m[u][1] = t;
	}
}

void DFS2(int u, int pre, int s = 0){
	ans[u] = n - size[u] - s <= n0;
	for (int v, i = 0; i < E[u].size(); ++i){
		if ((v = E[u][i]) == pre)
			continue;
		ans[u] &= size[v] - m[v][0] <= n0;
		DFS2(v, u, n - size[v] <= n0 ? n - size[v] : max(s, (size[v] <= n0 ? size[v] : m[v][0]) != m[u][0] ? m[u][0] : m[u][1]));
	}
}

int main(){
	scanf("%d", &n);
	for (int u, v, i = 1; i < n; ++i){
		scanf("%d%d", &u, &v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	n0 = n >> 1;
	DFS1(1, 0);
	DFS2(1, 0);
	for (int i = 1; i <= n; ++i)
		printf("%d%c", ans[i], "\n "[i < n]);
	return 0;
}