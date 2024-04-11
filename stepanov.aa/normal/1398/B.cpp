#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		string s;
		cin >> s;
		vector<int> a(1, 0);
		int j = 0;
		for (char x : s) {
			if (x == '1') {
				a[j] += 1;
			}
			else if (x == '0' && a[j] != 0) {
				a.push_back(0);
				++j;
			}
		}
		if (a[j] == 0) {
			a.pop_back();
		}
		sort(a.begin(), a.end());
		int res = 0;
		for (j = a.size() - 1; j >= 0; j -= 2) {
			res += a[j];
		}
		cout << res << endl;
	}
	return 0;
}