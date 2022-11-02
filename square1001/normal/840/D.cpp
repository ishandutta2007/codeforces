#include <cstdio>
#include <random>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;
const int inf = 1012345678;
mt19937 mt(1145141919);
int rand_rng(int l, int r) {
	uniform_int_distribution<int> p(l, r - 1);
	return p(mt);
}
int N, Q, a[300009], c[300009], cc[300009], l[300009], r[300009], t[300009], p[300009], ans[300009];
int main() {
	scanf("%d %d", &N, &Q);
	for (int i = 0; i < N; i++) scanf("%d", &a[i]);
	for (int i = 0; i < Q; i++) scanf("%d %d %d", &l[i], &r[i], &t[i]), l[i]--, p[i] = i, ans[i] = inf;
	int B = sqrt(N);
	sort(p, p + Q, [&](int i, int j) { return l[i] / B != l[j] / B ? l[i] < l[j] : ((l[i] / B) & 1 ? r[i] > r[j] : r[i] < r[j]); });
	int cl = 0, cr = 0; cc[0] = 300009;
	for (int i = 0; i < Q; i++) {
		while (cr < r[p[i]]) c[a[cr++]]++;
		while (cl > l[p[i]]) c[a[--cl]]++;
		while (cr > r[p[i]]) c[a[--cr]]--;
		while (cl < l[p[i]]) c[a[cl++]]--;
		for(int j = 0; j < 84; j++) {
			int x = rand_rng(l[p[i]], r[p[i]]);
			if (t[p[i]] * c[a[x]] > r[p[i]] - l[p[i]]) {
				ans[p[i]] = min(ans[p[i]], a[x]);
			}
		}
	}
	for (int i = 0; i < Q; i++) printf("%d\n", ans[i] != inf ? ans[i] : -1);
	return 0;
}