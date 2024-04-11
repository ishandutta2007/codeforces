#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int oct(int i, int j) {
	return (i > 0 ? 1 : 0) + 2 * (j > 0 ? 1 : 0);
}



int main() {
	int n; scanf("%d", &n);
	int ax, ay; scanf("%d %d", &ax, &ay);
	int bx, by; scanf("%d %d", &bx, &by);
	int cx, cy; scanf("%d %d", &cx, &cy);
	bx -= ax, cx -= ax;
	by -= ay, cy -= ay;
	//  -3 -1
	// -1 -3
	if (oct(bx, by) == oct(cx, cy)) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	return 0;
}