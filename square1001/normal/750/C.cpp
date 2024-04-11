#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n, c[200009], d[200009], sum[200009];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> c[i] >> d[i];
	for (int i = 0; i < n; i++) sum[i + 1] = sum[i] + c[i];
	int l = -1000000000, r = 1000000000;
	if (d[0] == 1) l = 1900;
	else r = 1900;
	for (int i = 0; i < n - 1; i++) {
		if (d[i + 1] == 1) l = max(l, 1900 - sum[i + 1]);
		else r = min(r, 1900 - sum[i + 1]);
	}
	if (r == 1000000000) cout << "Infinity" << endl;
	else if (l >= r) cout << "Impossible" << endl;
	else cout << r + sum[n] - 1 << endl;
	return 0;
}