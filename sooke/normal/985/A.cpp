#include <cstdio>
#include <algorithm>

using namespace std;

#define Maxn 101

#define Abs(x) ((x) < 0 ? -(x) : (x))
#define Min(x, y) ((x) < (y) ? (x) : (y))

int n, ansa, ansb, a[Maxn];

int main() {
	scanf("%d", &n);
	n /= 2;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		ansa += Abs(i * 2 - 1 - a[i]);
		ansb += Abs(i * 2 - a[i]);
	}
	printf("%d\n", Min(ansa, ansb));
	return 0;
}

// By Sooke.
// CF985A Chess Placing.