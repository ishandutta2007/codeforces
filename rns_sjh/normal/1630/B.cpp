#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define ll long long

using namespace std;

const int N = 200500;

int n, k, a[N], b[N];

vector<pii> vec;

bool cmp(pii A, pii B) {
	return abs(A.fi - A.se) < abs(B.fi - B.se);
}

int main() {
	int tcase;
	scanf("%d", &tcase);
	while (tcase--) {
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		for (int i = 0; i < n; i++) b[i] = a[i];
		sort(b, b + n);
		int cnt = k + (n - k + 1) / 2;
		vec.clear();
		for (int i = 0; i < n; i++) {
			int j = i + cnt - 1;
			if (j >= n) break;
			vec.push_back(pii(b[i], b[j]));
		}
		sort(vec.begin(), vec.end(), cmp);
		int x = vec[0].fi, y = vec[0].se;
		printf("%d %d\n", x, y);
		if (k == 1) {
			printf("%d %d\n", 1, n);
			continue;
		}
		for (int i = 0, j; i < n; i++) {
			int cnt = 0;
			for (j = i; j < n; j++) {
				if (x <= a[j] && a[j] <= y) {
					cnt++;
					if (j - i + 1 < 2 * cnt) {
						k--; break;
					}
				}
			}
			printf("%d %d\n", i + 1, j + 1);
			if (k == 1) {
				printf("%d %d\n", j + 2, n);
				break;
			}
			i = j;
		}
	}

	return 0;
}