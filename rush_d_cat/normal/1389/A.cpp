#include <bits/stdc++.h>
using namespace std;
int t, l, r;
int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%d%d", &l, &r);
		if (2 * l > r) {
			printf("-1 -1\n");
		} else {
			printf("%d %d\n", l, 2 * l);
		}
	}
}