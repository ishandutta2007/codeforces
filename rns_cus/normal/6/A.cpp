#include <stdio.h>
#include <algorithm>
using namespace std;

int a[11];

int main() {
	for (int i = 0; i < 4; i ++) scanf("%d", &a[i]);
	sort(a, a + 4);
	if (a[0] + a[1] > a[2] || a[1] + a[2] > a[3]) puts("TRIANGLE");
	else if (a[0] + a[1] == a[2] || a[1] + a[2] == a[3]) puts("SEGMENT");
	else puts("IMPOSSIBLE");
	return 0;
}