#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int n, a[100009]; string s;
int main() {
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> s;
	int l = -1000000000, r = 1000000000;
	for (int i = 4; i < n; i++) {
		if (s[i] == '1' && s[i - 1] == '0') {
			l = max(l, *max_element(a + (i - 4), a + (i + 1)) + 1);
		}
		if (s[i] == '0' && s[i - 1] == '1') {
			r = min(r, *min_element(a + (i - 4), a + (i + 1)) - 1);
		}
	}
	cout << l << ' ' << r << endl;
	return 0;
}