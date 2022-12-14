#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int h = 0; h < t; ++h) {
		int n;
		scanf("%d", &n);
		int freq[n], a[n], sum = 1, mx, ans = 0;
		fill_n(freq, n, 0);
		for (int i = 0; i < n; ++i) scanf("%d", &a[i]), --a[i];
		for (int i = 0; i < n; ++i) ++freq[a[i]];
		if (*max_element(freq, freq + n) > (n + 1) / 2) {
			printf("-1\n");
			continue;
		}
		fill_n(freq, n, 0);
		++freq[a[0]];
		for (int i = 1; i < n; ++i) {
			if (a[i] == a[i - 1]) freq[a[i]] += 2, sum += 2;
		}
		++freq[a[n - 1]];
		++sum;
		mx = *max_element(freq, freq + n);
		while (mx - 2 > (sum - 2) / 2) {
			mx -= 2;
			sum -= 2;
			ans += 2;
		}
		printf("%d\n", (sum - 2) / 2 + ans);
	}
	return 0;
}