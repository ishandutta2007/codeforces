#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	long long n, m, a, b;
	cin >> n >> m >> a >> b;
	if (n % m == 0)
		return cout << 0, 0;

	cout << min(b*(n%m), a*(m-n%m));
}