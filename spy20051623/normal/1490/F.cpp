#include <bits/stdc++.h>
using namespace std;
map<int, int> c, d;

int main() {
//	freopen("in.txt", "r", stdin);
	int t, n, i, in;
	long long sum, minm;
	cin >> t;
	while (t--) {
		cin >> n;
		c.clear();
		d.clear();
		for (i = 0; i < n; ++i) {
			cin >> in;
			++c[in];
		}
		for (auto it : c) {
			++d[it.second];
		}
		minm = 0x3f3f3f3f3f3f3f3f;
		for (auto it1 : d) {
			sum = 0;
			for (auto it2 : d) {
				if (it2.first < it1.first)
					sum += it2.first * it2.second;
				if (it2.first > it1.first)
					sum += (it2.first - it1.first) * it2.second;
			}
			if (sum < minm)
				minm = sum;
		}
		cout << minm << endl;
	}
	return 0;
}