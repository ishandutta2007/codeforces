#include <bits/stdc++.h>
using namespace std;
int t;
int main() {
	scanf("%d", &t);
	while (t--) {
		int a, b; scanf("%d%d", &a, &b);
		if (a > b) swap(a, b);
		int len = max(b, 2 * a);
		printf("%d\n", len * len);
	}
}