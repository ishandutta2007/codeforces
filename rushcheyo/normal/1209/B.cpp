#include <bits/stdc++.h>

using namespace std;

int n;
string col[1000];

int main() {
	cin >> n >> col[0];
	for (int i = 1; i < 1000; ++i)
		col[i] = col[0];
	for (int i = 0, a, b; i < n; ++i) {
		scanf("%d%d", &a, &b);
		char now = col[0][i];
		for (int j = b; j < 1000; j += a) {
			now = '0' + '1' - now;
			for (int t = j; t < min(1000, j + a); ++t)
				col[t][i] = now;
		}
	}
	int ans = 0;
	for (int i = 0; i < 1000; ++i)
		ans = max(ans, (int)count(col[i].begin(), col[i].end(), '1'));
	printf("%d\n", ans);
}