#include <stdio.h>
#include <stdlib.h>
#include <vector>

#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

int main() {
	int i, j;
	int t;
	int w, h;
	int x1, y1, x2, y2;
	int w1, h1;
	int w2, h2;
	int dx, dy;
	scanf("%d", &t);
	for(i=0; i<t; i++) {
		scanf("%d %d", &w, &h);
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		w1 = x2-x1;
		h1 = y2-y1;
		scanf("%d %d", &w2, &h2);
		dx = max(x1, w-x2);
		dy = max(y1, h-y2);
		if(w1+w2 <= w) {
			if(h1+h2 <= h) {
				printf("%.10f\n", (double)min(max(w2-dx, 0), max(h2-dy, 0)));
			} else {
				printf("%.10f\n", (double)max(w2-dx, 0));
			}
		} else {
			if(h1+h2 <= h) {
				printf("%.10f\n", (double)max(h2-dy, 0));
			} else {
				printf("-1\n");
			}
		}
		
	}
}