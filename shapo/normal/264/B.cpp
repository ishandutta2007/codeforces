#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int n;
int a[111111];
int ans[111111];

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf ("%d", a + i);
	memset (ans, 0, sizeof (ans));
	for (int i = n - 1; i >= 0; --i) {
		if (a[i] == 1)
			continue;
		int cur = ans[a[i]] + 1;
		for (int j = 2; j * j <= a[i]; ++j)
			if (a[i] % j == 0)
				cur = max (cur, max (ans[j], ans[a[i] / j]) + 1);
		ans[a[i]] = max (ans[a[i]], cur);
		for (int j = 2; j * j <= a[i]; ++j) 
			if (a[i] % j == 0) {
				ans[j] = max (ans[j], cur);
				ans[a[i] / j] = max (ans[a[i] / j], cur);
			}
	}
	int res = 1;
	for (int i = 2; i <= a[n - 1]; ++i)
		res = max (res, ans[i]);
	printf ("%d\n", res);
	return 0;
}