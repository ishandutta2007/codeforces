#include <cstdio>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;
const int inf = 1012345678;
int n, m, l, r;
int main() {
	scanf("%d", &n);
	int pl = inf, pr = -inf;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &l, &r);
		pl = min(pl, r);
		pr = max(pr, l);
	}
	scanf("%d", &m);
	int ql = inf, qr = -inf;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &l, &r);
		ql = min(ql, r);
		qr = max(qr, l);
	}
	printf("%d\n", max({ pr - ql, qr - pl, 0 }));
	return 0;
}