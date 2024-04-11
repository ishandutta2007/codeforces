#include <cstdio>
#include <algorithm>
#define lol long long
#define Maxn 400001
#define Abs(x) ((x) < 0 ? -(x) : (x))

using namespace std;

bool Cmp(lol x, lol y) {
	return Abs(x) < Abs(y);
}

int n, cnt;
long long ans[Maxn];
lol a[Maxn];

inline void Insert(lol d) {
	if (d < 0) {
		cnt--;
	} else {
		cnt++;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%I64d%I64d", &a[i * 2 - 1], &a[i * 2]);
		a[i * 2] = - a[i * 2] - 1;
	}
	sort(a + 1, a + n * 2 + 1, Cmp);
	for (int i = 1; i <= n * 2; i++) {
		ans[cnt] += Abs(a[i]) - Abs(a[i - 1]);
		while (i <= n * 2 && Abs(a[i]) == Abs(a[i + 1])) {
			Insert(a[i]);
			i++;
		}
		Insert(a[i]);
	}
	for (int i = 1; i <= n; i++) {
		printf("%I64d", ans[i]);
		if (i == n) {
			printf("\n");
		} else {
			printf(" ");
		}
	}
	return 0;
}

// By Sooke.
// CF1000C Covered Points Count.