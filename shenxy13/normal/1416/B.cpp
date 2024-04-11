#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
int main() {
	int t;
	scanf("%d", &t);
	for (int h = 0; h < t; ++h) {
		int n;
		scanf("%d", &n);
		int a[n + 1];
		for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
		vector<iii> ops;
		for (int i = 2; i <= n; ++i) {
			if (a[i] % i) {
				ops.push_back(iii(ii(1, i), i - (a[i] % i)));
				a[1] -= i - (a[i] % i), a[i] += i - (a[i] % i);
			}
			ops.push_back(iii(ii(i, 1), a[i] / i));
			a[1] += a[i], a[i] = 0;
		}
		if (a[1] % n == 0) {
			for (int i = 2; i <= n; ++i) ops.push_back(iii(ii(1, i), a[1] / n));
			printf("%lu\n", ops.size());
			for (iii i: ops) printf("%d %d %d\n", i.first.first, i.first.second, i.second);
		} else printf("-1\n");
	}
	return 0;
}