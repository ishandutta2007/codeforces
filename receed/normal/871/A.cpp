#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef FLOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int q, n;
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> n;
		if (n <= 3 || n == 5 || n == 7 || n == 11)
			cout << -1 << '\n';
		else if (n % 2 == 0)
			cout << n / 4 << '\n';
		else
			cout << (n - 9) / 4 + 1 << '\n';
	}
}