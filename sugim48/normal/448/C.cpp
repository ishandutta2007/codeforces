#include <algorithm>
#include <cstdio>
using namespace std;

typedef long long ll;

int a[5000];

ll foo(int l, int r) {
	int mi = 1000000000;
	for (int i = l; i < r; i++)
		mi = min(mi, a[i]);
	for (int i = l; i < r; i++)
		a[i] -= mi;
	ll res = mi;
	int i = l;
	for (;;) {
		while (i < r && a[i] == 0)
			i++;
		if (i == r)
			break;
		int j = i;
		while (j < r && a[j] > 0)
			j++;
		res += foo(i, j);
		i = j;
	}
	return min((ll)(r - l), res);
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("%I64d\n", foo(0, n));
}