#include <bits/stdc++.h>
using namespace std;
bool d[100005];

int main() {
//	freopen("in.txt", "r", stdin);
	int n, a = 0, b = 0, in, last = 0, i, j, cnt = 0;
	memset(d, 0, sizeof(d));
	cin >> n;
	cnt = n;
	while (n--) {
		cin >> in;
		if (in == last) {
			--cnt;
		} else if (in == a) {
			if (last)
				b = last;
			memset(d, 0, sizeof(d));
			--cnt;
		} else if (in == b) {
			if (last)
				a = last;
			memset(d, 0, sizeof(d));
			--cnt;
		} else if (d[in]) {
			a = last;
			b = in;
			--cnt;
			memset(d, 0, sizeof(d));
			last = 0;
		} else {
			last = in;
			d[in] = 1;
		}
	}
	cout << cnt;
	return 0;
}