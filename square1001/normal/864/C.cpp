#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int a, b, p, c;
int main() {
	cin >> a >> b >> p >> c;
	vector<int> v;
	v.push_back(p);
	for (int i = 0; i < c - 1; i++) {
		if (i % 2 == 0) v.push_back((a - p) * 2);
		else v.push_back(p * 2);
	}
	if (c % 2 == 0) v.push_back(p);
	else v.push_back(a - p);
	if (*max_element(v.begin(), v.end()) > b) cout << -1 << endl;
	else {
		int cur = b, ret = 0;
		for (int i = 0; i < v.size(); i++) {
			cur -= v[i];
			if (i + 1 != v.size() && cur < v[i + 1]) ret++, cur = b;
		}
		cout << ret << endl;
	}
	return 0;
}