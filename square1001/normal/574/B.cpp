#include <cstdio>
#include <algorithm>
using namespace std;
const int inf = 1012345678;
int n, m, a[4009], b[4009], c[4009]; bool g[4009][4009];
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a[i], &b[i]); a[i]--, b[i]--;
		c[a[i]]++; c[b[i]]++; g[a[i]][b[i]] = g[b[i]][a[i]] = true;
	}
	int ret = inf;
	for (int i = 0; i < m; i++) {
		for (int j = i + 1; j < m; j++) {
			if (a[i] == a[j] && g[b[i]][b[j]]) ret = min(ret, c[a[i]] + c[b[i]] + c[b[j]] - 6);
			if (a[i] == b[j] && g[a[j]][b[i]]) ret = min(ret, c[a[i]] + c[a[j]] + c[b[i]] - 6);
			if (b[i] == a[j] && g[b[j]][a[i]]) ret = min(ret, c[b[i]] + c[b[j]] + c[a[i]] - 6);
			if (b[i] == b[j] && g[a[i]][a[j]]) ret = min(ret, c[b[i]] + c[a[i]] + c[a[j]] - 6);
		}
	}
	printf(ret == inf ? "-1\n" : "%d\n", ret);
	return 0;
}