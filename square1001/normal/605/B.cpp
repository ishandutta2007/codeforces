#include <cstdio>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;
int n, m, a[100009], b[100009], x[100009], y[100009], p[100009];
bool compare(int i, int j) {
	if (x[i] != x[j]) return x[i] < x[j];
	return y[i] > y[j];
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) scanf("%d %d", &x[i], &y[i]), p[i] = i;
	sort(p, p + m, compare);
	int v1 = 1, v2 = 2, cnt = 0; bool f = true;
	for (int i = 0; i < m; i++) {
		if (y[p[i]] == 1) b[p[i]] = ++cnt;
		else {
			if (v2 > cnt) {
				f = false;
				break;
			}
			a[p[i]] = v1, b[p[i]] = v2;
			if (++v1 == v2) v1 = 1, v2++;
		}
	}
	if (!f) printf("-1\n");
	else for (int i = 0; i < m; i++) printf("%d %d\n", a[i] + 1, b[i] + 1);
	return 0;
}