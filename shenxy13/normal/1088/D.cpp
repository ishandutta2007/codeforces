#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int a = 0, b = 0;
	bool agreat = false;
	printf("? 0 0\n");
	fflush(stdout);
	int x, y;
	scanf("%d", &x);
	if (x > 0) agreat = true;
	for (int i = 29; i >= 0; --i) {
		printf("? %d %d\n", a + (1 << i), b);
		fflush(stdout);
		scanf("%d", &x);
		printf("? %d %d\n", a, b + (1 << i));
		fflush(stdout);
		scanf("%d", &y);
		if (x == y) {
			if (agreat) a += 1 << i;
			else b += 1 << i;
			if (x > 0) agreat = true;
			else agreat = false;
		} else if (y == 1) a += 1 << i, b += 1 << i;
	}
	printf("! %d %d", a, b);
	return 0;
}