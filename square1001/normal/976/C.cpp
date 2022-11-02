#include <iostream>
#include <algorithm>
using namespace std;
int n, l[300009], r[300009], p[300009];
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> l[i] >> r[i], p[i] = i;
	sort(p, p + n, [&](int i, int j) {
		if (r[i] != r[j]) return r[i] < r[j];
		return l[i] > l[j];
	});
	int idx = -1, resa = -1, resb = -1;
	for (int i = 0; i < n; i++) {
		if (idx != -1 && l[p[i]] <= l[idx]) {
			resa = idx + 1;
			resb = p[i] + 1;
			break;
		}
		if (idx == -1 || l[idx] < l[p[i]]) {
			idx = p[i];
		}
	}
	cout << resa << ' ' << resb << "\n";
	return 0;
}