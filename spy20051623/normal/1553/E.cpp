#include <bits/stdc++.h>

using namespace std;

int a[300005];
int b[300005];
int c[300005];

void solve() {
	int n, m;
	scanf("%d%d", &n, &m);
	memset(c, 0, sizeof(int) * (n + 5));
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		++c[(i + n - a[i]) % n];
	}
	vector<int> ans;
	for (int i = 0; i < n; ++i) {
		if (c[i] >= n / 3) {
			memcpy(b, a, sizeof(int) * (n + 5));
			int cnt = 0;
			for (int j = 1; j <= n; ++j) {
				while (b[j] != (j + n - i - 1) % n + 1) {
					++cnt;
					swap(b[j], b[(b[j] + i - 1) % n + 1]);
				}
			}
			if (cnt <= m)ans.push_back(i);
		}
	}
	printf("%d", ans.size());
	for (auto i:ans)printf(" %d", i);
	printf("\n");
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}