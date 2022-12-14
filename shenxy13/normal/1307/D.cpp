#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> ii;
int main() {
	int n, m, k, x, y;
	scanf("%d %d %d", &n, &m, &k);
	int a[k];
	for (int i = 0; i < k; ++i) scanf("%d", &a[i]), --a[i];
	vector<int> adjlist[n];
	for (int i = 0; i < m; ++i) {
		scanf("%d %d", &x, &y);
		adjlist[x - 1].push_back(y - 1);
		adjlist[y - 1].push_back(x - 1);
	}
	int sp1[n], sp2[n];
	queue<int> bfs;
	fill_n(sp1, n, -1);
	sp1[0] = 0;
	bfs.push(0);
	while (!bfs.empty()) {
		int v = bfs.front();
		bfs.pop();
		for (int i: adjlist[v]) {
			if (sp1[i] != -1) continue;
			sp1[i] = sp1[v] + 1;
			bfs.push(i);
		}
	}
	fill_n(sp2, n, -1);
	sp2[n - 1] = 0;
	bfs.push(n - 1);
	while (!bfs.empty()) {
		int v = bfs.front();
		bfs.pop();
		for (int i: adjlist[v]) {
			if (sp2[i] != -1) continue;
			sp2[i] = sp2[v] + 1;
			bfs.push(i);
		}
	}
	int ans = 0;
	ii smth[k];
	for (int i = 0; i < k; ++i) smth[i] = ii(sp1[a[i]] - sp2[a[i]], a[i]);
	sort(smth, smth + k);
	int pfx[k], sfx[k];
	pfx[0] = sp1[smth[0].second];
	for (int i = 1; i < k; ++i) pfx[i] = max(pfx[i - 1], sp1[smth[i].second]);
	sfx[k - 1] = sp2[smth[k - 1].second];
	for (int i = k - 2; i >= 0; --i) sfx[i] = max(sfx[i + 1], sp2[smth[i].second]);
	ans = sfx[1] + sp1[smth[0].second];
	for (int i = 1; i < k - 1; ++i) ans = max(ans, max(pfx[i - 1] + sp2[smth[i].second], sfx[i + 1] + sp1[smth[i].second]));
	ans = max(ans, pfx[k - 2] + sp2[smth[k - 1].second]);
	printf("%d", min(ans + 1, sp2[0]));
	return 0;
}