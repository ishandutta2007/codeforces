#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	int ans = 0;
	int x[n];
	int y[m];
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> y[i];
	}

	int p1 = -1, p2 = -1;
	int s1 = 0;
	int s2 = 0;
	while (p1 < n) {
		if (s1 == s2) {
			ans++;
			p1++;
			if (p1 == n) break;
			s1 += x[p1];
		}
		while (s1 < s2) {
			p1++;
			s1 += x[p1];
		}
		while (s2 < s1) {
			p2++;
			s2 += y[p2];
		}
	}
	cout << ans-1 << endl;
	cin >> n;
}