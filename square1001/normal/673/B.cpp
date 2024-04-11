#include <iostream>
#include <algorithm>
using namespace std;
int n, m, a, b;
int main() {
	cin >> n >> m;
	int l = 1, r = n;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		if (a > b) swap(a, b);
		l = max(l, a);
		r = min(r, b);
	}
	cout << max(r - l, 0) << endl;
	return 0;
}