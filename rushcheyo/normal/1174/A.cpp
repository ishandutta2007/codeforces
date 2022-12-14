#include <bits/stdc++.h>
using namespace std;

int n, a[2005];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= 2 * n; ++i)
		scanf("%d", a + i);
	sort(a + 1, a + 1 + 2 * n);
	if (a[1] == a[2 * n]) puts("-1");
	else {
		for (int i = 1; i <= 2 * n; ++i)
			printf("%d ", a[i]);
	}
	return 0;
}