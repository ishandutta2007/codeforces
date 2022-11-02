#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int s, n;
	cin >> s >> n;
	vector < pair < int, int > > a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i].first >> a[i].second;
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n; ++i) {
		if (s > a[i].first) {
			s += a[i].second;
		} else {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}