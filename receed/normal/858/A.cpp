#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k, p2 = 0, p5 = 0;
	cin >> n >> k;
	int c = n;
	while (c % 2 == 0) {
		p2++;
		c /= 2;
	}
	while (c % 5 == 0) {
		p5++;
		c /= 5;
	}
	long long ans = n;
	for (int i = 0; i < k - p2; i++)
		ans *= 2;
	for (int i = 0; i < k - p5; i++)
		ans *= 5;
	cout << ans;
}