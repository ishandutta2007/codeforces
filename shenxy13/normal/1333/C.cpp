#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
int main() {
	int n, fptr = 0;
	scanf("%d", &n);
	long long a[n + 1], ans = 0;
	a[0] = 0;
	for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
	for (int i = 1; i <= n; ++i) a[i] += a[i - 1];
	map<long long, int> psum;
	psum[0] = 1;
	for (int i = 1; i <= n; ++i) {
		while (psum[a[i]] != 0) --psum[a[fptr++]];
		ans += i - fptr;
		++psum[a[i]];
	}
	printf("%lld", ans);
	return 0;
}