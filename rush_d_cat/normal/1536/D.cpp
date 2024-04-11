#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <map>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	int t; cin >> t;
	while (t --) {
		int n; cin >> n;
		vector<int> b(n);
		for (int i = 0; i < n; i ++) {
			cin >> b[i];
		}
		bool ok = 1;
		set<int> s; 
		s.insert(b[0]);

		for (int i = 1; i < n; i ++) {
			//printf("i=%d,%d\n", i,b[i]);
			if (b[i] > b[i-1]) {
				auto it = s.upper_bound(b[i-1]);
				if (it != s.end()) {
					if (b[i] > (*it)) {
						ok = false; break;
					}
				}
				s.insert(b[i]);
			}
			if (b[i] < b[i-1]) {
				auto it = s.lower_bound(b[i-1]);
				if (it != s.begin()) {
					-- it;
					if (b[i] < (*it)) {
						ok = false; break;
					}
				}
				s.insert(b[i]);
			}
		}
		cout << (ok?"YES":"NO") << endl;
	}
}