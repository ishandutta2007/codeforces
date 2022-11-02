#include <cstdio>
#pragma warning(disable : 4996)
int n, a[200009], par[200009];
int root(int x) {
	if (par[x] == x) return x;
	return par[x] = root(par[x]);
}
bool same(int x, int y) {
	return root(x) == root(y);
}
void unite(int x, int y) {
	x = root(x), y = root(y);
	par[x] = y;
}
int main() {
	scanf("%d", &n);
	int cnt = 0, p = -1;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]), a[i]--, par[i] = i;
		if (a[i] == i) p = i;
	}
	for (int i = 0; i < n; i++) {
		if (same(i, a[i])) {
			if (p == -1 || p == i) {
				if (i != a[i]) a[i] = i, cnt++;
				p = i;
			}
			else a[i] = p, cnt++;
		}
		unite(i, a[i]);
	}
	printf("%d\n", cnt);
	for (int i = 0; i < n; i++) {
		if (i) printf(" ");
		printf("%d", a[i] + 1);
	}
	printf("\n");
	return 0;
}