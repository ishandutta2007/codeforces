#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <math.h>
#include <vector>

int main() {
	int h, i, j;
	int t, n, m;
	int u, v;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d", &n);
		if(n == 1) {
			printf("1\n");
		} else {
			int a[n];
			for(i=0; i<n; i++) {
				scanf("%d", &a[i]);
			}
			int minval=a[0], maxval=a[0];
			int minidx=0, maxidx=0;
			for(i=1; i<n; i++) {
				if(a[i] < minval) {
					minval = a[i];
					minidx = i;
				}
				if(a[i] > maxval) {
					maxval = a[i];
					maxidx = i;
				}
			}
			int pos1 = n-std::min(minidx, maxidx);
			int pos2 = std::max(minidx, maxidx)+1;
			int pos3 = (std::min(minidx, maxidx)+1)+(n-std::max(minidx, maxidx));
			printf("%d\n", std::min(std::min(pos1, pos2), pos3));
		}
	}
}