#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n; string s;
int main() {
	cin >> n;
	while(s == "") getline(cin, s);
	vector<int> v;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '-' || s[i] == ' ') v.push_back(i + 1);
	}
	v.push_back(s.size());
	int l = v[0], r = s.size() + 1;
	for (int i = 1; i < v.size(); i++) l = max(l, v[i] - v[i - 1]);
	while (r - l > 1) {
		int m = (l + r) >> 1;
		int p = 0, c = 0;
		while (p < s.size()) p = *(lower_bound(v.begin(), v.end(), p + m) - 1), c++;
		if (c <= n) r = m;
		else l = m;
	}
	cout << l << endl;
	return 0;
}