#include <vector>
#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int A = ((n - 1) * 2 / 5) / 2 * 2 + 1;
	vector<pair<int, int> > v;
	for (int i = 0; i < A; ++i) {
		v.push_back(make_pair(0, i));
		if (i != 0 && i != A - 1 && i % 2 == 0) {
			v.push_back(make_pair(4, i));
		}
	}
	for (int i = 2; v.size() < n; ++i) {
		if (i % 2 == 0) v.push_back(make_pair(i / 2, 0));
		else v.push_back(make_pair(i / 2, A - 1));
	}
	if (n <= 10) {
		v.clear();
		for (int i = 0; i < n; ++i) {
			v.push_back(make_pair(0, i));
		}
	}
	for (pair<int, int> i : v) {
		cout << i.first << ' ' << i.second << endl;
	}
	return 0;
}