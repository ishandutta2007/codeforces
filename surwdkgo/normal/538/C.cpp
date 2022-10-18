#include <stdio.h>
#include <algorithm>
using namespace std;
int main() {
	int n, mx=0, nd;
	scanf("%d%d", &nd, &n);
	int ld, lh;
	for (int i=0; i<n; i++) {
		int d, h;
		scanf("%d%d", &d, &h);
		if (i==0) {
			mx = max(mx, h + d-1);
		} else {
			if (abs(h - lh) > d-ld) {mx = -1; break;}
			else {
				mx = max(mx, max(h, lh) + (d - ld - abs(h - lh)) / 2);
			}
		}
		ld = d;
		lh = h;
	}
	if (mx == -1) puts("IMPOSSIBLE");
	else printf("%d\n", max(mx, nd - ld + lh));
	return 0;
}