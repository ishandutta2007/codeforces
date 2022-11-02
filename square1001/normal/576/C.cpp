#include <iostream>
#include <algorithm>
using namespace std;
int n, x[1000009], y[1000009], p[1000009];
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
		p[i] = i;
	}
	sort(p, p + n, [](int i, int j) {
		if (x[i] / 1000 != x[j] / 1000) return x[i] < x[j];
		else if (x[i] / 1000 % 2 == 0) return y[i] < y[j];
		return y[i] > y[j];
	});
	for (int i = 0; i < n; ++i) {
		cout << p[i] + 1 << ' ';
	}
	return 0;
}