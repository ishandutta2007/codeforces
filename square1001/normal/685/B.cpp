#include <cstdio>
#pragma warning(disable : 4996)
int n, q, x, l, r, p[22][300009], c[300009], d[300009], e[300009], z[300009], a[300009]; bool f[300009];
int main() {
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n; ++i) {
		if (i != 0) {
			scanf("%d", &p[0][i]);
			--p[0][i];
			++e[p[0][i]];
		}
		c[i] = 1;
		f[i] = true;
	}
	for (int i = 0; i < n; ++i) {
		if (e[i] == 0) {
			z[r++] = i;
		}
	}
	while (l != r) {
		if (z[l] == 0) {
			++l;
			continue;
		}
		if (--e[p[0][z[l]]] == 0) {
			z[r++] = p[0][z[l]];
		}
		c[p[0][z[l]]] += c[z[l]];
		++l;
	}
	for (int i = 1; i < n; ++i) {
		d[p[0][i]] = (d[p[0][i]] > c[i] ? d[p[0][i]] : c[i]);
	}
	for (int i = 0; i < 18; ++i) {
		for (int j = 0; j < n; ++j) {
			p[i + 1][j] = p[i][p[i][j]];
		}
	}
	for (int i = 0; i < n; ++i) {
		int pos = i;
		for (int j = 18; j >= 0; --j) {
			if (c[p[j][pos]] < d[i] * 2) {
				pos = p[j][pos];
			}
		}
		if (c[pos] < d[i] * 2) {
			pos = (pos != 0 ? p[0][pos] : -1);
		}
		if (pos != -1) {
			while (c[pos] <= c[i] * 2) {
				a[pos] = i;
				if (pos == 0) {
					break;
				}
				pos = p[0][pos];
			}
		}
	}
	for (int i = 0; i < q; ++i) {
		scanf("%d", &x);
		printf("%d\n", a[--x] + 1);
	}
	return 0;
}