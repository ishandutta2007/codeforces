#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n, m; cin >> n >> m;
	vector<bool> reachable(101, false);
	reachable[0] = true;
	for (int i = 0; i < n; ++i) {
		int ai, bi; cin >> ai >> bi;
		if (reachable[ai]) {
			for (int p = ai; p <= bi; ++p) {
				reachable[p] = true;
			}
		}
	}
	cout << (reachable[m] ? "YES" : "NO") << endl;
	return 0;
}