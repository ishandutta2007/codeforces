#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; ++i)
#define fs first
#define sc second

int main() {
	int n;
	scanf("%d", &n);
	printf("YES\n");
	forn (i, n) {
		int x1, x2, y1, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		x1 = min(x1, x2);
		y1 = min(y1, y2);
		printf("%d\n", 1 + (abs(x1) % 2) * 2 + (abs(y1) % 2));
	}
	return 0;
}