#include <vector>
#include <iostream>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;
int n, m, a, b, c[130009], d[130009]; bool ok[130009]; vector<int> g[130009];
void rec1(int pos, int pre) {
	if (ok[pos]) c[pos] = 1;
	for (int i : g[pos]) {
		if (i == pre) continue;
		rec1(i, pos);
		c[pos] += c[i];
	}
}
int rec2(int pos, int pre) {
	int ret = 1;
	for (int i : g[pos]) {
		if (i == pre || c[i] == 0) continue;
		ret += rec2(i, pos);
	}
	return ret;
}
void rec3(int pos, int pre) {
	if (pre == -1) d[pos] = 0;
	for (int i : g[pos]) {
		if (i == pre) continue;
		d[i] = d[pos] + 1;
		rec3(i, pos);
	}
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &a, &b); a--, b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for (int i = 0; i < m; i++) scanf("%d", &a), ok[--a] = true;
	rec1(a, -1);
	int r = 2 * rec2(a, -1) - 2;
	rec3(a, -1);
	for (int i = 0; i < n; i++) {
		if (ok[i] && d[a] < d[i]) a = i;
	}
	rec3(a, -1);
	int b = -1;
	for (int i = 0; i < n; i++) {
		if (ok[i] && (b == -1 || d[b] < d[i])) b = i;
	}
	printf("%d\n", min(a, b) + 1);
	printf("%d\n", r - d[b]);
	return 0;
}