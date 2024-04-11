#include <stdio.h>
#include <stdlib.h>
;
int a, b, n;
typedef long long LL;
int chk(LL l, LL r, LL t, LL m) {
	if (l >= r) return 1;
	LL lv = a+(l-1)*b, rv = a+(r-2) *b;
	LL len = (r - l);
	if (lv>t ||rv > t) return 0;
	if ((lv + rv) * len / 2 > t * m) return 0;
	return 1;
}

int main() {
	scanf("%d%d%d", &a, &b, &n);
	for (int ii=0; ii<n; ii++) {
		int l, m, t;
		scanf("%d%d%d", &l, &t, &m);
		int L = 0, R = 100000000, M;
		while (L+1 < R) {
			M = (L+R) / 2;
			if (chk(l, l+M, t, m)) L = M;
			else R = M;
		}
		printf("%d\n", L==0 ? -1 : l+L-1);
	}
	return 0;
}