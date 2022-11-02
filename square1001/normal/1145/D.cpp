#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int ans = 2 + (a[2] ^ (*min_element(a.begin(), a.end())));
	cout << ans << endl;
	return 0;
}