#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int n, ro, re, oe;
	scanf("%d %d %d %d", &n, &ro, &re, &oe);
	int least = min(min(ro, re), oe);
	if (n == 1) {
		printf("0");
		return 0;
	}
	if (least == ro || least == re) {
		printf("%d", (n-1)*least);
	} else {
		printf("%d", min(ro, re) + (n-2)*oe);
	}
	return 0;
}