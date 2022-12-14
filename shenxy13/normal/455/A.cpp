#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
int val[500000], counts[500000], x = -1;
long long dptable[500000];
long long dp(int n) {
	if (n >= x) return 0;
	if (dptable[n] != -1) return dptable[n];
	long long ans = (long long) counts[n] * (long long) val[n];
	ans = max(ans + dp(n + ((val[n + 1] == val[n] + 1) ? 2 : 1)), dp(n + 1));
	return dptable[n] = ans;
}
int main() {
	fill_n(dptable, 500000, -1);
	int n, nextint;
	scanf("%d", &n);
	map<int, int> ma;
	for (int i = 0; i < n; i++) {
		scanf("%d", &nextint);
		ma[nextint] += 1;
	}
	x = ma.size();
	int i = 0;
	for (map<int, int>::iterator it = ma.begin(); it != ma.end(); it++, i++) {
		val[i] = it -> first, counts[i] = it -> second;
	}
	printf("%lld", dp(0));
	return 0;
}