#include <cstdio>
int n, a[100009], b[100009], p[200009], x[200009];
void solve(int pos) {
	if (x[p[pos]] == 0) {
		x[p[pos]] = 3 - x[pos];
		solve(p[pos]);
	}
	if (x[pos ^ 1] == 0) {
		x[pos ^ 1] = 3 - x[pos];
		solve(pos ^ 1);
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i], &b[i]); a[i]--, b[i]--;
		p[a[i]] = b[i]; p[b[i]] = a[i];
	}
	for (int i = 0; i < 2 * n; i++) {
		if (x[i] == 0) {
			x[i] = 1;
			solve(i);
		}
	}
	for (int i = 0; i < n; i++) printf("%d %d\n", x[a[i]], x[b[i]]);
	return 0;
}