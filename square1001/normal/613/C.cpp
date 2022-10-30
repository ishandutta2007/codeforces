#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	int sum = 0;
	for (int i = 0; i < n; ++i) cin >> a[i], sum += a[i];
	int lim = *max_element(a.begin(), a.end());
	int ret = 0;
	for (int i = 1; i <= lim; ++i) {
		bool ok = true;
		int odds = 0;
		for (int j = 0; j < n; ++j) {
			if (a[j] % i != 0) ok = false;
			if ((a[j] / i) % 2 == 1) ++odds;
		}
		if (ok && odds <= 1) ret = max(ret, i);
	}
	cout << ret * (ret != 0 && (sum / ret) % 2 == 0 ? 2 : 1) << endl;
	if (ret != 0) {
		string s;
		for (int i = 0; i < n; ++i) {
			s += string((a[i] / ret) / 2, i + 97);
		}
		for (int i = 0; i < n; ++i) {
			if ((a[i] / ret) % 2 == 1) s += (char)(i + 97);
		}
		for (int i = n - 1; i >= 0; --i) {
			s += string((a[i] / ret) / 2, i + 97);
		}
		for (int i = 0; i < ret; ++i) cout << s;
		cout << '\n';
	}
	else {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < a[i]; ++j) {
				cout << (char)(i + 97);
			}
		}
		cout << '\n';
	}
	return 0;
}