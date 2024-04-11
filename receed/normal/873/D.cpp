#include <bits/stdc++.h>

using namespace std;

int a[100000];

bool ms(int l, int r, int d, int k) {
	if (k % 2 == 0 || r - l == 1 && k > 1)
		return 1;
	if (k == 1) {
		for (int i = l; i < r; i++)
			a[i] = i + d;
		return 0;  
	}
	int m = (l + r) / 2;
	if (k % 4 == 3) {
		if (ms(l, m, d + (r - l + 1) / 2, k / 2) || ms(m, r, d - (r - l) / 2, k / 2))
			return 1;
	}
	else {
		if (ms(l, m, d + (r - l + 1) / 2, k / 2 - 1) || ms(m, r, d - (r -l) / 2, k / 2 + 1))
			return 1;
	}
	return 0;
}

int main() {
#ifdef FLOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, k;
	cin >> n >> k;
	if (k % 2 == 0 || ms(0, n, 1, k))
		cout << -1;
	else
		for (int i = 0; i < n; i++)
			cout << a[i] << ' ';	
}