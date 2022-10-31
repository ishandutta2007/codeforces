#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<char> a(100000);
	vector<int> res(300000);
	int t;
	cin >> t;
	for (int c = 0; c < t; ++c) {
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		int k = 0;
		for (int i = 0; i < n; ++i) {
			char x = 0;
			cin >> x;
			if (x != a[i]) {
				res[k++] = i + 1;
				res[k++] = 1;
				res[k++] = i + 1;
			}
		}
		cout << k << " ";
		for (int i = 0; i < k; ++i) {
			cout << res[i] << " ";
		}
		cout << '\n';
	}
	return 0;
}