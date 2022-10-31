#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		vector<int> used(2 * n + 1, false);
		int res = 0;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			--a[i];
		}
		sort(a.begin(), a.end());
		for (int i = 0; i < n; ++i) {
			if (!used[a[i]]) {
				res += 1;
				used[a[i]] = true;
			}
			else if (!used[a[i] + 1]) {
				res += 1;
				used[a[i] + 1] = true;
			}
		}
		cout << res << "\n";
	}
	return 0;
}