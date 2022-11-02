#include <cstdio>
int n, m, q, a, b, l[200009], r[200009], s[200009], ss[200009];
int main() {
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 0; i < n; i++) scanf("%d %d", &l[i], &r[i]), s[l[i]]++, s[++r[i]]--;
	for (int i = 1; i <= 200000; i++) s[i] += s[i - 1];
	for (int i = 1; i <= 200000; i++) ss[i] = ss[i - 1] + (s[i] >= m ? 1 : 0);
	for (int i = 0; i < q; i++) scanf("%d %d", &a, &b), printf("%d\n", ss[b] - ss[--a]);
	return 0;
}