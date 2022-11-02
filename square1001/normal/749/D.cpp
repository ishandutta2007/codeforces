#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n, q, m, a[200009], b[200009], c[200009], r[200009], p[200009], id[5]; bool ok[200009]; vector<int> g[200009];
bool compare(int i, int j) {
	return r[i] > r[j];
}
int main() {
	scanf("%d", &n);
	fill(r, r + n, -1);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a[i], &b[i]); a[i]--;
		g[a[i]].push_back(i);
		r[a[i]] = p[i] = i;
	}
	sort(p, p + n, compare);
	scanf("%d", &q);
	while (q--) {
		scanf("%d", &m);
		for (int i = 0; i < m; i++) scanf("%d", &c[i]), ok[--c[i]] = true;
		id[0] = id[1] = -1;
		int cnt = 0;
		for (int i = 0; i < n && cnt < 2; i++) {
			if (!ok[p[i]]) id[cnt++] = r[p[i]];
		}
		if (id[0] == -1) puts("0 0");
		else {
			int w = a[id[0]];
			int ptr = lower_bound(g[w].begin(), g[w].end(), id[1]) - g[w].begin();
			printf("%d %d\n", w + 1, b[g[w][ptr]]);
		}
		for (int i = 0; i < m; i++) ok[c[i]] = false;
	}
	return 0;
}