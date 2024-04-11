#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("a.in", "r", stdin);
	long long n;
	cin >> n;
	int k = sqrt(2.0 * n) - 1;
	while (1ll * (k + 1) * (k + 2) / 2 < n) k ++;
	cout << n - 1ll * k * (k + 1) / 2 << endl;
	return 0;
}