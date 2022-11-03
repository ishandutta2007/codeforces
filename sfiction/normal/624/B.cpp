#include <cstdio>
#include <algorithm>

using namespace std;

int a[30];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	sort(a, a + n);
	long long ans = a[n - 1];
	int pre = a[n - 1];
	for (int i = n - 2; i >= 0; --i)
		if (pre > 0)
			ans += pre = min(pre - 1, a[i]);
	printf("%I64d\n", ans);
	return 0;
}