#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n, q, x, a[1048588], b[1048588]; long long s[22], st[22];
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < 1 << n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 1 << n; j += 2 << i) {
			int p1 = j, p2 = j + (1 << i), p3 = j + (2 << i), ptr = p2;
			for (int k = p1; k < p2; k++) {
				while (ptr != p3 && a[k] > a[ptr]) ptr++;
				s[i] += ptr - p2;
			}
			int ptr2 = p1;
			for (int k = p2; k < p3; k++) {
				while (ptr2 != p2 && a[k] > a[ptr2]) ptr2++;
				st[i] += ptr2 - p1;
			}
			int ptr3 = p2, cur = 0;
			for (int k = p1; k < p2; k++) {
				while (ptr3 != p3 && a[k] > a[ptr3]) b[cur++] = a[ptr3++];
				b[cur++] = a[k];
			}
			for (int k = ptr3; k < p3; k++) b[cur++] = a[k];
			for (int k = 0; k < 2 << i; k++) a[k + j] = b[k];
		}
	}
	cin >> q;
	int bit = 0;
	for (int i = 0; i < q; i++) {
		cin >> x;
		bit ^= (1 << x) - 1;
		long long ret = 0;
		for (int j = 0; j < n; j++) {
			if (bit & (1 << j)) ret += st[j];
			else ret += s[j];
		}
		cout << ret << endl;
	}
	return 0;
}