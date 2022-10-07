#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100;
int ar[maxn];
int n, m;

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", ar + i);
	}

	sort(ar, ar + n);
	int ind = n - m;
	if (ind >= 0) {
		int ans = ar[ind];
		printf("%d %d\n", ans, ans);
	} else
		printf("-1");
	return 0;
}