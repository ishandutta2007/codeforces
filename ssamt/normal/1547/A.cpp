#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <vector>

int main() {
	int h, i, j, k;
	int t, n;
	int ax, ay;
	int bx, by;
	int fx, fy;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		fgetc(stdin);
		scanf("%d %d", &ax, &ay);
		scanf("%d %d", &bx, &by);
		scanf("%d %d", &fx, &fy);
		if(ax == fx && bx == fx && ((ay < fy && fy < by) || (by < fy && fy < ay))) {
			printf("%d\n", abs(ay-by)+2);
		} else if(ay == fy && by == fy && ((ax < fx && fx < bx) || (bx < fx && fx < ax))) {
			printf("%d\n", abs(ax-bx)+2);
		} else {
			printf("%d\n", abs(ax-bx)+abs(ay-by));
		}
	}
}