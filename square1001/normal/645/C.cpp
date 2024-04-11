#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, c, a[100009]; string s;
int main() {
	cin >> n >> m >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0') a[c++] = i;
	}
	int ret = 100009;
	for (int i = 0; i < c - m; i++) {
		int ptr = lower_bound(a + i, a + i + m + 1, (a[i] + a[i + m]) / 2) - a; ret = min(ret, max(a[ptr] - a[i], a[i + m] - a[ptr]));
		if (ptr != 0) ret = min(ret, max(a[ptr - 1] - a[i], a[i + m] - a[ptr - 1]));
	}
	cout << ret << endl;
	return 0;
}