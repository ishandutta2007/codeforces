#include <cstdio>
#include <algorithm>

using namespace std;
int n;
int a[200005];

int absolute(int val)
{
	return val > 0 ? val : -val;
}

int half(int val)
{
	if (val >= 0) return val / 2 + (absolute(val) & 1);
	return -half(-val);
}

int interval(int minval, int maxval)
{
	if (minval > maxval) swap(minval, maxval);
	if (a[n] < minval || a[1] > maxval) return 0;
	int l = 1, r = n;
	while (l < r) {
		int mid = (l + r) / 2;
		if (a[mid] < minval)
			l = mid + 1;
		else
			r = mid;
	}
	int start_interval = l;
	l = 1, r = n;
	while (l < r) {
		int mid = (l + r) / 2 + 1;
		if (a[mid] > maxval)
			r = mid - 1;
		else
			l = mid;
	}
	int end_interval = l;
	if (start_interval <= end_interval) return end_interval - start_interval + 1;
	
	return 0;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	sort(a + 1, a + n + 1);
	long long total = 0;
	for (int xpos = 1; xpos <= n; xpos++) {
		if (a[xpos] == 0) continue;
		if (a[xpos] == 1) {
			total += interval(1, 2) + interval(-1, -2); continue;
		}
		total += interval(half(a[xpos]), 2 * a[xpos]) - 1;
		total += interval(-2 * a[xpos], -half(a[xpos]));
	}
	printf("%I64d", total / 2LL); return 0;
}