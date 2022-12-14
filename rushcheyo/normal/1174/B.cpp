#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int n, a[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	int x = a[1] & 1;
	bool flag = true;
	for (int i = 2; i <= n; ++i)
		if ((a[i] & 1) != x) flag = false;
	if (!flag)
		sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; ++i)
		printf("%d ", a[i]);
	return 0;
}