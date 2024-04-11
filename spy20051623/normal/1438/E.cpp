#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;
int a[N];

int find_high_digit(int x) {
	int cnt = 0;
	while (x) {
		++cnt;
		x >>= 1;
	}
	return cnt;
}

set<pair<int, int>> s;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++i) {
		int sum = 0;
		for (int j = i + 1; j <= n - 1; ++j) {
			sum += a[j];
			if (sum == (a[i] ^ a[j + 1])) s.emplace(i, j + 1);
			if (find_high_digit(sum) > find_high_digit(a[i])) break;
		}
	}
	for (int i = n; i >= 1; --i) {
		int sum = 0;
		for (int j = i - 1; j >= 2; --j) {
			sum += a[j];
			if (sum == (a[i] ^ a[j - 1])) s.emplace(j - 1, i);
			if (find_high_digit(sum) > find_high_digit(a[i])) break;
		}
	}
	printf("%d\n", s.size());
	return 0;
}