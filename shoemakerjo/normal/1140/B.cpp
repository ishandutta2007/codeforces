#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n;

	cin >> t;
	string line;
	while (t--) {
		cin >> n;
		cin >> line;

		int res = n-1;

		for (int i = 0; i < n; i++) {
			if (line[i] == '>') {
				res = min(res, i);
				break;
			}
		}

		for (int i = n-1; i >= 0; i--) {
			if (line[i] == '<') {
				res = min(res,  n - i - 1);
			}
		}
		cout << res << endl;
	}
	//pick > or <, get down to one
	// if we start with <, end with > what happens?
	//   --> then this must always be true and we die


}