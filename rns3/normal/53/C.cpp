#include <bits/stdc++.h>
using namespace std;

int n, m;

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i ++) {
		m = (i + 1) / 2;
		if (!(i % 2)) m = n + 1 - m;
		printf("%d ", m);
	}
	m = (n + 1) / 2;
	if (!(n % 2)) m = n + 1 - m;
	printf("%d\n", m);
	return 0;
}