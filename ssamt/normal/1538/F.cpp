#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <math.h>
#include <vector>

int main() {
	int h, i, j;
	int t, l, r;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d %d", &l, &r);
		int answer = r-l;
		while(l > 0 || r > 0) {
			answer += (r/10)-(l/10);
			l /= 10;
			r /= 10;
		}
		printf("%d\n", answer);
	}
}