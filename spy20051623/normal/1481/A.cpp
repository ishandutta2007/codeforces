#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("in.txt", "r", stdin);
	int t, c[4], x, y;
	string s;
	cin >> t;
	while (t--) {
		cin >> x >> y;
		memset(c, 0, sizeof(c));
		cin >> s;
		for (auto ch : s) {
			if (ch == 'U')
				++c[0];
			if (ch == 'R')
				++c[1];
			if (ch == 'D')
				++c[2];
			if (ch == 'L')
				++c[3];
		}
		if (-c[3] <= x && x <= c[1] && -c[2] <= y && y <= c[0])
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}