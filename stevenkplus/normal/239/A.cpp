#include <cstdio>

using namespace std;

int y,k,n;
int main() {
	scanf("%d %d %d", &y, &k, &n);
	int x = 1;
	int md = (x + y) % k;
	if (md > 0) {
		x += (k - md);
	}
	if (x + y > n) {
		printf("-1\n");
		return 0;
	} else {
		bool first = true;
		while (x + y <= n) {
			if (!first)  {
				printf(" ");
			}
			first = false;
			printf("%d", x);
			x += k;
		}
		printf("\n");
	}
	return 0;
}