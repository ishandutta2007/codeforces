#include <vector>
#include <iostream>
using namespace std;
int n, m, a[2009], c[2009];
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i]; a[i]--;
		if (a[i] < m) c[a[i]]++;
	}
	int r = n / m, cnt = 0;
	for (int i = 0; i < m; i++) {
		int ptr = 0;
		while (c[i] < r && ptr < n) {
			if (a[ptr] >= m) {
				a[ptr] = i; c[i]++; cnt++;
			}
			ptr++;
		}
	}
	for (int i = 0; i < m; i++) {
		int ptr = 0;
		while(c[i] < r && ptr < n) {
			if (a[ptr] < m && c[a[ptr]] > r) {
				c[a[ptr]]--; c[i]++; a[ptr] = i;
				cnt++;
			}
			ptr++;
		}
	}
	cout << r << ' ' << cnt << endl;
	for (int i = 0; i < n; i++) {
		if (i) cout << ' ';
		cout << a[i] + 1;
	}
	cout << endl;
	return 0;
}