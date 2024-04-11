#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	int a[n];
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	vector<int> adjlist[n + 2];
	int sp[2][n + 2];
	for (int i = 0; i < n; ++i) {
		if (a[i] % 2) adjlist[n].push_back(i);
		else adjlist[n + 1].push_back(i);
		if (i - a[i] >= 0) adjlist[i - a[i]].push_back(i);
		if (i + a[i] < n) adjlist[i + a[i]].push_back(i);
	}
	for (int i = 0; i < 2; ++i) {
		queue<int> bfs;
		fill_n(sp[i], n + 2, -1);
		sp[i][n + i] = 0;
		bfs.push(n + i);
		while (!bfs.empty()) {
			int x = bfs.front();
			bfs.pop();
			for (int j: adjlist[x]) {
				if (sp[i][j] != -1) continue;
				sp[i][j] = sp[i][x] + 1;
				bfs.push(j);
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		if (sp[a[i] % 2][i] == -1) printf("-1 ");
		else printf("%d ", sp[a[i] % 2][i] - 1);
	}
	return 0;
}