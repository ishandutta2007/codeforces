#include <stdio.h>
#include <vector>
#define N 2010

using namespace std;

vector <int> v[N], rv[N];
bool vis[N], rvis[N];

void dfs(int u) {
	vis[u]=1;
	int i, j;
	for (i=0; i<v[u].size(); i++) {
		j=v[u][i];
		if (!vis[j]) dfs(j);
	}
}

void rdfs(int u) {
	rvis[u]=1;
	int i, j;
	for (i=0; i<rv[u].size(); i++) {
		j=rv[u][i];
		if (!rvis[j]) rdfs(j);
	}
}

int main() {
	int n, i, j, k;
//	freopen ("in.txt", "r", stdin);
	scanf("%d", &n);
	for (i=1; i<=n; i++) for (j=1; j<=n; j++) {
		scanf("%d", &k);
		if (k) {
			v[i].push_back(j);
			rv[j].push_back(i);
		}
	}
	dfs(1);
	rdfs(1);
	for (i=1; i<=n; i++) if (!vis[i] || !rvis[i]) break;
	if (i<=n) puts("NO");
	else puts("YES");
}