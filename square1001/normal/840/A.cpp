#include <iostream>
#include <algorithm>
using namespace std;
int n, a[200009], b[200009], p[200009], inv[200009];
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i], p[i] = i;
	sort(p, p + n, [](int i, int j) { return b[i] < b[j]; });
	for (int i = 0; i < n; i++) inv[p[i]] = i;
	sort(a, a + n);
	reverse(a, a + n);
	for (int i = 0; i < n; i++) cout << a[inv[i]] << ' ';
	return 0;
}