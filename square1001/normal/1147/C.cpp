#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	int mn = *min_element(a.begin(), a.end());
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] == mn) ++cnt;
	}
	cout << (cnt <= n / 2 ? "Alice" : "Bob") << endl;
	return 0;
}