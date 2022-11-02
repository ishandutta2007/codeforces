#include <bits/stdc++.h>
using namespace std;

int x, y, xx, yy;

int main() {
	scanf("%d %d %d %d", &x, &y, &xx, &yy);
	printf("%d\n", max(abs(x - xx), abs(y - yy)));

	return 0;
}