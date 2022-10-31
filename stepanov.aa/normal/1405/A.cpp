#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	int t;
	cin >> t;
	for (int x = 0; x < t; ++x) {
		int n;
		cin >> n;
		vector<int> p(n);
		vector<int> d(2 * n + 1, -1);
		bool stop = false;
		for (int i = 0; i < n; ++i) {
			cin >> p[i];
		}
		reverse(p.begin(), p.end());
		for (int i = 0; i < n; ++i) {
			cout << p[i] << ' ';
		}
		cout << '\n';
	}
	return 0;
}