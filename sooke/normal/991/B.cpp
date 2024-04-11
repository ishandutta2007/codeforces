#include <cstdio>
#include <cmath>
#include <algorithm>
#define Maxn 101
#define Eps 0.000001

using namespace std;

int n, a[Maxn];
double dv;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		dv += a[i];
	}
	dv /= n;
	sort(a + 1, a + n + 1);
	int i;
	for (i = 1; i <= n && dv <= 4.5 - Eps; i++) {
		dv += (5.0 - a[i]) / n;
	}
	printf("%d\n", i - 1);
	return 0;
}

// By Sooke.
// CF991B Getting an A.