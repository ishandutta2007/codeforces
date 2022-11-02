#include <iostream>
using namespace std;
int n, m, a[100009], s, b;
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> s;
			a[i] |= s << j;
		}
		b |= 1 << a[i];
	}
	bool f = false;
	for (int i = 0; i < 1 << m; i++) {
		for (int j = i + 1; j < 1 << m; j++) {
			if ((i & j) == 0 && (b & (1 << i)) && (b & (1 << j))) {
				f = true;
			}
		}
	}
	if (b & 1) f = true;
	cout << (f ? "YES" : "NO") << endl;
	return 0;
}