#include <cstdio>
#include <cmath>

using namespace std;
int dist(int R1, int R2) {
	return 2 * sqrt(R1*R2) + 1;
}

int main() {
	int curx  = 0;
	printf("302\n");
	int preR = 1000000;
	printf("%d %d\n", curx, preR);
	for(int r = 300; r >= 1; --r) {
		int d =  dist(preR, r);
		preR = r;
		curx += d;
		printf("%d %d\n", curx, r);
	}
	int R = 1000000;
	curx = 1000000;
	printf("%d %d\n", curx, R);
	return 0;
}