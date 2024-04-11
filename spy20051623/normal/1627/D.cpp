#include <bits/stdc++.h>

using namespace std;
int v[1000005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	map<int, map<int, int>> m;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		v[x] = 1;
	}
	for (int i = 1000000; i > 0; --i) {
		int g = 0;
		for (int j = 2; i * j <= 1000000; ++j) {
			if (v[i * j]) g = __gcd(g, j);
			if (g == 1) break;
		}
		if (g == 1) v[i] = 1;
	}
	int cnt = 0;
	for (int i = 1; i <= 1000000; ++i) {
		if (v[i]) ++cnt;
	}
	cout << cnt - n << '\n';
	return 0;
}