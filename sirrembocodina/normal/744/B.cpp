#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

int mn[30][2][1010];
vector<int> q;

int main() {
	ios_base::sync_with_stdio();
	int n;
	cin >> n;
	for (int j = 0, p = 1; p < n; p <<= 1, ++j) {
		forn (o, 2) {
			q.clear();
			forn (i, n) {
				if (bool(i & p) == bool(o)) {
					q.push_back(i);
				}
			}
			cout << q.size() << endl;
			cout.flush();
			forn (i, q.size()) {
				cout << q[i] + 1 << " ";
			}
			cout << endl;
			cout.flush();
			forn (i, n) {
				cin >> mn[j][o][i];
			}
		}
	}
	cout << "-1\n";
	cout.flush();
	forn (i, n) {
		int ans = 2000000000;
		for (int j = 0, p = 1; p < n; p <<= 1, ++j) {
			ans = min(ans, mn[j][1 - bool(i & p)][i]);
		}
		cout << ans << " ";
	}
	cout << endl;
	cout.flush();
	return 0;
}