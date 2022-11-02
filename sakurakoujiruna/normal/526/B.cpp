#include <bits/stdc++.h>
using namespace std;

int a[2 << 20];

int main() {
	ios :: sync_with_stdio(false);
	int n; cin >> n;
	int m = (1 << (n + 1)) - 2;
	for(int i = 1; i <= m; i ++)
		cin >> a[i];

	int ans = 0;
	for(int i = m; i >= 2; i -= 2) {
		if(a[i] < a[i - 1])
			swap(a[i], a[i - 1]);
		ans += a[i] - a[i - 1];
		a[i / 2 - 1] += a[i];
	}
	cout << ans << '\n';
	return 0;
}