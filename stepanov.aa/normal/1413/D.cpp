#include <iostream>
#include <vector>
#include <set>
#include <algorithm>


using namespace std;


int n;
vector<pair<char, int>> a;


int main() {
	cin >> n;
	a.resize(2 * n);
	for (int i = 0; i < 2 * n; ++i) {
		char t;
		cin >> t;
		a[i].first = t;
		if (t == '-') {
			cin >> a[i].second;
		}
	}
	set<int> s;
	vector<int> res;
	for (int i = (2 * n) - 1; i >= 0; --i) {
		if (a[i].first == '-') {
			if (s.size() == 0 || *(s.begin()) > a[i].second) {
				s.insert(a[i].second);
			}
			else {
				cout << "NO" << "\n";
				return 0;
			}
		}
		else if (a[i].first == '+') {
			if (s.size() == 0) {
				cout << "NO" << "\n";
				return 0;
			}
			else {
				res.push_back(*(s.begin()));
				s.erase(s.begin());
			}
		}
	}
	cout << "YES" << "\n";
	reverse(res.begin(), res.end());
	for (auto x : res) {
		cout << x << " ";
	}
	cout << "\n";
	return 0;
}