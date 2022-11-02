#include <iostream>
#include <algorithm>
using namespace std;
int n, a[1009], b[1009], p[1009]; bool used[1009];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	for (int i = 0; i < n; i++) {
		fill(used, used + n + 1, false);
		bool f = true;
		for (int j = 0; j < n; j++) {
			if (i != j) {
				if (used[a[j]]) f = false;
				used[a[j]] = true;
			}
		}
		if (f) {
			int rem = -1;
			for (int j = 1; j <= n; j++) {
				if (!used[j]) rem = j;
			}
			for (int j = 0; j < n; j++) {
				if (i == j) p[j] = rem;
				else p[j] = a[j];
			}
			int cnt = 0;
			for (int j = 0; j < n; j++) {
				if (p[j] != b[j]) cnt++;
			}
			if (cnt == 1) {
				for (int j = 0; j < n; j++) cout << p[j] << ' ';
				break;
			}
		}
	}
	return 0;
}