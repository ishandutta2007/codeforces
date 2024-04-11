#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int n, p[N];

int main() {
	scanf("%d", &n);
	if (n % 4 <= 1) {
		for (int i = 1; i <= n / 4; ++i) {
			p[2 * i - 1] = 2 * i;
			p[2 * i] = n - (2 * i - 1) + 1;
			p[n - (2 * i - 1) + 1] = n - 2 * i + 1;
			p[n - 2 * i + 1] = 2 * i - 1;
		}
		if (n % 2)
			p[(n + 1) / 2] = (n + 1) / 2;
		for (int i = 1; i <= n; ++i)
			printf("%d ", p[i]);
	} else
		puts("-1");
	return 0;
}