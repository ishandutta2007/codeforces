#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) cin >> b[i];
	if (a[0] != b[0] || a[n - 1] != b[n - 1]) {
		cout << "No" << endl;
	}
	else {
		vector<int> da(n - 1), db(n - 1);
		for (int i = 0; i < n - 1; ++i) {
			da[i] = a[i + 1] - a[i];
			db[i] = b[i + 1] - b[i];
		}
		sort(da.begin(), da.end());
		sort(db.begin(), db.end());
		cout << (da == db ? "Yes" : "No") << endl;
	}
	return 0;
}