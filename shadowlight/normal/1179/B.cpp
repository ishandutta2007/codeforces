#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(int n, int m) {
	int s = 0, t = n - 1;
	int a = 0, b = m - 1;
	while (s < t) {
		for (int i = 0; i < m; i++) {
			cout << s + 1 << " " << i + 1 << "\n";
			cout << t + 1 << " " << m - i << "\n";
		}
		s++, t--;
	}
	if (s == t) {
		int a = 0, b = m - 1;
		while (a < b) {
			cout << s + 1 << " " << a + 1 << "\n";
			cout << s + 1 << " " << b + 1 << "\n";
			a++, b--;
		}
		if (a == b) {
			cout << s + 1 << " " << a + 1 << "\n";
		}
	}
}

int main() {
	//freopen("B.in", "r", stdin);
	//freopen("B.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	solve(n, m);
}