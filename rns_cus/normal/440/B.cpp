#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 500500

long long a[N], sum;
int n;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i ++) scanf("%I64d", &a[i]), sum += a[i];
	long long mid = sum / n;
	long long ans = 0;
	for (int i = 0; i < n; i ++) {
		ans += abs(mid - a[i]);
		a[i+1] -= (mid - a[i]);
	}
	printf("%I64d\n", ans);
}