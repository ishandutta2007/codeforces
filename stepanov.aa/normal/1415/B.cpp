#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


const int mxc = 100;
int n, k;
vector<int> a;


int get_res_by_color(int c) {
	int res = 0;
	for (int i = 0; i < n;) {
		if (a[i] == c) {
			++i;
		}
		else {
			++res;
			i += k;
		}
	}
	return res;
}


int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		a.resize(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		int res = 2e9;
		for (int c = 1; c <= mxc; ++c) {
			res = min(res, get_res_by_color(c));
		}
		cout << res << "\n";
	}
	return 0;
}