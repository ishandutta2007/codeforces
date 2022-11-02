#include <cmath>
#include <queue>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>
#pragma warning(disable : 4996)
using namespace std;
int n, a[200009], d[200009];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]), a[i]--;
	fill(d + 1, d + n, -1);
	queue<int> que; que.push(0);
	while (!que.empty()) {
		int u = que.front(); que.pop();
		if (d[a[u]] == -1) d[a[u]] = d[u] + 1, que.push(a[u]);
		if (u >= 1 && d[u - 1] == -1) d[u - 1] = d[u] + 1, que.push(u - 1);
		if (u <= n - 2 && d[u + 1] == -1) d[u + 1] = d[u] + 1, que.push(u + 1);
	}
	for (int i = 0; i < n; i++) printf("%d ", d[i]);
	return 0;
}