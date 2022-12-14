#include <cstdio>
#include <algorithm>

using namespace std;

int rd() {
	int x = 0; char c = getchar();
	while (c > '9' || c < '0') c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x;	
}

const int N = 2e6 + 10;
int p[N], a[N], id, pl, pr, n;
long long ans, sum;

int main() {
	n = rd();
	for (int i = 1; i <= n; i ++) p[i] = rd();
	for (int i = 1; i <= n; i ++) {
		sum += abs(p[i] - i);
		if (p[i] >= i) a[p[i] - i] ++, pl ++; else pr ++;
	}
	ans = sum;
//	for (int j = 0; j < n; j ++) printf("%d ", a[j]); puts("");
	for (int i = 1; i < n; i ++) {
		pl -= a[i - 1], pr += a[i - 1];
//		a[i - 1] = 0;
		sum = sum - pl + pr - abs(p[n - i + 1] - n - 1) + p[n - i + 1] - 1;
//		sum = sum + (p[n - i + 1] == n) ? 1 : -1;
	//	printf("%d %d %lld %d %d\n", pl, pr, sum, abs(p[n - i + 1] - n), p[n - i + 1] - 1);
		pl ++, pr --; 
		a[p[n - i + 1] + i - 1] ++;
//		for (int j = 0; j < n; j ++) printf("%d ", a[j]); puts("");
		if (ans > sum) ans = sum, id = i;
		
	}
	printf("%I64d %d\n", ans, id);
	return 0;
}