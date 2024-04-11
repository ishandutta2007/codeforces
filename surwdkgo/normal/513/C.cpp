#include <stdio.h>
int n, inp[10][2];
int clip(int i, int l, int r) {
	if (i < l) return l;
	if (i > r) return r;
	return i;
}
int isin(int i, int l, int r) {
	return i>= l && i<r ? 1 : 0;
}
int main() {
	scanf("%d", &n);
	double ans = 0, sp=0;
	for (int i=0; i<n; i++) {
		scanf("%d%d", &inp[i][0], &inp[i][1]);
	}
	for (int j=1; j<=10000; j++) {
		for (int k = 0; k<n; k++) {
			for (int l = 0; l<(1<<n); l++) {
				if ((l&(1<<k)) && (1<<k) != (l&-l)) continue;
				if (!l || l == (1<<k)) continue;
				double p = 1.0;
				for (int i=0; i<n; i++) {
					int L = inp[i][0], r = inp[i][1]+1;
					if ((i == k) && (l&(1<<i))) {
						p = p * isin(j, L, r) / (r-L);
					} else if (i==k) {
						p = p * (r-clip(j+1, L, r)) / (r-L);
					} else if (l & (1<<i)) {
						p = p * isin(j, L, r) / (r-L);
					} else {
						p = p * (clip(j, L, r) - L) / (r-L);
					}
				}
				ans += p * j;
				sp+=p;
				//if (j == 5) printf("%d %d %f\n", k, l, p);
			}
		}
	}
	//printf("%lf\n", sp);
	printf("%.12f\n", ans);
	return 0;
}