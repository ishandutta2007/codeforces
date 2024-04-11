#include <cstdio>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;
int n, m, s, d, c, e, a[200009], l[200009], r[200009], pl[200009], pr[200009];
int main() {
	scanf("%d %d %d %d", &n, &m, &s, &d);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	sort(a, a + n); c = 1;
	for (int i = 0; i < n; i++) {
		if (!binary_search(a, a + n, a[i] - 1)) l[c] = a[i] - 1;
		if (!binary_search(a, a + n, a[i] + 1)) r[c++] = a[i] + 1;
	}
	int z = 0;
	for (int i = 1; i <= c; i++) {
		if (i == c || l[i] - r[i - 1] >= s) {
			pl[e] = l[z]; pr[e++] = r[i - 1];
			z = i;
		}
	}
	bool f = true;
	for (int i = 0; i < e; i++) {
		if (pr[i] - pl[i] > d) f = false;
	}
	if (pl[0] != pr[0] || !f) printf("IMPOSSIBLE\n");
	else {
		for (int i = 1; i < e; i++) {
			printf("RUN %d\n", pl[i] - pr[i - 1]);
			printf("JUMP %d\n", pr[i] - pl[i]);
		}
		if (pr[e - 1] != m) printf("RUN %d\n", m - pr[e - 1]);
	}
	return 0;
}