#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int q;
	cin >> q;
	while(q--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for(int i = 0; i < n; ++i) cin >> a[i];
		sort(a.begin(), a.end(), [](int i, int j) { return i > j; });
		int ans = min(a[1] - 1, n - 2);
		cout << ans << endl;
	}
	return 0;
}