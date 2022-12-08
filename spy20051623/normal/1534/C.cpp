#include <bits/stdc++.h>

using namespace std;

typedef struct n {
	int x;
	int flag;
} N;

void solve() {
	int i, n, flag, x, z, r;
	long long re = 1;
	cin >> n;
	vector<int> d(n + 5);
	vector<N> s(n + 5);
	for (i = 1; i <= n; i++) {
		cin >> d[i];
	}
	for (i = 1; i <= n; i++) {
		cin >> x;
		s[i].flag = 0;
		s[d[i]].x = x;
	}

	for (i = 1; i <= n; i++) {
		z = s[i].x;
		flag = 1;
		while (!s[i].flag && flag) {
			s[z].flag = 1;
			z = s[z].x;
			if (z == i) {
				flag = 0;
				re *= 2;
				re %= (int) 1e9 + 7;
			}
		}
	}

	cout << re << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}