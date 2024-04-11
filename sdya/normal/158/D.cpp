#include <iostream>
#include <cstdio>

using namespace std;

const int maxN = 21000;

int n;
int a[maxN];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);

	int best = -1000000000;
	for (int i = 3; i <= n; ++i)
		if (n % i == 0) {
			int d = i;
			int step = n / d;
			for (int j = 0; j < step; ++j) {
				int s = 0;
				for (int k = j; k < j + n; k += step)
					s += a[k % n];
				best = max(best, s);
			}
		}

	printf("%d\n", best);

	return 0;
}