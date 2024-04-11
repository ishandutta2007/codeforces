#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	int n, m; scanf("%d %d", &n, &m);
	vector<int> games(n);
	vector<int> bills(m);
	for (int i = 0; i < n; ++i) scanf("%d", &games[i]);
	for (int i = 0; i < m; ++i) scanf("%d", &bills[i]);
	queue<int> billLine;
	for (int i : bills) billLine.push(i);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (billLine.empty() or billLine.front() < games[i]) continue;
		if (billLine.front() >= games[i]) {
			billLine.pop();
			++ans;
		}
	}
	printf("%d\n", ans);
	return 0;
}